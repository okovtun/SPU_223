#include"String.h"
/////////////////////////////////////////////////////////////////////////////
//////////		CLASS DEFINITION - ОПРЕДЕЛЕНИЕ КЛАССА			/////////////

size_t String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//				Constructors:
String::String(size_t size) :size(size), str(new char[size] {})
{
	cout.width(WIDTH);
	cout << std::left << "DefaultConstructor:" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	strcpy(this->str, str);	//strcpy - string copy
	//strcpy(dst, src);
	//dst - destination string (с трока В которую копируем - строка получатель)
	//src - source string (строка источник - строка, из которой копируем)
	cout.width(WIDTH);
	cout << std::left << "Constructor:" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout.width(WIDTH);
	cout << std::left << "CopyConstructor:" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	other.size = 0;
	other.str = nullptr;
	cout.width(WIDTH);
	cout << std::left << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] str;
	cout.width(WIDTH);
	cout << std::left << "Destructor:" << this << endl;
}

//					Operators:
String& String::operator=(const String& other)
{
	//0) Проверяем, не является ли принятый объект нашим объектом:
	if (this == &other)return *this;
	//1) Удаляем старое значение объекта
	delete[] this->str;
	//2) Deep copy:
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout.width(WIDTH);
	cout << std::left << "CopyAssignment:" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	//Shallow copy:
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout.width(WIDTH);
	cout << std::left << "MoveAssignment:" << this << endl;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}


//					Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////	CLASS DEFINITION END - КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА		/////////////
/////////////////////////////////////////////////////////////////////////////