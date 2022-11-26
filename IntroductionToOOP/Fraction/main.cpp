﻿#include<iostream>
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
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgumentConstructor:" << this << endl;
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

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK

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

	cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
}