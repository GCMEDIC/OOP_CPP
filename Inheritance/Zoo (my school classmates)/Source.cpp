#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Animal
{
public:
	virtual ~Animal()
	{

	}
	
	virtual void sound()const = 0; // чисто виртуальный метод (pure-virtual function)
	                              // благодаря которому класс является абстрактным
};

class Cat :public Animal
{
	
};

class Tiger :public Cat
{
	~Tiger()
	{

	}

	void sound()const
	{
		cout << "звуки рычания" << endl;
	}
};

class HomeCat :public Cat
{
	~HomeCat()
	{

	}

	void sound()const
	{
		cout << "звуки мурчания" << endl;
	}
};

class Dog :public Animal
{
	~Dog()
	{

	}

	void sound()const
	{
		cout << "Гав" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	//Animal a;
	//Cat tom;
	//Dog sobakin;

	Animal* zoo[] =
	{
		new HomeCat,
		new Dog,
		new Tiger,
		new Dog,
		new HomeCat
	};

	//2. Specialisation:
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}

}