#pragma once
#include "Engine.h"
#include "Tank.h"

class Car
{
protected:
	std::string type;
	Engine* engine;
	Tank* tank;
public:
	//Car(Engine* engine, Tank* tank) :engine(engine), tank(tank) {}
	Car(Engine* engine, Tank* tank):engine(engine), tank(tank)
	{

	}

	~Car()
	{
		delete engine;
		delete tank;
	}
	const std::string& get_type = 0;
	void info()const
	{
		engine->info();
		tank->info();
	}
};