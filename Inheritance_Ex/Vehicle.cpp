#include "Vehicle.h"
#include <string>
#include <iostream>

//default ctor definition
Vehicle::Vehicle()
	:make{ "Honda" }, cylinders{ 4 }, owner{ Person("Kyle") }{}

//parametric ctor definition
Vehicle::Vehicle(std::string make, int cyl, const Person& owner)
	: make{ make }, cylinders{ cyl }, owner{ owner }{}

//getter definitions
std::string Vehicle::getMake() const { return this->make; }

int Vehicle::getCyl() const { return this->cylinders; }

//getOwner getter function calls obj owner (type Person) getter function
std::string Vehicle::getOwner() const { return this->owner.getName(); }

//setter definitions
void Vehicle::setMake(std::string make) {
	make = make;
}
void Vehicle::setCyl(int cyl) {
	cylinders = cyl;
}
//setOwner function calls ctor for type person
void Vehicle::setOwner(std::string name) {
	temp = new owner(name);
	delete owner;
	owner = temp;
}

//overloaded assignment operator definition
Vehicle& Vehicle::operator = (const Vehicle& that) {

	if (this != &that) {
		this->make = that.getMake();
		this->cylinders = that.getCyl();
		this->owner = that.getOwner();
	}
	return *this;

}

//copy ctor definition
Vehicle::Vehicle(const Vehicle& that) {
	if(this != &that) {
		this->make = that.getMake();
		this->cylinders = that.getCyl();
		this->owner = that.getOwner();
	}
}
