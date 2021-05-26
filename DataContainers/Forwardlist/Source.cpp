#include"Element.h"
#include"Element.cpp"
#include"iterator.h"
#include"iterator.cpp"
#include"ForwardList.h"
#include"ForwardList.cpp"

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
	cout << sizeof(Element<int>) << endl;
	ForwardList<int> list = { 3,5,8,13,21 };
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

	ForwardList<double> dfl = { 2.5, 2.87, 3.14, 5.9, 8.2 };
	for (double i : dfl) cout << i << tab; cout << endl;

	ForwardList<std::string> stih = { "Легендарный", "Дракон", "Доджимы", "на", "улицах" "гулял"};
	for (std::string i : stih)cout << i << tab;
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