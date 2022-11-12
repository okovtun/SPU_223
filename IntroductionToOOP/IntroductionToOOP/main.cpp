//IntroductionToOOP
#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//OOD - Object-Oriented Design (Объектно-Ориентированное Проектирование)
//UML - Unified Modelling Language (Унифицированный язык моделирования)
//OOP - Object-Oriented Programming
//type name;
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
				//Создание объекта 'A' структуры 'Point'
				//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA << endl;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << sizeof(Point) << endl;
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
}

/*
--------------------------------------------------------------------
		Обращение к полям объектов:
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
--------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------
1. Encapsulation;
	Модификаторы доступа
		private:	закрытые поля (члены), доступны только внутри класса.
		public:		открытые поля, доступны из любого места программы
		protected:	защищенные поля, доступны только из нашего класса, и его дочерних классов.
	get/set-методы
		get - взять, получить;
		set - задать, установить;
2. Inheritance;
3. Polymorphism;
--------------------------------------------------------------------
*/