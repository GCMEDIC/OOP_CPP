#pragma once
#pragma warning(disable:4326)
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"

class ForwardList;

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//Pointer to next - ��������� �� ��������� �������
	static int count;
public:
	const Element* getpNext()const;
	int getData()const;
	Element(int Data, Element* pNext = nullptr);
	~Element();


	friend class Iterator;
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};