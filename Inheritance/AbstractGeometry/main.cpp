#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

		console_default = 0x07,	//Hex-код цвета, первая цифра - цвет фона, вторая цифра - цвет текста
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
	};
	/*
	---------------------
	enum (Enumeration) - перечисление.
	Перечисление - это набор именованных констант типа 'int'
	---------------------
	*/

	class Shape
	{
	protected:
		static const int MIN_START_X = 10;
		static const int MAX_START_X = 800;
		static const int MIN_START_Y = 10;
		static const int MAX_START_Y = 500;
		static const int MIN_LINE_WIDTH = 5;
		static const int MAX_LINE_WIDTH = 25;

		static const int MIN_LENGTH = 15;
		static const int MAX_LENGTH = 500;
		Color color;
		int start_x;
		int start_y;
		int line_width;
	public:

		Shape(int start_x, int start_y, int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		void set_start_x(int start_x)
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < MIN_START_Y)start_y = MIN_START_Y;
			if (start_y > MAX_START_Y)start_y = MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}

		virtual double get_area() const = 0;
		virtual double get_perimeter() const = 0;
		virtual void draw() const = 0;

		virtual void info()const
		{
			cout << "Площадь: " << get_area() << endl;
			cout << "Периметр:" << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle :public Shape
	{
		double length;
		double width;
	public:
		double get_length()const
		{
			return length;
		}
		double get_width()const
		{
			return width;
		}
		void set_length(double length)
		{
			if (length < MIN_LENGTH)length = MIN_LENGTH;
			if (length > MAX_LENGTH)length = MAX_LENGTH;
			this->length = length;
		}
		void set_width(double width)
		{
			if (width < MIN_LENGTH)width = MIN_LENGTH;
			if (width > MAX_LENGTH)width = MAX_LENGTH;
			this->width = width;
		}

		Rectangle(double length, double width, int start_x, int start_y, int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_length(length);
			set_width(width);
		}

		double get_area()const
		{
			return length * width;
		}
		double get_perimeter()const
		{
			return (length + width) * 2;
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/

			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);	//pen - рисует линию
			HBRUSH hBrush = CreateSolidBrush(color);	//brush - рисует заливку замкнутой фигуры
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + length);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина: " << length << endl;
			cout << "Ширина:" << width << endl;
			Shape::info();
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, int start_x, int start_y, int line_width, Color color)
			:Rectangle(side, side, start_x, start_y, line_width, color) {}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_length() << endl;
			Shape::info();
		}
	};

	class Circle :public Shape
	{
		static const int MIN_RADIUS = 15;
		static const int MAX_RADIUS = 500;
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius < MIN_RADIUS)radius = MIN_RADIUS;
			if (radius > MAX_RADIUS)radius = MAX_RADIUS;
			this->radius = radius;
		}
		Circle(double radius, int start_x, int start_y, int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius);
		}
		~Circle() {}
		double get_area()const
		{
			return M_PI * radius*radius;
		}
		double get_perimeter()const
		{
			return 2 * M_PI*radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, 300, 100, 400, 200);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус: " << radius << endl;
			Shape::info();
		}
	};

	class Triangle :public Shape
	{
	public:
		virtual double get_height()const = 0;
		Triangle(int start_x, int start_y, int line_width, Color color)
			:Shape(start_x, start_y, line_width, color) {}
		~Triangle() {}
		void info()const
		{
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class IsoscalesTriangle :public Triangle
	{
		double base;	//Основание
		double side;	//Длина стороны
	public:
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		void set_base(double base)
		{
			if (base < MIN_LENGTH)base = MIN_LENGTH;
			if (base > MAX_LENGTH)base = MAX_LENGTH;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side < MIN_LENGTH)side = MIN_LENGTH;
			if (side > MAX_LENGTH)side = MAX_LENGTH;
			this->side = side;
		}
		IsoscalesTriangle(double base, double side, int start_x, int start_y, int line_width, Color color)
			:Triangle(start_x, start_y, line_width, color)
		{
			set_base(base);
			set_side(side);
		}
		~IsoscalesTriangle() {}

		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base * get_height() / 2;
		}
		double get_perimeter()const
		{
			return base + side * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			CONST POINT vertex[] = 
			{
				{start_x, start_y+side},
				{start_x+base, start_y+side},
				{start_x+base/2, start_y+side-get_height()},
			};

			::Polygon(hdc, vertex, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Основание треугольника:" << base << endl;
			cout << "Длина стороны:			" << side << endl;
			Triangle::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_red);
	Geometry::Rectangle rect(70, 150, 500, 50, 15, Geometry::Color::console_red);
	/*cout << "Длина прямоугольника: " << rect.get_length() << endl;
	cout << "Ширина прямоугольника: " << rect.get_width() << endl;
	cout << "Площадь прямоугольника: " << rect.get_area() << endl;
	cout << "Периметр прямоугольника: " << rect.get_perimeter() << endl;
	rect.draw();*/
	rect.info();

	Geometry::Square square(180, 750, 50, 5, Geometry::Color::green);
	square.info();

	Geometry::Circle circle(50, 450, 150, 5, Geometry::Color::yellow);
	circle.info();

	Geometry::IsoscalesTriangle isocsales(50, 75, 750, 250, 5, Geometry::Color::green);
	isocsales.info();
}