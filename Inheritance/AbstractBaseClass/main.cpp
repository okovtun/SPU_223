#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;	//Чисто виртуальный метод, который и делает класс абстрактным.
	// = 0 показывает, что данный метод НЕ имеет определения
};

class GroundVehicle :public Vehicle
{

};
class AirVehicle :public Vehicle
{
	int height;
public:
	virtual void take_off() = 0;
};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едет на четырех колесах" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;
	Car bmw;
	bmw.move();
}