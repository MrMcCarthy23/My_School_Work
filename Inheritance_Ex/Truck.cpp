#include "Truck.h"
#include <iostream>
#include <string>

//default ctor calls parametric ctor for type Vehicle
//and type Vehicle calls parametric ctor for type Person
Truck::Truck()
	:Vehicle("Ford", 8, Person("John")), load{ 1.5 }, towing{ 40000 }{}

//parametric ctor calls calls parametric ctor for type vehicle
//and type Vehicle calls parametric ctor for type Person
Truck::Truck(std::string make, int cyl, std::string owner, double load, int towing)
	:Vehicle(make,cyl,Person(owner)),load{load},towing{towing}{}

//parametric ctor by passing type Vehicle 
Truck::Truck(const Vehicle& that, double load, int towing)
	:Vehicle(that.getMake(), that.getCyl(),that.getOwner()), load{load}, towing{towing}{}


//getter definitions
double Truck::getLoad()const  { return this->load; }

int Truck::getTowing()const { return this->towing; }

//setter definitions

void Truck::setLoad(double load) { this->load = load; }

void Truck::setTowing(int towing) { this->towing = towing; }

//assignment operator overload definition
Truck& Truck::operator=(const Truck& that) {
	if (this != &that) {
		this->setMake(that.getMake());
		this->setCyl(that.getCyl());
		this->setOwner(that.getOwner());
		this->setLoad(that.getLoad());
		this->setTowing(that.getTowing());
	}
	return *this;
}

//copy ctor definition
Truck::Truck(const Truck& that)
	: Vehicle::Vehicle(that),load{that.getLoad()},towing{that.getTowing()}{}