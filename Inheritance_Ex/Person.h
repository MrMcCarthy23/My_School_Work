#pragma once
#include <string>
#include <iostream>


class Person {

public:

	//ctor declarations
	Person();
	Person(std::string theName);
	Person(const Person& theObj);

	//getter declaration
	std::string getName() const;

	//assignment operator declaration
	Person& operator = (const Person& that);

	//IO friend function declarations
	friend std::istream& operator >> (std::istream& instream, Person& personObj);
	friend std::ostream& operator << (std::ostream& outStream, Person& personObj);

private:
	//private member var
	std::string name;
};