#include <iostream>

using namespace std;

int main()
{
	//var declaration
	int n;
	int bef_prev = 0;
	int prev = 1;
	int current = 0;

	//prompt user for num of iterations to output
	cout << "Enter number of Fibonacci numbers required: ";
	cin >> n;

	//for loop to calculate the successive numbers in the sequence 
	for (int i = 0; i < n; i++)
	{
		current = bef_prev + prev;
		bef_prev = prev;
		prev = current;
		cout << current << ", ";
	}
	return 0;
}