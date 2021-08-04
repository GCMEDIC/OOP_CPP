#pragma once
#include "stdafx.h"
#include "Human.h"

class Student :public Human
{
	string speciality;
	unsigned int rating;
	unsigned int semester;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	double get_rating()const
	{
		return rating;
	}
	unsigned int get_semester()const
	{
		return semester;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_rating(double rating)
	{
		if (rating > 0 && rating <= 5)
			this->rating = rating;
		else
			this->rating = 0;
	}
	void set_semester(unsigned int semester)
	{
		if (semester <= 5)
			this->semester = semester;
		else
			this->semester = 0;
	}

	//         Constructor:
	Student(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double rating, unsigned int semester
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_rating(rating);
		set_semester(semester);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//         Methods:
	void info()const
	{
		cout << "Курс: " << semester << ", Специальность: " << speciality << ", Успеваемость: " << rating << endl;
	}
};