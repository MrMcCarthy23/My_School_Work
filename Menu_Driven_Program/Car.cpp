#include "Car.h"
#include <iostream>
#include <string>

		//ctors//
//default:
Car::Car()
	:id{ 0 }, make{ "Unknown" }, modle{ "Unknown" }, color{ "Unknown" }{}

//para:
Car::Car(int i, std::string mk, std::string md, std::string co)
	: id{ i }, make{ mk }, modle{ md }, color{ co }{}

//copy:
Car::Car(const Car& that)
	: id{ that.id }, make{ that.make }, modle{ that.modle }, color{ that.color }{}

		//overloaded operators//
//assignment:
Car& Car::operator=(const Car& that) {
	if (this != &that) {
		this->id = that.id;
		this->make = that.make;
		this->modle = that.modle;
		this->color = that.color;
	}
	return *this;
}

//istream input:
std::istream& operator >>(std::istream& ins, Car& c) {
	std::cout << "Please enter the car ID: ";
	ins >> c.id;
	std::cout << "\n";
	std::cout << "Make: ";
	ins >> c.make;
	std::cout << "\n";
	std::cout << "Modle: ";
	ins >> c.modle;
	std::cout << "\n";
	std::cout << "Color: ";
	ins >> c.color;
	std::cout << "\n";
	return ins;
}

//ostream output:
std::ostream& operator <<(std::ostream& outs, Car& c) {
	c.print();
	return outs;
}


		//interface//
//mutators
void Car::setID(int i) { id = i; }
void Car::setMake(std::string mk) { make = mk; }
void Car::setModle(std::string md) { modle = md; }
void Car::setColor(std::string co) { color = co; }

//accessors
int Car::getID() const { return id; }
std::string Car::getMake() const { return make; }
std::string Car::getModle() const { return modle; }
std::string Car::getColor() const { return color; }

//prints out the member var
void Car::print() {
	std::cout << "ID: " << getID() << "\n";
	std::cout << "Make: " << getMake() << "\n";
	std::cout << "Modle: " << getModle() << "\n";
	std::cout << "Color: " << getColor() << "\n";
	std::cout << std::endl;
}