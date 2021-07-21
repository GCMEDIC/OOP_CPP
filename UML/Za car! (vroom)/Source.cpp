#include <iostream>
#include <conio.h>
#include <thread>
using namespace std;

#define Escape 27
#define Enter 13

const unsigned int DEFAULT_TANK_CAPACITY = 60;
const unsigned int MIN_FUEL_LEVEL = 5;
const unsigned int DEFAULT_ENGINE_FUEL_USAGE = 8;

class Tank
{
	const unsigned int capacity;
	double level_of_fuel;
	unsigned int min_level;

public:
	unsigned int get_capacity()const
	{
		return capacity;
	}
	double get_level_of_fuel()const
	{
		return level_of_fuel;
	}
	unsigned int get_min_level()const
	{
		return min_level;
	}

	void set_level_of_fuel(double fuel)
	{
		if (fuel < 0) return;
		if (this->level_of_fuel + fuel < capacity)
		{
			level_of_fuel += fuel;
		}
		else
		{
			level_of_fuel = capacity;
		}
	}
	explicit Tank(int capacity):capacity(capacity = capacity >= 40 && capacity <= 120 ? capacity : DEFAULT_TANK_CAPACITY)
	{
		//this->capacity = capacity >= 40 && capacity <= 120 ? capacity : DEFAULT_TANK_CAPACITY;
		level_of_fuel = 0;
		min_level = MIN_FUEL_LEVEL;
	}
	void info()const
	{
		cout << "capacity:\t" << capacity << endl;
		cout << "fuel:\t" << level_of_fuel << endl;
		cout << "minimal fuel:\t" << min_level << endl;
	}

	~Tank()
	{
		cout << "Tank is over:\t" << this << endl;
	}
	double give_fuel(double amount)
	{
		level_of_fuel -= amount;
		if (level_of_fuel < 0) level_of_fuel = 0;
		return level_of_fuel;
	}
};

class Engine
{
	// Engine properties 
	unsigned int capacity;
	unsigned int power;
	double fuel_usage; // per 100 km
	double fuel_usage_persecond; // self explanatory

	// Engine state:
	bool started;

public:
	double get_fuel_usage()const
	{
		return fuel_usage;
	}
	double get_fuel_usage_per_second()const
	{
		return fuel_usage_persecond;
	}
	Engine(double fuel_usage)
	{
		this->fuel_usage = fuel_usage >= 4 && fuel_usage <= 25 ? fuel_usage : DEFAULT_ENGINE_FUEL_USAGE;
		this->fuel_usage_persecond = fuel_usage * 5e-5; //fuel_usage * 5 * 10 ^ -4
		started = false;
		cout << "EngineReady:\t" << this << endl;
	}

	~Engine()
	{
		cout << "EngineOver:\t" << this << endl;
	}

	bool is_started()const
	{
		return started;
	}
	void start()
	{
		started = true;
	}
	void stop()
	{
		started = false;
	}

	void info()const
	{
		cout << "fuel usage:\t" << fuel_usage << endl;
		cout << "fuel usage per second:\t" << fuel_usage_persecond << endl;
	}
	
};

class Car
{
	Engine engine;
	Tank tank;
	unsigned int max_speed;
	unsigned int speed;
	bool driver_inside;
	bool gas_pedal;
	unsigned int acceleration;

	struct Control
	{
		std::thread main_thread;
		std::thread panel_thread;
		std::thread engine_idle_thread;
		std::thread free_wheeling_thread;
	}control;

public:
	/*Car(const Engine engine, const Tank tank) :engine(engine), tank(tank)
	{
		cout << "Car is ready:\t";
	}*/
	Car(double fuel_usage, unsigned int capacity, unsigned int MAX_SPEED) :engine(capacity), tank(capacity), max_speed(max_speed >= 90 && max_speed <= 400 ? max_speed : 250) , speed(0)
	{
	    driver_inside = false;
		gas_pedal = false;
		acceleration = 5;
		control.main_thread = std::thread(&Car::control_car, this); // Запускаем метод control_car в потоке main_thread 
		cout << "Car is ready:\t" << this << endl;
	}
	~Car()
	{
		//if (control.engine_idle_thread.joinable())control.engine_idle_thread.join();
		if(control.main_thread.joinable()) control.main_thread.join();
		cout << "Car is over:\t" << this << endl;
	}

