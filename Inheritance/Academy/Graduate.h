#pragma once
#include "stdafx.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"

class Graduate :public Student
{
	string topic;
public:
	const string& get_topic()const
	{
		return topic;
	}
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}

	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double rating, unsigned int semester,
		const string& topic
	) :Student
	(
		last_name, first_name, age, speciality, rating, semester
	)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout << "Тема диплома: " << topic << endl;
	}
};