#pragma once
#include "Person.h"
#include <iostream>
#include <string>

class Vehicle
{private:
	std::string make;
	int cylinders;
	Person owner;
public:

	//default ctor declaration
	Vehicle();
	
	//parametric ctor declaration
	Vehicle(std::string make, int cyl, const Person& owner);

	//getter declarations
	std::string getMake()const;
	int getCyl() const;
	std::string getOwner()const;

	//setter declarations
	void setMake(std::string make);
	void setCyl(int cyl);
	void setOwner(std::string name);

	//assignment operator
	Vehicle& operator = (const Vehicle& that);

	//copy ctor 
	Vehicle(const Vehicle& that);
};