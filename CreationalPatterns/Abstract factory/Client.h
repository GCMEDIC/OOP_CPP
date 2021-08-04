#pragma once
#include "Factory.h"
#include "Car.h"

class Client
{
	Factory* factory;
public:
	Client(Factory* factory) :factory(factory)
	{
		// supposed to be empty
	}

	void setFactory(Factory* factory)
	{
		this->factory = factory;
	}

	void info()const
	{
		Engine* engine = factory->createEngine();
		Tank* tank = factory->createTank();
		engine->info();
		tank->info();
		delete engine;
		delete tank;
	}
	Car* assembly(Factory* factory)
	{
		return new Car(factory->createEngine(), factory->createTank());
	}
	
};