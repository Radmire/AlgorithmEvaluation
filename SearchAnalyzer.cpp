//Programmer: Ryan Admire

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <string.h>
#include <string>

//Function prototypes
int * CreateArray(int * arr, int length, std::string name);
int LinearSearch(int arr[], int length, int key);
int BinarySearch(int arr[], int lenght, int key);

using namespace std;

int main() {

	long double lDur = 0, lTot = 0, bDur = 0, bTot = 0;  //to help track how quick searches are done
	double lAv = 0, bAv = 0, bAv2 = 0, bAv3 = 0, bAv4 =0;  //doubles to hold the average of searches
	int * arr = NULL;                            //will hold the various arrays
	int length = 0;                              //length of the array
	srand(time(NULL));                           //make our numbers time based random values
	int key = 0;                                 //key to be searched for


	//for 10 arrays of size 500
	for (int i = 0; i < 500; i++) {
		length = 500;
		arr = CreateArray(arr, length, "500.txt");
	    key = rand() % arr[length - 1] + arr[0]; //make our key to be searched for between our highest and lowest array values
		clock_t t1, t2;
		t1 = clock();

		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			LinearSearch(arr, length, key);
		}

		t2 = clock();
		lDur = (t2 - t1)/1000;  //must divide by the number of repitions
		lTot += lDur;           //add the duration into the total

		t1 = clock();
		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			BinarySearch(arr, length, key);
		}

		t2 = clock();
		bDur = (t2 - t1) / 1000;  //must divide by the number of repitions
		bTot += bDur;           //add the duration into the total

	}

	lAv = (lTot / 10.0) / CLOCKS_PER_SEC;
	bAv = (bTot / 10.0) / CLOCKS_PER_SEC;

	//Results of the search timings
	cout << "Average Times of Linear Search:" << endl
		 << "500 elements - " << lAv << " seconds" << endl;

	lTot = 0;
	bTot = 0; //reset totals

	//for 10 arrays of size 1000
	for (int i = 0; i < 1000; i++) {
		length = 1000;
		arr = CreateArray(arr, length, "1000.txt");
		key = rand() % arr[length - 1] + arr[0]; //make our key to be searched for between our highest and lowest array values
		clock_t t1, t2;
		t1 = clock();

		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			LinearSearch(arr, length, key);
		}

		t2 = clock();
		lDur = (t2 - t1) / 1000;  //must divide by the number of repitions
		lTot += lDur;           //add the duration into the total

		t1 = clock();
		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			BinarySearch(arr, length, key);
		}

		t2 = clock();
		bDur = (t2 - t1) / 1000;  //must divide by the number of repitions
		bTot += bDur;           //add the duration into the total

	}

	lAv = (lTot / 10.0) / CLOCKS_PER_SEC;
	bAv2 = (bTot / 10.0) / CLOCKS_PER_SEC;

	cout << "1000 elements - " << lAv << " seconds" << endl;

	lTot = 0;
	bTot = 0;

	//for 10 arrays of size 2500
	for (int i = 0; i < 2500; i++) {
		length = 2500;
		arr = CreateArray(arr, length, "2500.txt");
		key = rand() % arr[length - 1] + arr[0]; //make our key to be searched for between our highest and lowest array values
		clock_t t1, t2;
		t1 = clock();

		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			LinearSearch(arr, length, key);
		}

		t2 = clock();
		lDur = (t2 - t1) / 1000;  //must divide by the number of repitions
		lTot += lDur;           //add the duration into the total

		t1 = clock();
		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			BinarySearch(arr, length, key);
		}

		t2 = clock();
		bDur = (t2 - t1) / 1000;  //must divide by the number of repitions
		bTot += bDur;           //add the duration into the total

	}

	lAv = (lTot / 10.0) / CLOCKS_PER_SEC;
	bAv3 = (bTot / 10.0) / CLOCKS_PER_SEC;

	cout << "2500 elements - " << lAv << " seconds" << endl;

	bTot = 0;
	lTot = 0;

	//for 10 arrays of size 5000
	for (int i = 0; i < 5000; i++) {
		length = 5000;
		arr = CreateArray(arr, length, "5000.txt");
		key = rand() % arr[length - 1] + arr[0]; //make our key to be searched for between our highest and lowest array values
		clock_t t1, t2;
		t1 = clock();

		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			LinearSearch(arr, length, key);
		}

		t2 = clock();
		lDur = (t2 - t1) / 1000;  //must divide by the number of repitions
		lTot += lDur;           //add the duration into the total

		t1 = clock();
		//run through the search many times to ensure a value for time is gotten
		for (int j = 0; j <= 1000; j++) {
			BinarySearch(arr, length, key);
		}

		t2 = clock();
		bDur = (t2 - t1) / 1000;  //must divide by the number of repitions
		bTot += bDur;           //add the duration into the total

	}

	lAv = (lTot / 10.0) / CLOCKS_PER_SEC;
	bAv4 = (bTot / 10.0) / CLOCKS_PER_SEC;

	cout << "5000 elements - " << lAv << " seconds" << endl << endl;

	//Results for Binary Search
	cout << "Average Times of Binary Search:" << endl
		 << "500 elements  - " << bAv << " seconds" << endl
		 << "1000 elements - " << bAv2 << " seconds" << endl
		 << "2500 elements - " << bAv3 << " seconds" << endl
		 << "5000 elements - " << bAv4 << " seconds";

	delete[] arr;
	arr = NULL;

}

//creates an array with the passed parameters
int * CreateArray(int * arr, int length, string name) {

	ifstream in(name.c_str()); //file to get the sorted array from

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

	int low = 0;                                   //smallest val
	int high = length - 1;                         //highest val

												   //while the bounds make sense
	while (low <= high) {
		int mid = ((low + high) / 2);  //midpoint of the bounds
		if (arr[mid] > key) {               //if the key is smaller than the value
			high = mid - 1;            //highest key is one smaller than mid
		}
		else if (arr[mid] < key) {          //if the key is bigger than the mid
			low = mid + 1;             //lowest val is one larger than the mid
		}
		else {
			return mid;   //found the value return its index!
		}
	}

	return -1; //value was not found
}

