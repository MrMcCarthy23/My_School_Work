//Mark McCarthy

//This program implements a simulation of the 
//round robin scheduling algorithm using stl queue

#include "Process.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>

using namespace std;

void arrivals(vector<Process>& vec, queue<Process>& q, int time);

int main() {
	//init containers, var, and fstream obj 
	vector<Process> vec;
	queue<Process> q;
	ifstream file;
	Process temp;
	int id, at, tr, time = 0;
	int exit_flag = 0;

	//open text file 
	file.open("round_robin.txt");

	//if opened successfuly, read in the  
	if (file.is_open()) {

		//while loop uses the formatted input for arithmetic
		//types feature of the operator >> as a conditional
		//statement to navigate the file and to read in the 
		//values for the process class. Then inits a process
		//type and stores it to a vector.
		while (file>>id>>at>>tr) {
			Process p(id, at, tr);
			vec.push_back(p);
		}
		
		//close the file
		file.close();
	}

	//if the file fails to open output error and exit program
	else {
		cerr << "Failed to open file\n";
		exit(1);
	}

	/////######################driver loop#######################////

	//use size of the vector as exit cond. for while loop
	exit_flag = vec.size();

	while (exit_flag > 0) {

		//check the vector for any arrivals and push them to queue
		arrivals(vec, q, time);

		//if the queue is empty, update time and continue
		if (q.empty()) {
			time += 4;
			continue;
		}

		//if the current process at the front of the queue
		//is going to be completed, mark the finish time 
		//and pop it from the queue
		if (q.front().getRtime() <= 4) {

			//set the finish time value
			q.front().setFtime(time);
			
			//output the values for the finished process
			q.front().print();
			
			//pop th efinished process from the queue
			q.pop();
			
			cout << "###########################" << endl;
			exit_flag--;
			
			//update time
			time += 4;
		}
		//if the current process at the front of the queue is
		//not going to be finished 
		else {

			//make a copy of the front of the queue
			temp = q.front();
			
			//pop the queue
			q.pop();
			
			//update time
			time += 4;
			
			//check if there are any new arrivals
			arrivals(vec, q, time);
			
			//update the time req for the process
			temp.setRtime(temp.getRtime() - 4);
			
			//push it back to the queue
			q.push(temp);
		}
	}
}

//function checks the arrival times of the processes int the 
//vector and enqueues the process(es) if the arrival time(s) match.
void arrivals(vector<Process>& vec, queue<Process>& q,int time){

	//for loop sweeps the vector for matching arrival times
	//and sets the bool value Process.added to true if it 
	//has been added to the queue
	for (int i = 0; i < vec.size(); i++) {
		if (time >= vec[i].getAtime() && !vec[i].getAdd()) {
			q.push(vec[i]);
			vec[i].setAdd(1);
		}
	}
}
