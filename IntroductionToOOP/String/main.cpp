#include"String.h"
using namespace std;

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK
//#define WAYS_TO_CALL_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1(10);		//Default constructor
	str1.print();

	String str2 = "Hello";
	str2 = str2;
	str2.print();

	String str3 = str2;		//Copy constructor
	str3.print();

	String str4;
	str4 = str3;			//CopyAssignment
	str4.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;

	cout << delimiter << endl;
	str1 += str2;
	cout << str1 << endl;
	cout << delimiter << endl;

	//cout << delimiter << endl;
	//String str3;
	//str3 = str1 + str2;
	//cout << delimiter << endl;
	//cout << str3 << endl;
	//Move semantic
	//MoveConstructor
	//MoveAssignment
	//Shallow copy  
#endif // OPERATOR_PLUS_CHECK

#ifdef WAYS_TO_CALL_CONSTRUCTORS
	String str1;			//Default constructor
	str1.print();

	String str2 = "Hello";	//Single-argument constructor
	str2.print();

	String str3 = str2;		//Copy constructor
	str3.print();

	String str4();	//Здесь НЕ вызывается Default constructor, 
					//здесь объявляется функция str4, которая ничего не принимает,
					//и возвращает значение типа String
	//str4.print();	//str4 - это функция, а не объект
	//Явно вызвать Default constructor можно так:
	String str5{};	//Явный вызов конструктора по умолчанию
	str5.print();

	String str6{ 8 };
	str6.print();

	String str7{ "Hello constructors" };
	str7.print();
#endif // WAYS_TO_CALL_CONSTRUCTORS

}