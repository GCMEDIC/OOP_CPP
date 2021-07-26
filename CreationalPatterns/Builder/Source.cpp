#include <iostream>
#include <string>
using namespace std;

class Computer
{
	std::string type;
	std::string cpu;
	size_t ram;
	std::string disk;
	std::string gpu;
public:
	void set_type(const std::string& type)
	{
		this->type = type;
	}
	void set_cpu(const std::string& cpu)
	{
		this->cpu = cpu;
	}

	void set_ram(size_t ram)
	{
		this->ram = ram;
	}
	void set_disk(const std::string& disk)
	{
		this->disk = disk;
	}
	void set_gpu(const std::string& video)
	{
		this->gpu = gpu;
	}

	void info()const
	{
		cout << type << endl;
		cout << cpu << endl;
		cout << ram << endl;
		cout << disk << endl;
		cout << gpu << endl;
	}

};

class ComputerBuilder // Abstract Builder
{
protected:
	Computer* computer;
public:
	ComputerBuilder()
	{
		this->computer = new Computer;
	}
	virtual ~ComputerBuilder()
	{

	}
	Computer* getComputer()
	{
		return computer;
	}
	void CreateNewComputer()
	{
		computer = new Computer;
	}
	virtual void setType() = 0;
	virtual void setCPU() = 0;
	virtual void setRAM() = 0;
	virtual void setDisk() = 0;
	virtual void setGpu() = 0;
};

class OfficeComputerBuilder :public ComputerBuilder
{
public:
	~OfficeComputerBuilder() {}

	void setType()
	{
		computer->set_type("Office pc");
	}
	void setCPU()
	{
		computer->set_cpu("Pentium");
	}
	void setRAM()
	{
		computer->set_ram(4);
	}
	void setDisk()
	{
		computer->set_disk("Samsung SSD 1 tb");
	}
	void setGpu()
	{
		computer->set_gpu("Integrated GPU");
	}
};

class GamingComputerBuilder :public ComputerBuilder
{
public:
	~GamingComputerBuilder() {}

	void setType()
	{
		computer->set_type("Gaming pc");
	}
	void setCPU()
	{
		computer->set_cpu("Amd ryzen 2700 pro");
	}
	void setRAM()
	{
		computer->set_ram(16);
	}
	void setDisk()
	{
		computer->set_disk("Kingstone SSD 240 gb");
	}
	void setGpu()
	{
		computer->set_gpu("Nvidia geforce 1660");
	}
};

class CheapComputerBuilder :public ComputerBuilder
{
public:
	~CheapComputerBuilder() {}

	void setType()
	{
		computer->set_type("Budget pc");
	}
	void setCPU()
	{
		computer->set_cpu("Pentium");
	}
	void setRAM()
	{
		computer->set_ram(4);
	}
	void setDisk()
	{
		computer->set_disk("Toshiba HDD 500 GB");
	}
	void setGpu()
	{
		computer->set_gpu("Integrated GPU");
	}
};
class Assembler
{
	ComputerBuilder* computer;
public:
	void assemblyComputer(ComputerBuilder* computer)
	{
		this->computer = computer;
		this->computer->setType();
		this->computer->setCPU();
		this->computer->setRAM();
		this->computer->setDisk();
		this->computer->setGpu();
	}
};

void main()
{
	setlocale(LC_ALL, "");	
	CheapComputerBuilder cheap_comp;
	OfficeComputerBuilder office;
	GamingComputerBuilder for_dying_light_2;

	Assembler sysadmin;
	sysadmin.assemblyComputer(&cheap_comp);
	cheap_comp.getComputer()->info();

	sysadmin.assemblyComputer(&office);
	office.getComputer()->info();

	sysadmin.assemblyComputer(&for_dying_light_2);
	for_dying_light_2.getComputer()->info();
}