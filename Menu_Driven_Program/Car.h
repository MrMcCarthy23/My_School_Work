#pragma once

#ifndef CAR_H
#define CAR_H

#include<string>
#include<iostream>
class Car
{
private:

	int id;
	std::string make;	
	std::string modle;
	std::string color;

public:
	//ctors//
	//default:
	Car();
	//para:
	Car(int i, std::string mk, std::string md, std::string co);
	//copy
	Car(const Car& that);

	//overloaded assignment operator
	Car& operator = (const Car& that);

	//friend functions for io
	friend std::istream& operator >>(std::istream& ins, Car& c);
	friend std::ostream& operator <<(std::ostream& outs, Car& c);

			//interface//
	//mutators
	void setID(int i);
	void setMake(std::string mk);
	void setModle(std::string md);
	void setColor(std::string co);

	//accessors
	int getID() const;
	std::string getMake() const;
	std::string getModle()const;
	std::string getColor()const;

	//prints all attributes 
	void print();
};
#endif //CAR_H