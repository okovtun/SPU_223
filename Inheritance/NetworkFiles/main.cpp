#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define IP_MAC_EXCHANGE

void main()
{
	setlocale(LC_ALL, "");

	/*char sz_room_number[FILENAME_MAX] = {};
	cout << "Введите номер аудитории: "; cin >> sz_room_number;
	char sz_source_filename[FILENAME_MAX] = {};
	strcat(sz_source_filename, sz_room_number);
	strcat(sz_source_filename, " RAW.txt");
	char sz_wal_filename[FILENAME_MAX] = {};
	strcat(sz_wal_filename, sz_room_number);
	strcat(sz_wal_filename, " ready.txt");
	char sz_dhcp_filename[FILENAME_MAX] = {};
	strcat(sz_dhcp_filename, sz_room_number);
	strcat(sz_dhcp_filename, ".dhcpd.txt");
	cout << sz_source_filename << endl;
	cout << sz_wal_filename << endl;
	cout << sz_dhcp_filename << endl;*/

	//const int IP_SIZE = 16;
	//const int MAC_SIZE = 18;
	//char sz_ip_buffer[IP_SIZE] = {};	//sz_ - String Zero (NULL Terminated Line)
	//char sz_mac_buffer[MAC_SIZE] = {};

	int room_number;
	cout << "Введите номер аудитории: "; cin >> room_number;
	std::string source_filename = std::to_string(room_number) + " RAW.txt";
	std::string wal_filename = std::to_string(room_number) + " WAL.txt";
	std::string dhcp_filename = std::to_string(room_number) + ".dhcpd.txt";

	cout << source_filename << endl;
	cout << wal_filename << endl;
	cout << dhcp_filename << endl;

	std::string sz_ip_buffer;
	std::string sz_mac_buffer;

#ifdef IP_MAC_EXCHANGE
	std::ofstream fout(wal_filename);
	std::ifstream fin(source_filename);
	if (fin.is_open())
	{
		//Будем читать файл

		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			fout << sz_mac_buffer << "\t";
			fout << sz_ip_buffer << "\n";
		}

		fin.close();

		fout.close();
		std::string sz_command_1 = "start notepad ";
		sz_command_1 += wal_filename;
		//strcat(sz_command_1, sz_wal_filename);
		system(sz_command_1.c_str());
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

#endif // IP_MAC_EXCHANGE

	fout.open(dhcp_filename);
	fin.open(source_filename);
	if (fin.is_open())
	{
		//TODO read file:

		for (int i = 0; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (sz_ip_buffer[0] == NULL && sz_mac_buffer[0] == NULL)continue;
			for (int j = 0; sz_mac_buffer[j]; j++)
				if (sz_mac_buffer[j] == '-')sz_mac_buffer[j] = ':';
			cout << "host " << room_number << "-" << i + 1 << endl;
			cout << "{\n";
			cout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			cout << "\tfixed-address\t\t" << sz_ip_buffer << ";\n";
			cout << "}\n";
			cout << endl;

			fout << "host " << room_number << "-" << i + 1 << endl;
			fout << "{\n";
			fout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			fout << "\tfixed-address\t\t" << sz_ip_buffer << ";\n";
			fout << "}\n";
			fout << endl;
		}

		fin.close();

		fout.close();
		std::string sz_command_2 = "start notepad ";
		sz_command_2 += dhcp_filename;
		std::system(sz_command_2.c_str());
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

}