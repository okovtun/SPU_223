#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout;		//1) Создаем поток
	fout.open("File.txt", std::ios_base::app);	//2) Открываем поток
	fout << "Hello Files\t";	//3) Пишем в поток
	fout << "Привет Мир!\n";
	fout.close();			//4) Закрываем поток, после того, как он уже не нужен

	system("notepad File.txt");
#endif // WRITE_TO_FILE

	std::ifstream fin("13 Generation Intel CPU 743844-002.pdf", std::ios::binary);	//1) Создаем и открываем поток
	//2) Проверяем, открыт ли наш поток:
	if (fin.is_open())
	{
		//3) Выполняем чтение из файла:

		//4) Создаем буфер чтения:
		const int SIZE = 10240;		//размер буфера чтения
		char sz_buffer[SIZE] = {};	//буфер

		//5) ПОКА НЕ КОНЕЦ ФАЙЛА, читаем его содержимое:
		while (!fin.eof())
		{
			//fin >> sz_buffer;	//чтение до пробела
			//для того чтобы прочитать строку с пробелами, нужно использовать fin.getline():
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}

		fin.close();	//6) Закрываем поток, только в том случае, когда он открыт
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	cout << "Reding complete" << endl;
}