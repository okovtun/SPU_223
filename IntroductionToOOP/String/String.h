#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define WIDTH	20
#define delimiter "\n--------------------------------------------\n"

/////////////////////////////////////////////////////////////////////////////
//////////		CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА			/////////////

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	size_t size;	//размер строки в Байтах (size_t - unsigned int)
	char* str;		//адрес строки в динамической памяти
public:
	size_t get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(size_t size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//					Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	//					Methods:
	void print()const;
};

//////////	CLASS DECLARATION END - КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА		/////////////
/////////////////////////////////////////////////////////////////////////////
