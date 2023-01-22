#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		Head = nullptr;	//Если Голова списка указывает на 0 - значит список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList other)
	{
		cout << "LCopyConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//				Adding Elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);	//1) Создаем новый элемент
		New->pNext = Head;					//2) Подключаем новый элемент к началу списка
		Head = New;			//3) Переводим Голову на новое начало списка
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);	//1) Создаем новый элемент
		//2) Нужно дойти до конца списка:
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		//3) Добавляем элемент в список:
		Temp->pNext = New;
	}

	//				Removing elements:
	void pop_front()
	{
		if (Head == nullptr)return;
		Element* Erased = Head;	//1) Запоминаем адрес удаляемого элемента
		Head = Head->pNext;		//2) Исключаем удаляемый элемент из списка
		delete Erased;		//3) Удаляем элемент из памяти
	}
	void pop_back()
	{
		if (Head == nullptr || Head->pNext == nullptr)return pop_front();
		//1) Доходим до предпоследнего элемента списка:
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		//2) Удаляем последний элемент из памяти:
		delete Temp->pNext;
		//3) Зануляем указатель на последний (удаленный) элемент
		Temp->pNext = nullptr;
	}

	//				Methods:
	void print()const
	{
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого 
		//можно получить доступ к элементам структуры данных.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	//list.push_front(123);
	//list.pop_back();
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	//list.push_back(123);
	list.print();
}