// Ch13_Ex11_MainProgram.cpp - given code below  

#include <iostream> 
#include "myArray.h"

using namespace std;
int main()
{
	// Creates list1 and list2
	myArray list1(5);
	myArray list2(5);


	// Zeroing (initializing) first array
	int i;
	cout << "list1 : ";
	for (i = 0; i < 5; i++)
		cout << list1[i] << " ";
		cout << endl;

	// Prompt to enter five numbers into list1
	cout << "Enter 5 integers: ";
	for (i = 0; i < 5; i++)
		cin >> list1[i];
		cout << endl;

	// show contents list1
	cout << "After filling list1: ";
	for (i = 0; i < 5; i++)
		cout << list1[i] << " ";
		cout << endl;

	// Transfer five elements from list1 to list2, Print list2
	list2 = list1;
	cout << "list2 : ";
	for (i = 0; i < 5; i++)
		cout << list2[i] << " ";
		cout << endl;

	// Write three elements replacing first 3 of list1
	cout << "Enter 3 elements: ";
	for (i = 0; i < 3; i++)
		cin >> list1[i];
		cout << endl;

	// Prints three elements of list1 just entered
	cout << "First three elements of list1: " << endl;
	for (i = 0; i < 3; i++)
		cout << list1[i] << " ";
		cout << endl;

	// Create list3 for first time
	// Induced Chaos by
	// cramming -2 to 6 into array list3
	myArray list3(-2, 6);

	// Print 8 array location numbers from -2 through 5
	// Should print zero eight times if memory is initialized
	cout << "list3: ";
	for (i = -2; i < 6; i++) cout << list3[i] << " ";
		cout << endl;

		// Assign some numbers to out-of-bounds locations
		list3[-2] = 7;
		//list3[-1] = 0; implied
		list3[0] = 54;
		//list3[1] = 0; implied
		list3[2] = list3[4] + list3[-2]; // 8 + 7 = 15 
		//list3[3] = 0; implied
		list3[4] = 8;
		//list3[5] = 0; implied

	// Print results to screen
	cout << "list3: ";
	for (i = -2; i < 6; i++)
		cout << list3[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
