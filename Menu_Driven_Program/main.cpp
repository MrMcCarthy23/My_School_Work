//Mark McCarthy

/*This program implements a management structure
for a car rental company. The program will implement 
classes ArrList and Car. The instructions for the program
are as follows:
- make up 10 cars and save them into a file: cars.data
- load these cars' info from the file, initialize 10 Car objects, place them into the Arraylist
- if new cars are added by user, they should be appended to the cars.data file when exiting the program
- design a menu based user interface that allows following operations:
-- search by id
-- search by make
-- search by model
-- search by color
-- add a new car (new car id cannot be same as existing ones)
-- delete an existing car by id
-- list all cars
-- exit the program
*/

#include"ArrList.h"
#include<iostream>
#include<fstream>
#include<sstream>


using namespace std;

//prints instructions out for user
void instructions();

//menu() returns the choice of action user
//wishes to utilize to the main driver
int menu();

//function to search ArrList for elt 
//based on ID number
void searchID(int id,ArrList& cars);

//function to search ArrList for elt 
//based on Make
void searchMake(string make, ArrList& cars);

//function to search ArrList for elt 
//based on Modle
void searchModle(string modle, ArrList& cars);

//function to search ArrList for elt 
//based on color
void searchColor(string color, ArrList& cars);


int main() {
	
	//print instructions
	instructions();

	//wait for user to start
	do
	{
		cout << '\n' << "Press enter to continue...";
	} while (cin.get() != '\n');

	
	//init ArrList class to store car objs
	ArrList cars;
	
	//while loop exit cond.
	int exit_condition = 1;

	//use while loop to continue program 
	//while user wants to
	while (exit_condition > 0) {


		//==================================================
		//display menu and return choice 
		int choice = menu();
		


		//===================================================
		//init temp var for user input and loops while 
		//program in use
		
		//blank for car class id, num, and iterators i&j
		int id,i,j,num,flag;
		
		//blank for car class make
		string make;
		
		//blank for car class modle
		string modle;
		
		//blank for car class color
		string color;
		
		//blank car class
		Car temp;
		
		//blank string for file in
		string fileName;
		
		//blank in file obj
		ifstream myfile;
		
		//blank for line by line file input
		string line;


		
		//====================================================
		//switch statement to guide UI based on user input
		switch (choice) {
			case 1:
			
				//search by ID
				cout << "Enter the ID required: ";
				cin >> id;
				searchID(id, cars);
				cout << endl;
	
				//reset id for future use
				id = INT_MIN;
				break;
	
				
			case 2://================================================
			
				//search by Make
				cout << "Enter the Make required: ";
				cin >> make;
				searchMake(make,cars);
				cout << endl;
			
				//reset make for future use
				make = "";
				break;

			
			case 3://================================================

				//search by Modle
				cout << "Enter the Modle required: ";
				cin >> modle;
				searchModle(modle, cars);
				cout << endl;
				
				//reset modle for future use
				modle = "";
				break;

			case 4://================================================

				//search by Color
				cout << "Enter the color required: ";
				cin >> color;
				searchColor(color, cars);
				cout << endl;

				//reset color for future use
				color = "";
				break;

			case 5://================================================

				//add a car

				//value to check if a new car was added to 
				//the list 
				flag = cars.size();
	
				//additional instructions here
				cout << "To add a car to the list, the car\n"
					<< " must be initialized.\n"
					<< "Please enter the car's ID: ";

				////////////////////////////////////////
				cin>>id;
			
				//if bad input, ouput error
				if (cin.fail()) {
					cerr << "Invalid input\n" << endl;
					exit(1);
				}

				//update temp member ID
				temp.setID(id);
				
				// reset id for future use
				id = INT_MIN;
	
				//clear input value
				cin.clear();
				cout << endl;
				
				////////////////////////////////////////
				cout << "Make: ";
				cin >> make;
				
				//if bad input, ouput error
				if (cin.fail()) {
					cerr << "Invalid input\n" << endl;
					exit(1);
				}
	
				//update temp member Make
				temp.setMake(make);
	
				//clear input value
				cin.clear();
				cout << endl;
				
				
				////////////////////////////////////////
				cout << "Modle: ";
				cin >> modle;
				
				//if bad input, ouput error
				if (cin.fail()) {
					cerr << "Invalid input\n" << endl;
					exit(1);
				}
	
				//update temp member Modle
				temp.setModle(modle);
				
				//clear input value
				cin.clear();
				cout << endl;
	
				
				////////////////////////////////////////
				cout << "Color: ";
				cin >> color;
				
				//if bad input, output error
				if (cin.fail()) {
					cerr << "Invalid input\n" << endl;
					exit(1);
				}
	
				//update temp member Color
				temp.setColor(color);
				
				//clear input value
				cin.clear();

				temp.print();
	
	
				////////////////////////////////////////
				//apend the temp car to the end of the list
				cars.push_back(temp);
	
				////////////////////////////////////////
				//conditional to check if the car has 
				//been added to the list
				if (cars.size() == flag+1) {
					cout << "Added car successfully.\n";
				}
				else {
					cerr << "An error occurred.";
					exit(1);
				}
				break;
	
			case 6://================================================
				
				//add car(s) by file
				//additional instructions here
				cout << "This option loads a pre-formatted file \n"
					<< "with data on 10 cars to the list.\n";
				cout << endl;



				fileName = "car.data";
				//if input good open file
				myfile.open(fileName);
	
				/*This section of code is desined to work with 
				a formatted file. the entries of the file are 
				in the following order:
				ID
				MAKE
				MODLE
				COLOR
				#
				then this pattern is repeated. var i iterates 
				through the enteries and temp stores the values
				from the file. Once the '#' is reached and (i == 4)
				cars.push_back(temp) is called to enter the car in 
				the list. var j keeps track of how many cars have been 
				added to the list. flag stores the old value of cars.size()
				to compare to the new value.*/
				i = 0;
				j = 0;
				flag = cars.size();
				//while there are lines to read in. 
				while (getline(myfile,line)) {
					switch (i) {
						case 0:
							//convert string input to int
							num = stoi(line);
							temp.setID(num);
							//if this input has been read increment i
							++i;
							break;
						case 1:
							temp.setMake(line);
							//if this input has been read increment i
							++i;
							break;
						case 2:
							temp.setModle(line);
							++i;
							//if this input has been read increment i
							break;
						case 3:
							temp.setColor(line);
							++i;//if this input has been read increment i
							break;
						case 4:
							//if all the fields have been filled add the car
							//to the list
							cars.push_back(temp);
							//reset i
							i = 0;
							//increment j to move to the next car
							j++;
							break;
					}
				}
				//close file when done
				myfile.close();
				
				//if there are the correct number of cars in the 
				//list reset i and j and output a success.
				if (flag+j == cars.size()) {
					cout << j << " Cars successfully added.\n";
					i = INT_MIN;
					j = INT_MIN;
					cout << endl;
				}
				//if not report error and quit.
				else {
					cerr << "an error occurred.\n";
					cout << endl;
					exit(1);
				}
				break;
			
			case 7://================================================
	
				//delete a car
				
				//set flag to old value of cars.size()
				flag = cars.size();
				cout << "Please enter the ID of the car to delete: ";
				cin >> id;
				cars.del(id);

				//if delete was successful cars.size() was updated 
				//in car.del()
				if (flag-1 == cars.size()) {
					cout << "car successfully deleted.\n";
					cout << endl;
				}
				//if not output error and quit
				else {
					cerr << "an error occurred.\n";
					cout << endl;
					exit(1);
				}
				//reset id for future use
				id = INT_MIN;
				break;
	
			case 8://================================================
	
				//list all cars
				cars.traverse();
				cout << endl;
				break;
	
			case 9://================================================
				//exit message
				cout << "Thank you for using the program. " << endl;
				//update exit condition
				exit_condition = -1;
				break;
		}
	}
}
	
