#include <iostream>
#include <map>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

#define MAP

void main()
{
	setlocale(LC_ALL, "");
#ifdef MAP
	/*std::multimap<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(4, "Thursday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(6, "Saturday")
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << tab << it->second << endl;
	}*/

	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("finite", {"������������", "������� ������"}),
		std::pair<std::string, std::list<std::string>>("walk", {"������", "��������"}),
		std::pair<std::string, std::list<std::string>>("Run", {"������", "����������� �����������"}),
		std::pair<std::string, std::list<std::string>>("armor", {"�����", "������"}),
		std::pair<std::string, std::list<std::string>>("incident", {"������", "�����������"})
	};
	std::cout << dictionary["finite"].front() << std::endl;
	dictionary["space"].assign({ "������������", "������", "������" });

	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		std::cout << it->first << ":\t";
		std::cout.width(20);
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			std::cout << *jt << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << dictionary.find("finite")->first << tab;
	for (std::string i : dictionary.find("finite")->second) std::cout << i << tab; std::cout << std::endl;

#endif //MAP
}