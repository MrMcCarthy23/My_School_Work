#include "ArrList.h"
#include <iostream>


        //ctors//
//default:
ArrList::ArrList() {
	_pa = new Car[10];
	_size = 0;
	_inventory = 10;
}

//para:
ArrList::ArrList(int inventory) {
	if (_inventory > 0) {
		_pa = new Car[inventory];
		_size = 0;
		_inventory = inventory;
	}
	else {
		ArrList();
	}
}

//copy: deep copy
ArrList::ArrList(const ArrList& that) {
	this->_inventory = that._inventory;
	this->_size = that._size;
	this->_pa = new Car[_inventory];
	for (int i = 0; i < _size; ++i) {
		this->_pa[i] = that._pa[i];
	}
}

       //overloaded operators//
//assignment: deep copy
ArrList& ArrList::operator=(const ArrList& that) {
	if (this != &that) {
		Car* temp = this->_pa;
		this->_inventory = that._inventory;
		this->_size = that._size;
		this->_pa = new Car[_inventory];
		for (int i = 0; i < _size; ++i) {
			this->_pa[i] = that._pa[i];
		}
		delete[] temp;
	}
	return *this;
}

//obj wrappers
Car& ArrList::operator[](unsigned int i) { return _pa[i]; }

const Car& ArrList::operator[](unsigned int i)const { return _pa[i]; }

//dtor
ArrList::~ArrList() {
	delete[] _pa;
}


          //interface//

void ArrList::push_back(Car c) {
	add(c);
}

//if the size is greater than zero, pop the 
//last elt from the list and return it
Car ArrList::pop() {
	if (_size <= 0) {
		std::cerr << "Fail to pop(). ArrList empty.\n";
		exit(1);
	}
	Car temp = _pa[_size - 1];
	_size--;
	return temp;
}

//if the input index is in the list
//return the elt at that index
Car ArrList::get(int index) {
	if (index <0 || index > _size) {
		std::cerr << "Fail to get(). Invlaid index.\n";
		exit(1);
	}
	return _pa[index];
}

//if the index is in the list 
//put the obj at that index
void ArrList::set(int index, Car c) {
	if (index <0 || index > _size) {
		std::cerr << "Fail to set(). Invalid index.\n";
		exit(1);
	}
	_pa[index] = c;
}

//if the list is not full, put the obj
//at the end of the list and update size.
//if the list is full, double the size of
//the list and call add function again.
void ArrList::add(Car c) {
	if (!_isFull()) {
		_pa[_size] = c;
		_size++;
	}
	else {
		_doubleCapacity();
		add(c);
	}
}

/*if the index is in the list, and the list
 is not full add the obj, c, to the specified
 index and shift the rest of the objs over 1.
 If the list is full, double the capacity and 
 call the parametric add again.*/
void ArrList::add(int index, Car c) {
	if (index <0 || index > _size) {
		std::cerr << "Fail to add(). Invalid index.\n";
		exit(1);
	}
	if (!_isFull()) {
		for (int i = _size - 1; i >= index; --i) {
			_pa[i + 1] = _pa[i];
		}
		_pa[index] = c;
		_size++;
	}
	else {
		_doubleCapacity();
		add(index, c);
	}
}

//delete by ID function
void ArrList::del(int id) {

	//set index container to safe negative value
	int j = -1;

	//loop through the list to find matching ID and 
	//set j to that index.
	for (int i = 0; i < _size; ++i) {
		if (_pa[i].getID() == id) {
			j = i;
		}
	}

	//if j is not in range of the list output error 
	//and quit.
	if (j <0 || j > _size) {
		std::cerr << "Fail to del(). Invalid index.\n";
		exit(1);
	}

	//if j is in range of the list, overwrite the 
	//elt at j and shift the rest of the tail elts
	// toward the head by 1.
	for (int i = j + 1; i < _size; ++i) {
		_pa[i - 1] = _pa[i];
	}
	_size--;
}

//get size of the list
int ArrList::size() { 
	return _size;
}

//get the capacit of the list
int ArrList::capacity() { 
	return _inventory;
}

//print out all of the elts of the list
// this uses the overloaded version of the 
// ostream operator << for the class Car.
void ArrList::traverse() {
	for (int i = 0; i < _size; ++i) {
		std::cout << _pa[i] << " ";
	}
	std::cout << std::endl;
}

//boolean returns if the list is full
bool ArrList::_isFull() {
	return _size == _inventory;
}

//creates a new list twice the size of the
//original and copies the elts over from the 
//old list. Then recycles the old space.
void ArrList::_doubleCapacity() {
	Car* temp = new Car[_inventory * 2];
	for (int i = 0; i < _size; ++i) {
		temp[i] = _pa[i];
	}
	_inventory *= 2;
	delete[] _pa;
	_pa = temp;
}