void instructions() {
	cout << "This is the Rental Managemant System (RMS).\n"
		<< "In this system you can store an inventory of cars\n"
		<< "and thier information(ID,Make,Modle,Color). There \n"
		<< "are multiple features including a search by ID, Make,\n"
		<< " Modle, and Color. Cars can be added to the inventory by\n"
		<< " formated data file or manualy by calling the add() \n"
		<< "function. Existing cars can be deleted by ID, just \n"
		<< "use the list all cars feature to find the ID of \n"
		<< " the car needed if it is not already known. To exit\n"
		<< "the program select the menu option to do so.\n";
	cout << endl;
}

int menu() {

	
	int choice = INT_MIN;

	//menu printed out for the user to choose from
	cout << "Menu:\n"
		<<"___________________________________________\n"
		<<"1: Search by ID\n"
		<<"2: Search by Make\n"
		<<"3: Search by Modle\n"
		<<"4: Search by Color\n"
		<<"5: Add a car\n"
		<<"6: Add car(s) by file\n"
		<<"7: Delete a car\n"
		<<"8: List all cars\n"
		<<"9: Exit the program\n"
		<< "Please enter the number for your choice: \n";
	cout << endl;

	//take user input 
	cin >> choice;
	//check that input is type int 
	if (cin.fail()) {
		cerr << "Invalid input" << endl;
		exit(1);
	}
	//check input is in range 
	if (choice < 0 || choice > 9) {
		cerr << "Invalid input" << endl;
		exit(1);
	}
	return choice;
}

//searchID sweeps cars array for a matching ID
//and calls the print member of the matching elt
//along with the index of the elt. If the 
//serch value is not found output not found
//message.
void searchID(int id, ArrList& cars) {
	int found = 0;
	for (int i = 0; i < cars.size(); ++i) {
		if (id == cars[i].getID()) {
			 cars[i].print();
			 cout << "At: " << i << endl;
			 found = 1;	
		}
	}
	if(found == 0 )
		cout << "No cars with the search attribute.\n";
}

//searchMake sweeps cars array for a matching Make
//and returns the matching elt. If the 
//serch value is not found output not found
//message.
void searchMake(string mk, ArrList& cars) {
	int found = 0;
	for (int i = 0; i < cars.size(); ++i) {
		if (mk == cars[i].getMake()) {
			cars[i].print();
			cout << "At: " << i << endl;
			found = 1;
		}
	}
	if (found == 0)
		cout << "No cars with the search attribute.\n";
}

//searchModle sweeps cars array for a matching Modle
// and returns the matching elt. If the 
//serch value is not found output not found
//message.
void searchModle(string md, ArrList& cars) {
	int found = 0;
	for (int i = 0; i < cars.size(); ++i) {
		if (md == cars[i].getModle()) {
			cars[i].print();
			cout << "At: " << i << endl;
			found = 1;
		}
	}
	if(found == 0)
		cout << "No cars with the search attribute.\n";
}

//searchColor sweeps cars array for a matching Color
//and returns the matching elt. If the 
//serch value is not found output not found
//message.
void searchColor(string co, ArrList& cars) {
	int found = 0;
	for (int i = 0; i < cars.size(); ++i) {
		if (co == cars[i].getColor()) {
			cars[i].print();
			cout << "At: " << i << endl;
			found = 1;
		}
	}
	if(found == 0)
		cout << "No cars with the search attribute.\n";
}