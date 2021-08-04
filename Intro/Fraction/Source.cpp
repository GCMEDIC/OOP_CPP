#include "asdfax.h"
#include "Fraction main.h"
#include "Fraction divide.h"
#include "Fraction multiply.h"
#include "Fraction minus.h"
#include "Fraction plus.h"
#include "Bool operators.h"

//#define constructors_check
//#define arithmetical_operators
//#define compound_assignments
//#define increment_check
//#define comparison_operators
//#define type_conversions

ostream& operator<<(ostream& os, const fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}


void main()
{
	setlocale(LC_ALL, "");
#ifdef constructors_check
	fraction A; //default constructor
	A.print();
	cout << A << endl;
	double b = 5;
	fraction B = 5;
	B.print();
	cout << B << endl;
	fraction C(0, 1, 2); //целое > числитель > знаминатель
	C.print();
	cout << C << endl;
	fraction D(3, 4, 5);
	D.print();
	cout << D << endl;
#endif // constructors_check

#ifdef arithmetical operators
	fraction A(11, 4);
	fraction B(5, 6, 7);
	cout << delimeter << endl;
	fraction C = A * B;
	cout << delimeter << endl;
	cout << C << endl;
	C = A - B;
	cout << delimeter << endl;
	cout << C << endl;
	cout << A / B << endl;
#endif // arithmetical operators

#ifdef compound_assignments
	double a = 2;
	double b = 3;
	a *= 3;
	fraction A(11, 4);
	fraction B(5, 6, 7);
	cout << A << endl;
	cout << B << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << delimeter << endl;
	cout << A << endl;
	cout << A - A << endl;
#endif // compound_assignments

#ifdef increment_check
	for (double i = .3; i < 10; i++)

		cout << i << tab;
	cout << endl;

	for (fraction i(3, 4); i.get_integer() < 10; i++)

		cout << i << tab;
	cout << endl;
#endif // increment_check

#ifdef comparison_operators
	fraction A(1, 2);
	fraction B(5, 10);
	/*if (A == B)
		cout << "Дроби равны, молодец, возможно, может быть." << endl;
	else
		cout << "Дроби разные, давай по новой." << endl;*/
	cout << delimeter << endl;
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << delimeter << endl;
	/*cout << (fraction(1, 2) != fraction(5, 11)) << endl;*/

	cout << A << endl;
	cout << B << endl;
#endif // comparison_operators
	
#ifdef type_conversions
	int a = 2; // no conversion
	double b = 3; // от меньшего к большему
	int c = 5.0; // от большего к меньшему без потери данных
	int d = 5.2; // от большего к меньшему с потерей данных

	char e = 43; // от большего к меньшему без потери данных
	char f = 543; // от большего к меньшему с потерей данных
	// truncation - урезание, усечение
	cout << f << endl;

	fraction A = 5; //from int to fraction - single argument constructor
	cout << A << endl;
#endif type_conversions

	//fraction A = (fraction) 5;
	fraction A(5);
	cout << A << endl;
	A = (fraction)8;
	cout << A << endl;
	fraction B(3, 4, 5);
	double b = (double)B;
	cout << b << endl;
	.3;
	double c = 2.634796437069370946709436738067540674;
	fraction C = 2.5;
	cout << C << endl;

	/*
	Type cast operator syntax
	operator type()
	{
		...
		...
		return ...;
	}
	*/
}