	void get_in()
	{
		driver_inside = true;
		control.panel_thread = std::thread(&Car::panel, this);
	}
	void get_out()
	{
		driver_inside = false;
		if (control.panel_thread.joinable())control.panel_thread.join();
		system("CLS");
		cout << "You just exited the car" << endl;
	}

	bool is_driver_inside()const
	{
		return driver_inside;
	}

	void fill(unsigned int fuel)
	{
		tank.set_level_of_fuel(fuel);
	}

	void start()
	{
		if (driver_inside && tank.get_level_of_fuel() > 0)
		{
			engine.start();
			control.engine_idle_thread = std::thread(&Car::engine_idle, this);
		}
	}
	void stop()
	{
		engine.stop();
		if (control.engine_idle_thread.joinable())
			control.engine_idle_thread.join();
	}
	void engine_idle()
	{
		using namespace std::literals::chrono_literals;
		while (engine.is_started() && tank.give_fuel(engine.get_fuel_usage_per_second()))
			std::this_thread::sleep_for(1s);
		engine.stop();
	}
	void panel()const
	{
		using namespace std::literals::chrono_literals;
		while (driver_inside)
		{
			system("CLS");
			cout << "Engine is: " << (engine.is_started() ? "started" : "stopped") << endl;
			cout << "Fuel level:\t" << tank.get_level_of_fuel() << "\t";
			if (tank.get_level_of_fuel() < tank.get_min_level()) cout << system("color 04") << "Low Fuel" << system ("color 00") << std::endl; // попытался окрасить текст, это сделать смог, но сколько я не гуглил я не смог найти как цвета сделать нормальными, и говорят систему лучше вообще не использовтаь
			cout << "speed:" << speed << "\t\n";
			cout << "Max speed:" << max_speed;
			std::this_thread::sleep_for(1s);
		}
	}

	void control_car()
	{
		cout << "You are inside" << endl;
		cout << "Press Enter to get in!" << endl;
		cout << "Press F to fill the car!" << endl;

		using namespace std::literals::chrono_literals;

		char key;
		do
		{
			key = _getch();
			switch (key)
			{
			case 'F':
			case 'f':
				unsigned int fuel;
				cout << "\nВведите объём топлива: "; cin >> fuel; cout << endl;
				fill(fuel);
				break;
			case 'I':
			case 'i':
				if (driver_inside)
				{
					if (!engine.is_started())start();
					else stop();
				}
				break;
			case 'W':
			case 'w':
				if (driver_inside && engine.is_started())
				{
					speed += 5;
				}
				break;
			case 'S':
			case 's':
				if (driver_inside && engine.is_started() && speed > 0)
				{
					speed -= 5;
					if (speed = 0)
					{
						break;
					}
				}
				break;
			case Enter:
				if (is_driver_inside())get_out();
				else get_in(); break;
			case Escape:
				stop();
				get_out();
				cout << "You exited from your car" << endl; break; //машина дальше 10 не разгоняется и не сбрасывается скорость
			}
			
			std::this_thread::sleep_for(0.5s);
			if (speed > 0 && !control.free_wheeling_thread.joinable())control.free_wheeling_thread = std::thread(&Car::free_wheeling, this);
			else if (control.free_wheeling_thread.joinable())control.free_wheeling_thread.join();
		} while (key != Escape);

	}

	void accelerate()
	{
		speed += acceleration;
	}
	void free_wheeling()
	{
		using namespace std::literals::chrono_literals;
		while (speed)
		{
			speed--;
			std::this_thread::sleep_for(1s);
		}
	}

	void info()const
	{
		cout << "Engine\n"; engine.info();
		cout << "Tank\n";  tank.info();
		cout << "Engine is: " << (engine.is_started() ? "started" : "stopped") << endl;
		cout << "Speed " << speed << " KM/h\n";
		cout << "Max Speed " << max_speed << " KM/h\n";
	}
};


//#define TANK_CHECK
//#define ENGINE_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef TANK_CHECK
	Tank tank(35);
	tank.info();
	cout << "\n---------------------------\n";
	tank.set_level_of_fuel(30);
	tank.info();
	cout << "\n---------------------------\n";
	tank.set_level_of_fuel(40);
	tank.info();
#endif // TANK_CHECK

#ifdef ENGINE_CHECK
	Engine engine(10);
	engine.info();
#endif // ENGINE_CHECK

	Car car(10, 50, 250);
	
	
}