#include <iostream>
#include <array>
#include <vector>
#include <iterator>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------\n"

//#define stl_array
//#define stl_vector
//#define stl_vector_insert
//#define vector_swap
#define stl_vector_erase

template<typename T> void vector_properties(const vector<T>& vec);
template<typename T> void print_vector(const vector<T>& vec);
template<typename T> void reverse_print_vector(const vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");
#ifdef stl_array
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		//cout << arr[i] << tab;
		cout << arr.at(i) << tab;
	}
	cout << endl;
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *arr.data() << endl;
#endif // stl_array

#ifdef stl_vector
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	vec.push_back(55);
	try
	{

		for (int i = 0; i < vec.size(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	vec.reserve(45);
	vec.shrink_to_fit();
	vector_properties(vec);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	vec.assign({ 1024,2048,3072 });
	print_vector(vec);
	vector_properties(vec);
#endif // stl_vector

#ifdef stl_vector_insert
	int index;
	int count;
	int value;
	do
	{
		cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
		if (index > vec.size()) cout << "ћеньше, иначе бабах\n";
	} while (index > vec.size());
	cout << "¬ведите количество добавл€емых элементов: "; cin >> count;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, count, value);
	for (int i : vec)
	{
		cout << i << tab;
		cout << endl;
	}
	vector_properties(vec);

	vec.insert(vec.begin() + 8, vec.begin() + 3, vec.begin() + 8);
	for (int i : vec)
	{
		cout << i << tab;
		cout << endl;
	}
#endif // stl_vector_insert

	/*vec.insert(vec.begin() + 5, {1024, 2048, 3072, 4096});
	print_vector(vec);
	vector_properties(vec);
	cout << delimiter << endl;
	vector<int> vec2;
	cout << "ѕустой вектор занимает: " << sizeof(vec2) << " Ѕайт" << endl;*/

#ifdef vector_swap
	vector <int>  vec1 = { 3,5,8,13,21 };
	vector <int>  vec2 = { 34,55,89 };
	vec1.swap(vec2);
	print_vector(vec1);
	print_vector(vec2);
	vec1.swap(vec2);
	print_vector(vec1);
	print_vector(vec2);
#endif // vector_swap

#ifdef stl_vector_erase
	vector <int> vec = { 3,5,8,13,21,34,55 };
	print_vector(vec);
	reverse_print_vector(vec);
	//int index;
	int index_start, index_end;
	/*cout << "¬ведите индекс удал€емого элемента: "; cin >> index;
	vector<int>::iterator position = vec.begin() + index;
	vec.erase(vec.begin() + index);*/
	cout << "¬ведите начало удал€емого диапазона: "; cin >> index_start;
	cout << "¬ведите конец удал€емого диапазона: "; cin >> index_end;
	vec.erase(vec.begin() + index_start, vec.begin() + index_end);
	print_vector(vec);
	vector_properties(vec);
#endif // stl_vector_erase

}

template<typename T>void vector_properties(const vector<T>& vec)
{

	cout << "Size: " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Max size: " << vec.max_size() << endl;

}

template<typename T> void print_vector(const vector<T>& vec)
{
	cout << typeid(vec.begin()).name() << endl;
	/*for (int i : vec)
	{
		cout << i << tab;
	}
	cout << endl;*/
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

template<typename T> void reverse_print_vector(const vector<T>& vec)
{
	for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}