#include <iostream>
using namespace std;

#define tab "\t"
//#define INTRO
//#define constructors_check
//#define assignment_check
//#define arithmetical_operators

class point
{
	double x; //объявляем координаты по оси x
	double y; //объявляем координате по оси y
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// methods

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	// constructors
	/*point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	point(double x)
	{
		this->x = x;
		this->y - 0;
		cout << "Single argument constructor: " << this << endl;
		
	}*/
	point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "constructor:\t" << this << endl;
	}
	point(const point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copyconstructor:\t" << this << endl;
	}
	~point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// operators
	point& operator=(const point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copyassignment:\t" << this << endl;
		return *this;
	}
	
	point& operator+=(const point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "operator +=" << this << endl;
		return *this;
	}

	point operator+ (const point& other)
	{
		point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "operator + " << this << endl;
		return result;
	}
	
	point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	point& operator++(int)
	{
		point old = *this;
		this->x++;
		this->y++;
		return old;
	}

};

point operator+(const point& left, const point& right)
{
	point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}

point operator-(const point& left, const point& right)
{
	point result
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	cout << "Global minus" << endl;
	return result;
}

point operator*(const point& left, const point& right)
{
	cout << "Global multiplier" << endl;
	return point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);

}

point operator/(const point& left, const point& right)
{
	cout << "Global divider" << endl;
	return point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}


void function(point* p)
{
	cout << p->get_x() << tab << p->get_y() << endl;
}

void function(point obj)
{
	cout << obj.get_x() << tab << obj.get_y() << endl;
}

ostream& operator<<(ostream& os, const point& obj)
{
	return os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
}

void main ()
{
	setlocale(LC_ALL, "");
#ifdef INTRO
	point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl; //выводим на координаты через табуляцию

	point* pA = &A; //pA - pointer to 'A'
	cout << pA->get_x() << tab << pA->get_y() << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(pA) << endl;
#endif //INTRO

#ifdef constructors_check
	point A;       // default constructor
	A.print();
	point B(2, 3);
	B.print();
	point C = 5;   // single argument constructor (method 1)
	C.print();
	point D(8);    // single argument construcotr (method 2)
	D.print();
	int b(3);      // Якобы для типа 'int' вызывается конструктор с одним параметром
	cout << int() << endl; //Якобы вызывается конструктор по умолчанию для типа 'int' и возвращает значение по умолчанию для типа 'int', так можно получить значение по умолчанию для любого типа
	point E{ 13 }; // single argument constructor (method 3)
	E.print();
	int c{ 5 };
	cout << c << endl;
	cout << int{} << endl; // значение по умолчанию для 'int'
	point F = B;   // copy constructor
	F.print();
	point G;       // default constructor
	G = F;         // copyassignment (operator =)
	G.print();
#endif //constructors_check
		
#ifdef assignment_check
	int a, b, c;
	a = b = c = 0;

	point A, B, C;
	A = B = C = point();
#endif //assignmentc_check

#ifdef arithmetical_operators
	//operators overloading
	int a = 2;
	int b = 3;
	int c = a + b;

	point A(2, 3);
	point B(3, 4);
	point C = A + B;
	C.print();
	(A - B).print();
	(A * B).print();
	(A / B).print();
	A.print();
	B.print();
#endif // arithmetical_operators

	point A(2, 3);
	point B(3, 4);
	A += B; // неявный вызов оператора
	A.print();
	A.operator+=(B); // явный вызов оператора
	A.print();
	operator/(A, B).print(); // явный вызов глобального оператора
	A++;
	A.print();
	cout << A << endl;

}