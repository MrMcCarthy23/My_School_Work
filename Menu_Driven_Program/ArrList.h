#pragma once
#include"Car.h"
#include <string>
#ifndef ARRLIST_H
#define ARRLIST_H

class ArrList
{
public:

	//ctors//
	//default:
	ArrList();
	//para:
	ArrList(int inventory);
	//copy:
	ArrList(const ArrList& that);

	//overloaded operators
	//assignment:
	ArrList& operator = (const ArrList& that);
	//obj wrappers
	Car& operator[](unsigned int i);
	const Car& operator[](unsigned int i)const;

	//dtor
	~ArrList();

	//interface
	void push_back(Car c);
	Car pop();
	Car get(int index);
	void set(int index, Car c);
	void add(Car c);
	void add(int index, Car c);
	void del(int index);
	int size();
	int capacity();
	void traverse();

private:
	Car* _pa;
	int _size;
	int _inventory;

	bool _isFull();
	void _doubleCapacity();
};

#endif //ARRLIST_H