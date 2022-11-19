//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define WIDTH	22
#define delimiter "\n-------------------------------------\n"

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

	//				Constructors:
	/*Point()
	{
		x = y = double();	//double() - значение по умолчанию для типа double
		cout.width(WIDTH);
		cout << left << "Constructor:" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout.width(WIDTH);
		cout << left << "SingleArgConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout.width(WIDTH);
		cout << left << "Constructor:" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout.width(WIDTH);
		cout << left << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout.width(WIDTH);
		cout << left << "Destructor:" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout.width(WIDTH);
		cout << left << "CopyAssignment:" << this << endl;
		return *this;
	}

	//				Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

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

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B:   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
	cout << delimiter << endl;
	int i = 0;
	for (/*int i = 0*/; i < 10; i++)
	{
		cout << i << "\t";
	}
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
	A.print();

	Point B = 5;//Single-argument constructor
	B.print();

	Point C(2, 3);//Prametrised constructor
	C.print();

	Point D = C;//CopyConstructor
	D.print();

	Point E;
	E = D;		//CopyAssignment
	E.print();
#endif // CONSTRUCTORS_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	C = A + B;
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

/*
--------------------------------------------------------------------
1. Constructor - это метод, который создает объект;
	-с параметрами;
	-без параметров;
	-по умолчанию - это конструктор, кторый может быть вызван без параметров;
	-конструктор копирования (CopyConstructor);
	-конструктор переноса;
2. ~Destructor - это метод, который уничтожает объект по завершении его времени жизни;
3. Assignment operator;
--------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------
			Operators overloading
1. Перегрузить можно только существующие операторы
	+  - перегружается;
	++ - перегружается;
	*  - перегружается;
	** - НЕ перегружается;
2. Не все существующие операторы можно перегрузить.
   Не перегружаются:
	?: - Conditional ternary;
	:: - Оператор разрешения видимости (Scope operator)
	.  - Оператор прямого доступа (Point operator)
	.* - Pointer to member selection
	#
	##
3. Перегруженные операторы сохраняют приоритет;
4. Переопределить поведение операторов над встроенными типами невозможно;

	type operator@(parameters)
	{
		group-of-statements;
	}
--------------------------------------------------------------------
*/