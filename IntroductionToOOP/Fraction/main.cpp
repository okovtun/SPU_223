﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define WIDTH 26

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//					Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;
	}
	explicit Fraction(int integer)	//explicit - явный
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgumentConstructor:" << this << endl;
	}
	Fraction(double decimal)
	{
		integer = decimal;		//Сохраняем целую часть десятичной дроби
		decimal -= integer;		//убираем целую часть из десятичной дроби
		denominator = 1e+9;
		decimal *= denominator;	//Всю дробную часть, которую мы можем сохранить вынимаем в целую часть числа
		numerator = decimal;	//
		reduce();
		cout.width(WIDTH);
		cout << std::left << "DoubleArgumentConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constryctor:" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	//					Operators:
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopyAssignment:" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				Increment/Decrement:
	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//				Type-cast operators:
	explicit operator int()
	{
		return to_proper().integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//					Methods:
	Fraction& to_proper()
	{
		//Преобразует дробь в правильную:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//Преобразует дробь в правильную
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		/*int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction res;
	res.set_numerator(left.get_numerator()*right.get_numerator());
	res.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction res
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	res.to_proper();
	return res;*/
	5;
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}

/////////////////////		Comparison operators		////////////////////
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if(left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return
		left.get_numerator()*right.get_denominator() ==
		right.get_numerator()*left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) cout << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) cout << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);*/

	/*
		2(3/4);
		2 3/4;
		1/2;
		5;
	*/
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);
	//cout << buffer << endl;
	int number[3];
	int n = 0;	//количество введенных значений
	
	//strtok() возвращает адрес строки до разделителя, при этом разделитель заменяется NULL-терминатором
	char delimiters[] = "() /";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = std::atoi(pch);
		//std::atoi(ANSI-string to integer) - преобразует строку в число типа int
	}

	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	obj = Fraction();	//Обнуляем объект
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3: obj(number[0], number[1], number[2]);
	}

	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HOME_WORK_1
#define HOME_WORK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;			//Default constructor
	A.print();

	Fraction B = 5;		//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;		//CopyConstructor
	E.print();

	Fraction F;			//CopyAssignment
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();
	/*A.to_improper();
	A.print();
	A.to_proper();
	A.print();*/

	Fraction B(3, 4, 5);
	B.print();
	/*B.to_improper();
	B.print();
	B.to_proper();
	B.print();*/

	double a = 2;
	double b = 3;
	double c = a * b;

	Fraction C = A * B;
	C.print();
	C = A / B;
	C.print();

	A *= B;
	//A = A * B;
	A.print();
	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
	for (double i = .50738; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
}
#endif // INCREMENT_CHECK

	//cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;

	/*Fraction A(2, 3, 4);
	cout << A << endl;
	cout << typeid(cin).name() << endl;*/

	//(type)value;	//C-like notation
	//type(value);	//Functional notation
	//Warning: conversion from 'type1' to 'type2' possible loss of data

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2;		//No conversion
	double b = a;	//Conversion from less to more
	double c = 2.;	//No conversion
	int d = b;		//From more to less without data loss
	int e = 2.7;	//From more to less with data loss

	cout << typeid(2 + 3U).name() << endl;
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	//1) Из других типов в наш тип;
//2) Из нашего типа в другие типы;

	Fraction A = (Fraction)5;	//From 'int' to 'Fraction'
	cout << A << endl;
	cout << endl;

	Fraction B;		//Default constructor
	B = Fraction(8);
	cout << B << endl;


	//Fraction C = 12;	//explicit-конструктор невозможно вызвать оператором '='
	Fraction C(12);		//explicit-конструктор можно вызвать только так
	Fraction D{ 13 };	//или так
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
			/*
------------------------------------
Type-cast operators:

operator type()const
{
	conversion - code;
}
------------------------------------
*/
	Fraction A(5);
	int a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	double b = (double)B;
	cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HOME_WORK_1
	Fraction A(128, 256, 512);
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
#endif // HOME_WORK_1

#ifdef HOME_WORK_2
	Fraction B = 2.75;
	cout << B << endl;
#endif // HOME_WORK_2

}