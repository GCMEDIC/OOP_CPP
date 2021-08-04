#pragma once
#include "asdfax.h"

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
		this->set_denominator(denominator);
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