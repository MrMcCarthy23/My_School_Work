# include <iostream>
# include <fstream>
using namespace std;


int main()
{
	char x;	// temp initialization 

	int len = 0;	//initialize length counter

	ifstream ifs("file.txt");	// open file

	while (ifs.eof() != true)	// loop through file until the end is reached
	{
		ifs >> x;	// assign x to the current value of the character in the file

		if (x != ' ')	// conditional to check for white spaces
			len++;	// increment lenght if not a white space

	}
	cout << "Number of characters: " << len << endl;	// result statement
}