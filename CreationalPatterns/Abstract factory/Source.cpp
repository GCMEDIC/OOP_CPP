#include "stdafx.h"
#include "client.h"

void main()
{
	setlocale(LC_ALL, "");
	SportFactory sf;
	TruckFactory tf;
	Client client(&sf);
	/*client.info();
	client.setFactory(&tf);
	client.info();
	Engine* sport_engine = sf.createEngine();
	sport_engine->info();*/
	Car* car = client.assembly(&sf);
	Car* truck = client.assembly(&sf);
	car->info();
	Car* truck = client.assembly(&tf);
	car->info();

}