#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define constructors_check
//#define arithmetical_operators
//#define compound_assignments
//#define increment_check
//#define comparison_operators
//#define type_conversions
#define tab "\t"


class fraction;
fraction operator*(fraction left, fraction right);
fraction operator/(fraction left, fraction right);

#define debug

class fraction
{
	int integer;     //целая чатсть
	int numerator;   //числитель
	int denominator; //знаминатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	// constructors below
	fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "defaultconstructor: " << this << endl;
#endif // DEBUG

	}
	explicit fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "single argument constructor:" << this << endl;
#endif // DEBUG

	}
	fraction(double decinmal)
	{
		decinmal += 1e-15;
		integer = decinmal;
		decinmal -= integer;
		denominator = 1e+9;
		numerator = decinmal * denominator;
		reduce();
	}
	fraction(int numerator, int denominator)
	{

		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator (denominator);
#ifdef DEBUG
		cout << "constructor:\t\t" << this << endl;
#endif // DEBUG

	}
	fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifdef DEBUG
		cout << "constructor:\t" << this << endl;
#endif // DEBUG

	}
	fraction(const fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "copy constructor:\t" << endl;
#endif // DEBUG

	}
	~fraction()
	{
#ifdef DEBUG
		cout << "destructor:\t" << this << endl;
#endif // DEBUG

	}

	//OPPPPPEEEEERATOOOOOOOOOOOORS

	fraction& operator=(const fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "copy assignment:\t" << this << endl;
#endif // DEBUG

		return *this;
	}
	fraction& operator *=(const fraction& other)
	{
		return *this = *this * other;
	}

	/*fraction operator*(const fraction& other)const
	{
		fraction left = *this;
		fraction right = other;
		left.to_improper();
		right.to_improper();
		return fraction 
		(
			left.numerator * right.numerator,
			left.denominator * right.denominator
		);
	}*/
		
	fraction operator/=(const fraction& other)
	{
		return *this = *this / other;
	}

	// INCREMEEEEEEEEEEEEEENTS/DECREMEEEEEEEEEEEEEEEEEEEEEEENTS
	fraction& operator++()
	{
		integer++;
		return *this;
	}
	fraction operator++(int)
	{
		fraction old = *this;
		integer++;
		return old;
	}
	fraction& operator--()
	{
		integer--;
		return *this;
	}
	fraction operator--(int)
	{
		fraction old = *this;
		integer--;
		return old;
	}

	// TYPE CAST OPERATOOOOOOOOOOOOOOORS
	explicit operator int()const
	{
		return integer;
	}

	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//MEEEEEEEEEEEEEEEEEEEEEEETHOOOOOOOOOOOOOOOOOOOOOOOOOODS
	fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
		/*fraction copy = *this;
		copy.integer += copy.numerator / copy.denominator;
		copy.numerator %= copy.denominator;
		return copy;*/
	}

	fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
		/*fraction copy = *this;
		copy.numerator += copy.integer * copy.denominator;
		copy.integer = 0;
		return *this;*/
	}

	fraction& reduce()
	{
		if (numerator == 0)
		{
			return *this;
		}

		int more, less, rest;
		//1) определяем кто больше, числитель или знаменатель
		if (numerator > denominator)
		{
			more = numerator, less = denominator;
		}
		else
		{
			less = numerator, more = denominator;
		}
		//2) вычисляем наибольший общий делитель (НОД - GCD)
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //Greatest common divisor - наибольший общий делитель
		//3) сокращаем дробь
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	fraction inverted() const
	{
		fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); //функция swap меняется местами две переменные
		return inverted;
	}

	void print()const
	{
		cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
	}
};

fraction operator-(fraction left, fraction right)
{
	left.to_proper();
	right.to_proper();
	fraction result
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper();
	result.reduce();
	return result;
}

fraction operator+(fraction left, fraction right)
{
	left.to_proper();
	right.to_proper();
	fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator
	(
		left.get_numerator() * right.get_denominator() + 
		right.get_numerator()*left.get_denominator()
	);
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;
}

fraction operator*(fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

//COMPARISOOOOOOOOOOOOOOOOOOOOON OPERATOOOOOOOOOOOOOOOOOOOORS

bool operator==(fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
		return left.get_numerator()*right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator !=(const fraction & left, const fraction & right)
{
	return !(left == right);
}


//STREEEEEEEEEEEEEEEEEEEEEEEEEEAM OPERATOOOOOOOOOOOOOOOOOOORS

fraction operator/(fraction left, fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return fraction
	{
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	}.to_proper();*/
	return left * right.inverted();
}
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

#define delimeter "\n---------------------------------------------------------------\n"

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