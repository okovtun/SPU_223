#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout;		//1) ������� �����
	fout.open("File.txt", std::ios_base::app);	//2) ��������� �����
	fout << "Hello Files\t";	//3) ����� � �����
	fout << "������ ���!\n";
	fout.close();			//4) ��������� �����, ����� ����, ��� �� ��� �� �����

	system("notepad File.txt");
#endif // WRITE_TO_FILE

	std::ifstream fin("13 Generation Intel CPU 743844-002.pdf", std::ios::binary);	//1) ������� � ��������� �����
	//2) ���������, ������ �� ��� �����:
	if (fin.is_open())
	{
		//3) ��������� ������ �� �����:

		//4) ������� ����� ������:
		const int SIZE = 10240;		//������ ������ ������
		char sz_buffer[SIZE] = {};	//�����

		//5) ���� �� ����� �����, ������ ��� ����������:
		while (!fin.eof())
		{
			//fin >> sz_buffer;	//������ �� �������
			//��� ���� ����� ��������� ������ � ���������, ����� ������������ fin.getline():
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}

		fin.close();	//6) ��������� �����, ������ � ��� ������, ����� �� ������
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	cout << "Reding complete" << endl;
}