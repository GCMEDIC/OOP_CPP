#include "stringopowah.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////	CLASS DEFINITION  - ОБЪЯВЛЕНИЕ КЛАССА //////////////////////////////////
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
string::string(const string& other) : string(other.str)
{
	//strcpy(this->str, other.str);
	std::cout << "copyconstructor:\t" << this << std::endl;
}
string::string(string&& other) : size(other.size), str(other.str)
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
