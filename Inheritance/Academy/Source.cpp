#include "stdafx.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Graduate.h"


//#define inheritance_basics

void main()
{
#ifdef inheritance_basics 
	setlocale(LC_ALL, "");
	Human vasily("�������", "�������", 18);
	vasily.info();
	Student kravchenko("Lev", "Kravchenko", 32, "��������", 5, 3);
	kravchenko.info();
	Teacher teacher("Kravchenko", "Petrovich", 130, "���������� ��������", 98);
	teacher.info();
	Graduate grad("Reznov", "Nikolai", 57, "��������", 5, 5, "Nervous system details");
	grad.info();
	Human* p_kravchekno = &kravchenko;
	Human* p_teacher = &kravchenko;
	Human* p_grad = &grad;
#endif // inheritance_basics 

	setlocale(LC_ALL, "");

	Human* group[] =
	{
		new Student ("Lev", "Kravchenko", 32, "��������", 5, 3),
		new Student ("���������", "�������", 25, "����������������", 4.5, 2),
		new Teacher ("Kravchenko", "Petrovich", 130, "���������� ��������", 98),
		new Student ("Belikov", "Sergei", 30, "Leutinant", 4.8, 4),
		new Graduate ("Reznov", "Nikolai", 57, "��������", 5, 5, "Nervous system details")
	};
	cout << delimeter;
	cout << sizeof(group) << endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->info();
		cout << delimeter;
		
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human); i++)
	{
		delete group[i];
	}
}