#include <iostream>
using namespace std;



class Weapon
{
public:
	virtual void damage() = 0;//����� ����������� �����
};

class Pistol :Firearms
{
	string model;
public:
	void damage()
	{
		cout << "���..." << endl;
	}

};

class Firearms : public Weapon
{
	double caliber;
	int capacity;
	int distance;
};

void main()
{
	Pistol de;
	de.damage();

}