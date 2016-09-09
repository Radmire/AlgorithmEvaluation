//Programmer: Ryan Admire
//Project #1
//File: used for part B1

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iomanip>

//Function prototypes
int * CreateArray(int * arr, int length);
void Print(int arr[], int length);
int LinearSearch(int arr[], int length, int key);
int BinarySearch(int arr[], int lenght, int key);

using namespace std;

int main() {

	int length = 100;    //length of the arrays to be searched
	int * arr = NULL;    //array of 100 ints that will be searched
	arr = CreateArray(arr, length); //fill the array with values
	srand(time(NULL));    //make our numbers time based random values
	int key = rand() % arr[length - 1] + arr[0]; //make our key to be searched for between our highest and lowest array values

	cout << "Sorted Array" << endl;
	Print(arr, length);  //prints the array
	cout << endl << endl
		<< "Value to search for: " << key << endl
		<< "Results of Linear Search: ";

	//Conditional to handle the result of our searches
	if (LinearSearch(arr, length, key) == -1) { //if the value wasn't found
		cout << "Value not found in array" << endl;
	}
	else {
		cout << "Value found at index " << LinearSearch(arr, length, key) << endl;
	}

	cout << "Results of Binary Search: ";

	//Now for Binary Search
	if (BinarySearch(arr, length, key) == -1) { //if the value wasn't found
		cout << "Value not found in array" << endl;
	}
	else {
		cout << "Value found at index " << BinarySearch(arr, length, key) << endl;
	}

	delete[] arr;
	arr = NULL;

}

//Reads the array in from a file
int * CreateArray(int * arr, int length) {

	ifstream in("array.txt"); //file to get the sorted array from

	//Check if the file is open
	if (in.is_open()) {
		arr = new int[length];  //allocate memory for the array

		//fill the array
		for (int i = 0; i < length; i++) {
			in >> arr[i];
		}
	}

	in.close(); //close the file

	return arr;

}

//Prints our array
void Print(int arr[], int length) {

	for (int i = 0; i < length; i++) {
		cout << left << setw(10) << setfill(' ') << arr[i];
	}
}

//Takes a sorted array and finds a random value which may be contained in the array. Returns the index of the value
int LinearSearch(int arr[], int length, int key) {

	for (int i = 0; i < length; i++) {
		if (key == arr[i]) {
			return i;
		}
	}

	return -1;  //value not found

}

//Takes a sorted array and does a binary search to find a random value that may be in it. Returns the index of the value
int BinarySearch(int arr[], int length, int key) {

	int low = 0;             //smallest val
	int high = length - 1;   //highest val

							 //while the bounds make sense
	while (low <= high) {
		int mid = ((low + high) / 2);  //midpoint of the bounds
		if (arr[mid] > key) {          //if the key is smaller than the value
			high = mid - 1;            //highest key is one smaller than mid
		}
		else if (arr[mid] < key) {     //if the key is bigger than the mid
			low = mid + 1;             //lowest val is one larger than the mid
		}
		else {
			return mid;   //found the value return its index!
		}
	}

	return -1; //value was not found
}
