#include "Element.h"

int Element::count = 0;	//Инициализация статической переменной

const Element* Element::getpNext()const
{
	return pNext;
}
int Element::getData()const
{
	return Data;
}
Element::Element(int Data, Element* pNext) :Data(Data), pNext(pNext)
{
	count++;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
Element::~Element()
{
	count--;
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

}
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr);
	~Iterator();

	//                        Operators:
	Iterator& operator++();
	Iterator operator++ (int);
	bool operator==(const Iterator& other)const;
	bool operator!=(const Iterator& other)const;
	const int& operator*()const;
	int& operator*();
	const Element* operator->()const;
	Element* operator->();
	
};


	Iterator::Iterator(Element* Temp) : Temp(Temp)
	{
#ifdef DEBUG
		cout << "IConstructor\t" << this << endl;
#endif // DEBUG

	}
	Iterator::~Iterator()
	{
#ifdef DEBUG
		cout << "IDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//                        Operators:
	Iterator& Iterator::operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator Iterator::operator++ (int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}

	bool Iterator::operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool Iterator::operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	const int& Iterator::operator*()const
	{
		return Temp->Data;
	}
	int& Iterator::operator*()
	{
		return Temp->Data;
	}


	const Element* Iterator::operator->()const
	{
		return Temp;
	}
	Element* Iterator::operator->()
	{
		return Temp;
	}

class ForwardList
{
	unsigned int size;
	Element* Head;	//Указатель на начальный элемент списка
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
		this->Head = nullptr;	//nullptr в Head означает что список пуст.
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
		if (index >= size) throw std::exception("out of range"); // бросаем исключение
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
		Element* erase_element = Head;	//1) Запоминаем адрес удаляемого элемента:
		Head = Head->pNext;		//2) Исключаем элемент из списка:
		delete erase_element;//3) Удаляем элемент из памяти
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
		//1) Доходим до предпоследнего элемента
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
			Temp = Temp->pNext;
		delete Temp->pNext;//2) Удаляем последний элемент из памяти
		Temp->pNext = nullptr;//3) Говорим, что это конец списка
		size--;
	}

	//			Methods:
	void print()const
	{
		/*
		//Для того чтобы ходить по списку нужны:
		//1)Итератор
		Element* Temp = Head;	//Temp - это итератор.
								//Итератор - это указатель, при помощи которого можно получить доступ
								//к элементам структуры данных.
		//2) Цикл:
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
		*/

		//		for(	Start;			  Stop; Step)....
		//for (Element* Temp = Head; Temp; /*Temp = Temp->pNext*/ Temp++)
		//Element* Temp = nullptr;
		for (Iterator Temp = Head; Temp != nullptr; Temp++)
			cout << *Temp << tab;
		cout << endl;
		cout << "В списке " << size << " элементов\n";
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (const Element* Temp = right.getHead(); Temp; Temp = Temp->getpNext())
		cat.push_back(Temp->getData());
	return cat;
}

//#define base_check
#ifdef base_check
//#define ADDING_ELEMENTS_CHECK
//#define removing_check  
#endif // base_check

//#define OPERATORS_PLUS_CHECK

//#define COPY_METHODS_CHECK

#define HARDCORE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef base_check
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	//list.print();
	cout << "List ready" << endl;
#ifdef removing_check
	list.pop_front();
	list.pop_back();
	list.print();
#endif // removing_check


	/*list.~ForwardList();
	list.print();*/
	int value;
	int index;
#ifdef ADDING_ELEMENTS_CHECK
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	//list.push_back(value);
	list.insert(index, value);
	list.print();

	ForwardList list2;
	cout << "Введите размер списка: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();
	list.print();
#endif // ADDING_ELEMENTS_CHECK

#endif // base_checkase_check

#ifdef HARDCORE
	int arr[] = { 3,5,8,13,21 };
//for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//{
//	cout << arr[i] << tab;
//}
//cout << endl;
	cout << sizeof(Element) << endl;
	ForwardList list = { 3,5,8,13,21 };
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	//list.print();
//	try
//{
//	//list.print();
//	for (size_t i = 0; i < list.get_size(); i++)
//	{
//		list[i] = rand() % 100;
//	}
//	for (size_t i = 0; i < 10; i++)
//	{
//		cout << list[i] << tab;
//	}
//}
//	catch (const std::exception& e)
//	{
//		std::cerr << e.what() << endl; // метод what() возвращает сообщение об ошибке
//	}
#endif // hardcore

#ifdef COPY_METHODS_CHECK
	int n;
	ForwardList list;
	cout << "Введите рзмер списка:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
	cout << delimiter << endl;
	ForwardList list2;
	list2 = list;  //copy construcot
	list2.print();
#endif // copy_methods_check

#ifdef OPERATORS_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);

	ForwardList list2;
	list1.push_back(21);
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.push_back(144);

	
	/////////////////////////////////////////////////
	cout << delimiter << endl;
	ForwardList list3;
	list3 = list1 + list2;
	list3.print();
	cout << delimiter << endl;
	/////////////////////////////////////////////////
#endif // OPERATORS_PLUS_CHECK
}