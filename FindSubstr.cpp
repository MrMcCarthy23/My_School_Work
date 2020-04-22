#include <iostream>

using namespace std;

//function definitions
int str_comp(char searched[], char query[], int searchlen, int querylen);
int get_len(char carr[]);

int main()
{

	const int max = 1000;	// variable declarations
	char searched[max], query[max];
	int searchlen, querylen;

	cout << "Enter first string: " << endl;	// prompt user for strings to compare
	cin.getline(searched, max);
	cout << "Enter second string: " << endl;
	cin.getline(query, max);

	cout << "\n" << endl;	// new line

	searchlen = get_len(searched);	//function calls for getting the length of each string
	querylen = get_len(query);

	int index = str_comp(searched, query, searchlen, querylen); //function call for searching for substring

	if (index >= 0)	// result statements
		cout << "Substring exists at index " << index << endl;
	else
		cout << "Substring DOES NOT exist" << endl;

	return 0;
}
int str_comp(char searched[], char query[], int searchlen, int querylen)	//substring search function definition
{
	int index = -1;
	for (int i = 0; i < searchlen; i++)	// for loop to search string for first cahr of substring
	{
		if (searched[i] == NULL)	// stop search condition
			break;
		if (searched[i] == query[0])	//conditional to set index to the appropriate value
		{
			index = i;
			for (int j = 1; j < querylen; j++)	// for loop to check if the substring is contained in the string 
			{
				if (query[j] != searched[i + j])	//conditional to check if the string char matches the substring char
				{
					index = -1;
					break;
				}
				else
					return index;	// return index if the substring is contained
			}
		}

	}
	return index;	// return -1 if the substring was not found
}
int get_len(char carr[])	// function declaration for getting the length of the string
{
	int max = 1000, length = 0;	// varible declaration

	for (int i = 0; i < max; i++)	// for loop to increment length count and check if the null character has been reached
	{
		if (carr[i] == NULL)
			break;
		else
			length++;
	}
	return length;
}