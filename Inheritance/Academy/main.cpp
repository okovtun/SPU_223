﻿#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define delimiter "\n---------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS	const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS	last_name, first_name, age

class Human
{
	static const int last_name_width = 10;
	static const int first_name_width = 10;
	static const int age_width = 5;
	static int count;
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//						Constructor
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		count++;
		cout << "HConstructor:\t" << this << "\t" << count << endl;
	}
	virtual ~Human()
	{
		count--;
		cout << "HDestructor:\t" << this << "\t" << count << endl;
	}

	//						Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " лет, ";
	}
	virtual std::ofstream& info(std::ofstream& ofs)const
	{
		ofs.width(last_name_width);
		ofs << std::left;
		ofs << last_name;
		ofs.width(first_name_width);
		ofs << first_name;
		ofs.width(age_width);
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

int Human::count = 0;	//Инициализация статической переменной.

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.info(ofs);
	return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}

#define STUDENT_TAKE_PARAMETERS	const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS	speciality, group, rating, attendance

class Student :public Human
{
	static const int speciality_width = 25;
	static const int group_width = 8;
	static const int rating_width = 8;
	static const int attandance_width = 8;
	std::string speciality;
	std::string group;
	double rating;		//успеваемость
	double attendance;	//посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os) << speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& info(std::ofstream& ofs)const
	{
		Human::info(ofs);
		ofs.width(speciality_width);
		ofs << std::left;
		ofs << speciality;
		ofs.width(group_width);
		ofs << group;
		ofs.width(rating_width);
		ofs << rating;
		ofs.width(attandance_width);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		//ifs >> speciality;
		char sz_speciality[speciality_width]{};
		ifs.read(sz_speciality, speciality_width);
		for (int i = speciality_width - 1; sz_speciality[i] == ' '; i--)
			sz_speciality[i] = 0;
		while (sz_speciality[0] == ' ')
			for (int i = 0; i<speciality_width; i++)sz_speciality[i] = sz_speciality[i + 1];
		speciality = sz_speciality;
		ifs >> group;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	static const int speciality_width = 25;
	static const int experience_width = 5;
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//					Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os) << speciality << " " << experience;
	}
	std::ofstream& info(std::ofstream& ofs)const
	{
		Human::info(ofs);
		ofs.width(speciality_width);
		ofs << speciality;
		ofs.width(experience_width);
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char sz_speciality[speciality_width]{};
		ifs.read(sz_speciality, speciality_width);	//читаем заданное количеставо символов из файла
		for (int i = speciality_width - 1; sz_speciality[i] == ' '; i--)
			sz_speciality[i] = 0;
		while (sz_speciality[0] == ' ')
			for (int i = 0; sz_speciality[i]; i++)sz_speciality[i] = sz_speciality[i + 1];
		speciality = sz_speciality;
		ifs >> experience;
		return ifs;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//					Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//				Methods:
	std::ostream& info(std::ostream& os)const
	{
		return Student::info(os) << subject;
	}
	std::ofstream& info(std::ofstream& ofs)const
	{
		Student::info(ofs) << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};

void print(Human** group, const int n);
void save(Human** group, const int n);
Human* HumanFactory(const std::string& type);
Human** load(const std::string& filename, int& n);

//#define INHERITANCE
//#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
	stud.info();

	Teacher white("White", "Walter", 50, "Chemistry", 25);
	white.info();

	Graduate grad("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg");
	grad.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM
	/*
	--------------------------
	Polymorhism (Poly - много, Morhis - форма)
	Ad-hoc polymorphism - это перегрузка функций, методов, и операторов,
						  реализуется на этапе компиляции, поэтому еще называется
						  Compile-time polymorhism.
	Inclusion polymorphism (Полиморфизм подтипов) - это способность объектов вести себя по разному,
						  в зависимости от того, кем они являеются.
						  Например, любое животное издает звуки, но каждое животное издает звук,
						  в зависимости от того, кем оно является:
						  Собаки лают, Коты мяукают.
	Реализуется при помощи:
	1. указателей на базовый класс.
	   Указатель на базовый класс может хранить адрес дочернего объекта,
	   это позволяет выполнят Generalisation (Обобщение)
	   Upcast - приведение к базовому типу.
	2. виртуальных методов.
	   Виртуальным называется метод, который может быть переопределен в дочернем классе,
	   с учетом его полей.
	   Виртуальные методы позволяют выполнять Specialisation (уточнение) - переход
	   от чего-то более абстрактного, более конктреному, такой переход еще называют Downcast.
	--------------------------
	*/

	/*Human* p_human1 = new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
	Human* p_human2 = new Teacher("White", "Walter", 50, "Chemistry", 25);
	p_human1->info();
	p_human2->info();*/

	//Generalisation:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25),	//UpCast
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 85, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapons ditribution", 20),
	};

	print(group, sizeof(group) / sizeof(Human*));
	save(group, sizeof(group) / sizeof(group[0]));

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

	int n = 0;	//размер группы
	Human** group = load("group.txt", n);
	print(group, n);
}

void print(Human** group, const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}
void save(Human** group, const int n)
{
	std::ofstream fout("group.txt");
	for (int i = 0; i < n; i++)
	{
		//group[i]->info();
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad group.txt");
}
Human* HumanFactory(const std::string& type)
{
	if (type.find("class Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("class Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
	if (type.find("class Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
}
Human** load(const std::string& filename, int& n)
{
	std::ifstream fin(filename);
	Human** group = nullptr;	//пока мы не знаем, сколько элементов будет в мссиве,
								//это нужно будет вычислить
	if (fin.is_open())
	{
		//TODO read file:
		//1) Вычисляем размер массива:
		std::string buffer;
		for (; !fin.eof(); n++)
		{
			std::getline(fin, buffer);
			if (buffer.empty())n--;
			cout << "Текущая позиция курсора: " << fin.tellg() << endl;
		}
		cout << n << endl;

		//2) Выделяем память под массив:
		group = new Human*[n] {};

		//3) Возвращаемся в начало файла, для того чтобы снова егопрочитать:
		fin.clear();
		fin.seekg(0);
		cout << "Текущая позиция курсора: " << fin.tellg() << endl;

		//4) Читаем участников группы из файла:
		for (int i = 0; i < n; i++)
		{
			std::string type;
			std::getline(fin, type, ':');
			cout << type << endl;
			group[i] = HumanFactory(type);
			fin >> *group[i];
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	return group;
}