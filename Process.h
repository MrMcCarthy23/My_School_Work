#pragma once
class Process
{
private:
	//class members store data for process
	int id;
	int arrival_time;
	int time_rem;
	int fin_time = -1;
	bool added = 0;

public:
	//default ctor
	Process();
	//Para ctor to init input data
	Process(int i, int at, int tr);

	//overloaded assignment op
	Process& operator = (const Process& that);

	//accessors and mutators

	int getId()const;
	int getAtime()const;
	int getRtime()const;
	int getFtime()const;
	bool getAdd()const;

	void setFtime(int fin);
	void setRtime(int time_left);
	void setAdd(bool state);

	void print();

};

