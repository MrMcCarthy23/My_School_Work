#include "Process.h"
#include <iostream>

//default
Process::Process()
	:id{0},arrival_time{},time_rem{0}{}
//para ctor def
Process::Process(int i, int at, int tr)
	:id{i},arrival_time{at},time_rem{tr}{}

//overloaded assignment operator
Process& Process::operator=(const Process& that) {
	if (this != &that) {
		this->id = that.id;
		this->arrival_time = that.arrival_time;
		this->time_rem = that.time_rem;
		this->fin_time = that.fin_time;
		this->added = that.added;
		return *this;
	}

}

//interface
int Process::getId()const { return id; }
int Process::getAtime()const { return arrival_time; }
int Process::getRtime()const { return time_rem; }
int Process::getFtime()const { return fin_time; }
bool Process::getAdd()const { return added; }

void Process::setFtime(int fin) { fin_time = fin; }
void Process::setRtime(int time_left) { time_rem = time_left; }
void Process::setAdd(bool state) { added = state;
}

//function prints all process data.
void Process::print() {
	std::cout << "          ID: " << getId() << std::endl;
	std::cout << "arrival_time: " << getAtime() << std::endl;
	std::cout << "    time_rem: " << getRtime() << std::endl;
	std::cout << " Finish_time: " << getFtime() << std::endl;
}
