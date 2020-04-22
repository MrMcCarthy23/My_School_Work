#include"Person.h"
#include <iostream>

//default ctor
Person::Person()
	:name{ "owner" } {}

//input string initd ctor
Person::Person(std::string theName)
	:name{theName}{}

//obj initd ctor
Person::Person(const Person& theObj)
	:name{theObj.name}{}

//name getter member function
std::string Person::getName() const { return name; }

//obj-obj assignment operator overload
Person& Person::operator = (const Person& rtSide){
	this->name= rtSide.getName();
	return *this;
}
 
//input operator overload
std::istream& operator >> (std::istream& instream, Person& personObj) {
	instream >> personObj.name;
	return instream;
}

//output operator overload
std::ostream& operator << (std::ostream& outstream, Person& personObj) {
	outstream << personObj.name << std::endl;
	return outstream;
}