#include <iostream>
#include <fstream>
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
#define COPY_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//cout << "HelloWorld";
	ofstream fout; // ������ �����
	fout.open("File.txt", ios_base::app); // ��������� �����
	fout << "HelloWorld" << endl;
	fout.close(); // ��������� ����� (�����������!!!)
	system("notepad File.txt");
#endif // WRITE_TO_fILE

#ifdef READ_FROM_FILE
	ifstream fin; // ������ �����
	fin.open("File.txt"); // ��������� �����
	const int n = 256;
	char buffer[n] = {};
	if (fin.is_open())
	{
		while (!fin.eof()) // End of file
		{
			fin >> buffer;//
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		cout << "Error: file was thrown out into the endless void" << endl;
	}
	fin.close(); // ��������� �����  
#endif // READ_FROM_FILE

#ifdef COPY_FILE
	ofstream fout;
	ifstream fin;
	fout.open("Copy.txt");
	fin.open("File.txt");

	const int n = 256;
	char buffer[n] = {};

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, n);
			fout << buffer << endl;
		}
	}
	else
	{
		cout << "Error: your file was thrown out into the trash" << endl;
	}

	fin.close();
	fout.close();
	system("notepad Copy.txt");
#endif // COPY_FILE

}