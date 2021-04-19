#include "stringopowah.h"

//#define constructors_check
//#define assignment_check
#define operator_plus_check



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