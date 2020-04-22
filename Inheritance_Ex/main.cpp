//s395e958
//Mark McCarthy

#include"Person.h"
#include "Vehicle.h"
#include "Truck.h"
#include<iostream>
#include <string>

using namespace std;

int main() {
	//test person class
	//###################################################

	//default ctor
	Person per1;

	//statement tests overloaded output operator and verifies default ctor
	cout << "default ctor Person name(expect 'owner'): " << per1 << endl;
	
	//string parametric ctor
	Person per2("Barry");

	//statement tests class getter function and verifies string parametric ctor
	cout << "String parametric ctor Person name(expect 'Barry'): " 
		<< per2.getName() << endl;
	
	//Obj parametric ctor
	Person per3(per1);

	//statement tests Obj parametric ctor
	cout << "Object parametric ctor Person name(expect 'owner'): " 
		<< per3 << endl;

	//overloaded assignment operator
	per1 = per2;
	
	//statement verifies overloaded assignment operator
	cout << "overloaded assignment operator Person name(expect 'Barry'): " 
		<< per1 << endl;

	//statement tests overloaded input operator
	cout << "please enter owners name: ";
	Person per4;
	cin >> per4;
	cout << "Owners name: " << per4;
	

	//test Vehicle class
	//###################################################################
	
	//default ctor 
	Vehicle v1;

	//statement tests accessor members(getters) and verifies default ctor
	cout << "default ctor Vehicle test(expect:'Honda, 4, Kyle): " 
		<< v1.getMake()<< ", " << v1.getCyl() << ", " << v1.getOwner()
		<< endl << endl;

	//parametric ctor
	Vehicle v2("Acura", 6, Person("Steve"));

	//Statement verifies parametric ctor
	cout << "Parametric ctor Vehicle test(expect:'Acura, 6, Steve'): " 
		<< v2.getMake() << ", "<< v2.getCyl() << ", " << v2.getOwner()
		<< endl << endl;

	//statements tests mutator members(setters)
	v1.setMake("Porsche");
	v1.setCyl(8);
	//setOwner passes input string to class Person ctor
	v1.setOwner("Mike");

	//statement verifies mutator members function
	cout << "Mutator members test(expect:'Porsche, 8, Mike'): " 
		<< v1.getMake() << ", "	<< v1.getCyl() << ", " << v1.getOwner() 
		<< endl << endl;

	//overloaded assignment operator test
	Vehicle v3 = v2;

	//statement verifies overloaded assignment operator 
	cout << "overloaded assignment operator test(expect:'Acura, 6, Steve'): " 
		<< v3.getMake() << ", "<< v3.getCyl() << ", " << v3.getOwner() 
		<< endl<<endl;

	//copy ctor test
	Vehicle v5(v1);

	//statement verifies copy ctor functions
	cout << "copy ctor test(expect:'Porsche, 8, Mike'): " 
		<< v5.getMake() << ", " << v5.getCyl()
		<< ", " << v5.getOwner() << endl << endl;


	//test truck class
	//####################################################

	//default ctor test
	Truck t1;

	//statement tests accessor members(getters) and verifies default ctor
	cout << "default ctor test(expect:'Ford, 8, John, 1.5, 40000'): "
		<< t1.getMake() << ", "<< t1.getCyl() << ", " << t1.getOwner() 
		<< ", " << t1.getLoad() << ", " << t1.getTowing() << endl << endl;

	//parametric ctor test passes first three parameters to 
	//parametric ctor for Vehicle class
	Truck t2("Toyota", 8, "Tom", 0.5, 20000);

	//statement verifies parametric ctor 
	cout << "Parametric ctor test(expect:'Toyota, 8, Tom, 0.5, 20000'): "
		<< t2.getMake() << ", "<< t2.getCyl() << ", " << t2.getOwner() <<
		", " << t2.getLoad() << ", " << t2.getTowing() << endl << endl;

	//parametric ctor test passes a Vehicle obj as parameter
	Vehicle test("Chevy", 8, Person("Eric"));
	Truck t3(test, 2.5, 60000);

	//statement verifies parametric ctor 
	cout<< "parametric ctor test(expect:'Chevy, 8, Eric, 2.5, 60000'): "
		<< t3.getMake() << ", "<< t3.getCyl() << ", " << t3.getOwner() 
		<<", " << t3.getLoad() << ", " << t3.getTowing() << endl << endl;

	//mutator member test
	t2.setMake(t3.getMake());
	t2.setCyl(t3.getCyl());
	t2.setOwner(t3.getOwner());
	t2.setLoad(t3.getLoad());
	t2.setTowing(t3.getTowing());

	//verify mutator member test
	cout<< "Mutator member test(expect:'Chevy, 8, Eric, 2.0, 60000'): "
		<< t2.getMake() << ", " << t2.getCyl() << ", " << t2.getOwner()
		<< ", " << t2.getLoad() << ", " << t2.getTowing() << endl << endl;

	//test overloaded assignment operator 
	Truck t4 = t1;

	//verify overloaded assignment operator
	cout << "overloaded assignment operator test(expect:'Ford, 8, John, 1.5, 40000'): "
		<< t4.getMake() << ", " << t4.getCyl() << ", " << t4.getOwner()
		<< ", " << t4.getLoad() << ", " << t4.getTowing() << endl << endl;
	
	//copy ctor test
	Truck t5(t3);

	//verify copy ctor
	cout << "copy ctor test(expect:'Chevy, 8, Eric, 2.5, 60000'): "
		<< t5.getMake() << ", " << t5.getCyl() << ", " << t5.getOwner()
		<< ", " << t5.getLoad() << ", " << t5.getTowing() << endl << endl;

	return 0;
}