#include<iostream>
#include<forward_list>
#include<string>
#include<list>
#include<map>
#include<windows.h>
using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n--------------------------------------------------------------------\n"

int menu(std::map<std::string, std::forward_list<std::string>>& base);
void print_base(const std::map<std::string, std::forward_list<std::string>>& base);
void add_crime(std::map<std::string, std::forward_list<std::string>>& base);
void crimes_of(std::string id, const std::map<std::string, std::forward_list<std::string>>& base);


void main()
{
	setlocale(LC_ALL, "");
	/*system("CHCP 1251");
	system("CLS");*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map < std::string, std::forward_list<std::string>> base =
	{
		std::pair<std::string, std::forward_list<std::string>>("M123RU777", {"������ �� �������", "���������� ��������"}),
		std::pair<std::string, std::forward_list<std::string>>("R249KN333", {"�������� � ������������ �����"}),
		std::pair<std::string, std::forward_list<std::string>>("L532FJ555", {"���������� ��������"}),
		std::pair<std::string, std::forward_list<std::string>>("L712FJ444", {"�������� � ��������� ����"}),
	};
	/*print_base(base);
	add_crime(base);
	print_base(base);*/
	/*std::string id;
	cout << "������� ����� ����������: "; cin >> id;
	crimes_of(id, base);*/
	menu(base);
}

int menu(std::map<std::string, std::forward_list<std::string>>& base)
{
	cout << "1) ����� ���� ���� " << endl;
	cout << "2) ����� ���������� �� ������ " << endl;
	cout << "3) ����� �� ��������� ������� " << endl;
	cout << "4) ���������� ��������� " << endl;
	cout << "5) ����� " << endl;
	int choice;
	cin >> choice;
	std::string id;
	switch (choice)
	{
	case 1: print_base(base); break;
	case 2: 
	{
		cout << "������� ����� ������: "; cin >> id;
		crimes_of(id, base);
	}

	case 4: add_crime(base); break;
	case 5: return choice;
	default: cout << "������������ ��������" << endl;
	}
	menu(base);
	return choice;
	
}

void print_base(const std::map<std::string, std::forward_list<std::string>>& base)
{
	for (std::map<std::string, std::forward_list<std::string>>::const_iterator it = base.begin(); it != base.end(); it++)
	{
		cout << it->first << ": ";
		for (std::forward_list<std::string>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			cout << *l_it << ", ";
		}
		cout << "\b \b";
		cout << "\b \b";
		cout << ";";
		cout << delimeter;
	}
}

void add_crime(std::map<std::string, std::forward_list<std::string>>& base)
{
	std::string id;
	std::string crime;
	cout << "������� ����� ����������: "; cin >> id;
	cout << "������� ���������: "; 
	cin.ignore();
	getline(cin, crime);
	base[id].push_front(crime);
}

void crimes_of(std::string id, const std::map<std::string, std::forward_list<std::string>>& base)
{ 
	std::map<std::string, std::forward_list<std::string>>::const_iterator criminal = base.find(id);
	if (criminal != base.end())
	{
		cout << "������ ���������: " << id << ":\t";
		for (std::forward_list<std::string>::const_iterator it = criminal->second.begin(); it != criminal->second.end(); it++)
		{
			cout << *it << endl;
		}
	}
}