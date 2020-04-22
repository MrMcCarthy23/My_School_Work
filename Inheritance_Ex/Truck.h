#pragma once
#include"Vehicle.h"
#include "Person.h"
#include <iostream>
#include <string>

class Truck : public Vehicle
{

public:
	double load;
	int towing;


	//default ctor declaration
	Truck();
	
	//parametric ctor declaration
	Truck(std::string make, int cyl, std::string owner, double load, int towing);

	//parametric ctor by passing a type Vehicle
	Truck(const Vehicle& that, double load, int towing);

	//getter declarations
	double getLoad()const ;
	int getTowing()const ;
	
	//setter declarations
	void setLoad(double load);
	void setTowing(int towing);

	//assignment operator declaration
	Truck& operator = (const Truck& that);

	//copy ctor declaration
	Truck(const Truck& that);


};