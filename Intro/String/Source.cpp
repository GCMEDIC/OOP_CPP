#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define delimiter "\n-------------------------------------------------------------------------------\n"
//#define operator_plus_check

class string;
string operator+(const string& left, const string& right);

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА ///////////////////////////////////

class string
{
	char* str; // указатель на строку в динамической памяти
	int size; // размер строки в байтах
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;

	// CONSTRUCTORS

	explicit string(int size = 80);

	string(const char* str);

	string(const string& other);

	string(string&& other);

	~string();

	// OPERATORS
	string& operator=(const string& other);

	string& operator=(string&& other);

	string& operator+=(const string& other);

	const char& operator[](int index) const;

	char& operator[](int index);


	// METHODS
	void print()const;
};

///////////////////////////	CLASS DECLARATION END - КОНЕЦ ОБЪЯВЛЕНИЕ КЛАССА ///////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////	CLASS DEFINITION END - ОБЪЯВЛЕНИЕ КЛАССА //////////////////////////////////
const char* string::get_str()const
{
	return str;
}
char* string::get_str()
{
	return str;
}
int string::get_size()const
{
	return size;
}

//			constructors:
string::string(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	std::cout << (size == 80 ? "default" : "size") << "constructor:\t" << this << std::endl;
}
string::string(const char* str) :string(strlen(str) + 1)
{
	strcpy(this->str, str);
	std::cout << "constructor:\t\t" << this << std::endl;
}
string::string(const string& other) :string(other.str)
{
	//strcpy(this->str, other.str);
	std::cout << "copyconstructor:\t" << this << std::endl;
}
string::string(string&& other) :size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.str = nullptr;
	std::cout << "moveconstructor:\t" << this << std::endl;
}
string::~string()
{
	delete[] this->str;
	std::cout << "destructor:\t\t" << this << std::endl;
}

//			Operators:
string& string::operator=(const string& other)
{
	//0) Проверить не является ли другой объект нашим объектом
	if (this == &other)return *this;
	//1) Сначала удаляем старое значение объекта
	delete[] this->str;
	//2)И только потом присваиваем ему новое значение
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	std::cout << "CopyAssignment:\t\t" << this << std::endl;
	return *this;
}
string& string::operator=(string&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	std::cout << "MoveAssignment:\t\t" << this << std::endl;
	return *this;
}

string& string::operator+=(const string& other)
{
	return *this = *this + other;
}

const char& string::operator[](int index)const
{
	return this->str[index];
}
char& string::operator[](int index)
{
	return this->str[index];
}

//			Methods:
void string::print()const
{
	std::cout << "Size:\t" << size << std::endl;
	std::cout << "Str:\t" << str << std::endl;
	//for (int i = 0; i < size; i++)cout << (int)str[i]; cout << endl;
}

string operator+(const string& left, const string& right)
{
	string result(left.get_size() + right.get_size() - 1);
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

///////////////////////////	CLASS DEFINITION END - ОБЪЯВЛЕНИЕ КЛАССА /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////


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

#ifdef operator_plus_check
	string str1 = "hello";
	string str2 = "world";
	std::cout << delimiter << std::endl;
	string str3 = str1 + str2; //операвтор + будет выполнять конкатенацию (слияние) строк
	std::cout << delimiter << std::endl;
	std::cout << str3 << std::endl;
	string str4 = str3;
	std::cout << str4 << std::endl;
	/*std::cout << delimiter << std::endl;
	str1 += str2;
	std::cout << str1 << std::endl;
	std::cout << delimiter << std::endl;*/
#endif // operator_plus_check

	//string str1; // default constructor
	//string str2(); // объявляестя функция str2, которая ничего не принимает и возвращает значение типа string
	//string str3{}; // default constructor
	//string str4{ 5 }; // size constructor
	//string str5{ 8 };
	//string str6{ "hello" };
	//string str7{ "hello" };
	//std::cout << str7 << std::endl;
	////string str8 = 16; //неявное преобразование int в string
	

}