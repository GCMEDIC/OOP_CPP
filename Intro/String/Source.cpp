#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define delimiter "\n-------------------------------------------------------------------------------\n"

class string;
string operator+(const string& left, const string& right);

class string
{
	char* str; // указатель на строку в динамической памяти
	int size; // размер строки в байтах
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}

	// CONSTRUCTORS

	string(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << (size == 80 ? "default" : "size") << "constructor\t" << this << std::endl;
	}

	string(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy(this->str, str);
		std::cout << "constructor:\t\t" << this << std::endl;
	}

	string(const string& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		std::cout << "copyconstructor:\t" << this << std::endl;
	}

	string(string&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << "Moveconstructor:\t" << this << std::endl;
	}

	~string()
	{
		delete[] this->str;
		std::cout << "destructor:\t\t" << this << std::endl;
	}

	// OPERATORS
	string& operator=(const string& other)
	{
		//0) проверить не является ли другой объект нашим объектом
		if (this == &other)return *this;
		//1) сначала удаляем старое значение объекта
		delete[] this->str;
		//2) и только потом присваиваем ему новое значение
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		std::cout << "copyassignment:\t\t" << this << std::endl;
		return *this;
	}

	string& operator=(string&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << "Moveassignment:\t" << std::endl;
		return *this;
	}

	string& operator+=(const string& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int index) const
	{
		return this->str[index];
	}

	char& operator[](int index)
	{
		return this->str[index];
	}


	// METHODS
	void print()const
	{
		std::cout << "size:\t" << size << std::endl;
		std::cout << "str:\t" << str << std::endl;
		
	}
};

string operator+(const string& left, const string& right)
{
	string result = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];

		for (int i = 0; i < right.get_size(); i++)
			//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
			result[i + left.get_size() - 1] = right[i];

	return result;
	
}


std::ostream& operator<<(std::ostream& os, const string& obj)
{
	return os << obj.get_str();
}

//#define constructors_check
//#define assignment_check

void main()
{
	setlocale(LC_ALL, "");

#ifdef constructors_check
	string str;
	str.print();

	string str2 = "hello";
	str2.print();
	std::cout << str2 << std::endl;

	string str3 = str2; // copyconstructor
	std::cout << "str3:\t" << str3 << std::endl;

	string str4;
	str4 = str3;
	std::cout << "str4:\t" << str4 << std::endl;

	int a = 2;
	int b = 3;
	a = b;
	std::cout << a << std::endl;
#endif // constructors_check

#ifdef assignment_check
	string str1 = "hello";
	string str2;
	str1 = str1;
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
#endif // assignment_check

	string str1 = "hello";
	string str2 = "world";
	std::cout << delimiter << std::endl;
	string str3 = str1 + str2; //операвтор + будет выполнять конкатенацию (слияние) строк
	std::cout << delimiter << std::endl;
	std::cout << str3 << std::endl;
	/*std::cout << delimiter << std::endl;
	str1 += str2;
	std::cout << str1 << std::endl;
	std::cout << delimiter << std::endl;*/

}