#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define delimiter "\n-------------------------------------------------------------------------------\n"


class string;

string operator+(const string& left, const string& right);
std::ostream& operator<<(std::ostream& os, const string& obj);

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// CLASS DECLARATION - ÎÁÚßÂËÅÍÈÅ ÊËÀÑÑÀ ///////////////////////////////////

class string
{
	char* str; // óêàçàòåëü íà ñòðîêó â äèíàìè÷åñêîé ïàìÿòè
	int size; // ðàçìåð ñòðîêè â áàéòàõ
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;

	// CONSTRUCTORS

	explicit string(int size = 80);

	string(const char* str);

	string(const string& other);

	string(string&& other);

	~string();

	// OPERATORS
	string& operator=(const string& other);

	string& operator=(string&& other);

	string& operator+=(const string& other);

	const char& operator[](int index) const;

	char& operator[](int index);


	// METHODS
	void print()const;


};

///////////////////////////	CLASS DECLARATION END - ÊÎÍÅÖ ÎÁÚßÂËÅÍÈÅ ÊËÀÑÑÀ ///////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////