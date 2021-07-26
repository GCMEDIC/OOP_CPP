#pragma warning(disable:4326)
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"



class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//Pointer to next - ��������� �� ��������� �������
	static int count;
public:
	const Element* getpNext()const
	{
		return pNext;
	}
	int getData()const
	{
		return Data;
	}
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}

	friend class Iterator;
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

int Element::count = 0;	//������������� ����������� ����������

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
#ifdef DEBUG
		cout << "IConstructor\t" << this << endl;
#endif // DEBUG

	}
	~Iterator()
	{
#ifdef DEBUG
		cout << "IDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//                        Operators:
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator operator++ (int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	const int& operator*()const
	{
		return Temp->Data;
	}
	int& operator*()
	{
		return Temp->Data;
	}


	const Element* operator->()const
	{
		return Temp;
	}
	Element* operator->()
	{
		return Temp;
	}
};



class ForwardList
{
	unsigned int size;
	Element* Head;	//��������� �� ��������� ������� ������
public:
	unsigned int get_size()const
	{
		return size;
	}
	const Element* getHead()const
	{
		return Head;
	}

	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;	//nullptr � Head �������� ��� ������ ����.
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const std::initializer_list<int> il):ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		/*for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}*/
		for (int i : il)
		{
			push_back(i);
		}
		cout << "ILConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other):ForwardList()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyConstructor:" << this << endl;
	}
	ForwardList(ForwardList&& other) noexcept
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveConstructor:" << this << endl;
	}
	~ForwardList()
	{
		while (Head) pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//          Operators:
	ForwardList& operator =(const ForwardList& other)
	{
		if (this == &other) return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LcopyAssignment:\t" << this << endl;
		return *this;
	}

	ForwardList& operator=(ForwardList&& other) noexcept
	{
		while (Head)pop_front();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveAssignment:" << this << endl;
		return *this;
	}

	int& operator[](int index)
	{
		if (index >= size) throw std::exception("out of range"); // ������� ����������
		Element* Temp = Head;
		for (int i = 0; i < index; i++)
		{
			Temp = Temp->pNext;
		}
		return Temp->Data;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index > Element::count)return;
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//			Removing elements:
	void pop_front()
	{
		if (Head == nullptr)return;
		Element* erase_element = Head;	//1) ���������� ����� ���������� ��������:
		Head = Head->pNext;		//2) ��������� ������� �� ������:
		delete erase_element;//3) ������� ������� �� ������
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		//1) ������� �� �������������� ��������
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
			Temp = Temp->pNext;
		delete Temp->pNext;//2) ������� ��������� ������� �� ������
		Temp->pNext = nullptr;//3) �������, ��� ��� ����� ������
		size--;
	}

	//			Methods:
	void print()const
	{
		/*
		//��� ���� ����� ������ �� ������ �����:
		//1)��������
		Element* Temp = Head;	//Temp - ��� ��������.
								//�������� - ��� ���������, ��� ������ �������� ����� �������� ������
								//� ��������� ��������� ������.
		//2) ����:
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//������� �� ��������� �������
		}
		*/

		//		for(	Start;			  Stop; Step)....
		//for (Element* Temp = Head; Temp; /*Temp = Temp->pNext*/ Temp++)
		//Element* Temp = nullptr;
		for (Iterator Temp = Head; Temp != nullptr; Temp++)
			cout << *Temp << tab;
		cout << endl;
		cout << "� ������ " << size << " ���������\n";
		cout << "����� ���������� ���������: " << Element::count << endl;
	}
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (const Element* Temp = right.getHead(); Temp; Temp = Temp->getpNext())
		cat.push_back(Temp->getData());
	return cat;
}

#ifdef base_check
//#define base_check
//#define ADDING_ELEMENTS_CHECK
//#define removing_check  
#endif // base_check

//#define OPERATORS_PLUS_CHECK

//#define COPY_METHODS_CHECK

#define HARDCORE

void main()
{
	setlocale(LC_ALL, "Russian");

	ForwardList list = { 3, 5, 8, 13, 21 };
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

}