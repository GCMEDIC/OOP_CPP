#pragma once
#include "Engine.h"
#include "Tank.h"

class Factory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Tank* createTank() = 0;
};

class SportFactory :public Factory
{
public:
	Engine* createEngine()
	{
		return new SportEngine;
	}
	Tank* createTank()
	{
		return new SportTank;
	}
};

class TruckFactory :public Factory
{
public:
	Engine* createEngine()
	{
		return new TruckEngine;
	}
	Tank* createTank()
	{
		return new TruckTank;
	}
};