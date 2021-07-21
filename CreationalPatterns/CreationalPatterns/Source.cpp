#include<iostream>
using namespace std;

class Singletone
{
	std::string last_name;
	std::string first_name;
	static Singletone* instance; // Адрес объекта в динамической памяти
	Singletone(/*const std::string& last_name, const std::string& first_name*/)// :last_name(last_name), first_name(first_name)
	{
		last_name="Singletone";
		first_name="Pattern";
		cout << "Constructor:\t" << this << endl;
	}
	~Singletone()
	{
		delete instance;
		instance = nullptr;
		cout << "Destructor:\t" << this << endl;
	}
public:

	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	static Singletone* getinstance()
	{
		if (instance == nullptr)instance = new Singletone();
		return instance;
	}
	void info()const
	{
		cout << this << ":" << last_name << " " << first_name << endl;
	}
};

Singletone* Singletone::instance = nullptr;

void main()
{
	setlocale(LC_ALL, "");
	cout << "This is a singletone pattern:" << endl;
	Singletone::getinstance()->info();
	Singletone::getinstance()->set_first_name("Daigo");
	Singletone::getinstance()->set_last_name("Dojima");
	Singletone::getinstance()->info();
}