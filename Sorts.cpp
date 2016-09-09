//Programmer: Ryan Admire
//Project #1
//File: used for part A1

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <fstream>

//Function prototypes
int * CreateArray(int * arr, int length);
void Print(int arr[], int length);
void BubbleSort(int arr [], int length);
void CocktailSort(int arr[], int length);
void ShellSortHalf(int arr[], int length);
void ShellSortCiura(int arr[], int length);


using namespace std;

int main() {

	int length = 100;
	int * arr = NULL;                    //pointer to be used for our array of random numbers
	int sorted[100];                     //a copy of the array which will be sorted.
	arr = CreateArray(arr, length);      //fills the array
	ofstream out;                        //file to be written to
	out.open("array.txt");


	//copies unsorted array.
	for (int i = 0; i < 100; i++) {
		sorted[i] = arr[i];
	}
	
	//prints the unsorted array
	cout << "Unosrted Array" << endl;
	Print(arr, 100);
	cout << endl << endl;

	BubbleSort(sorted, 100);

	//prints the sorted array
	cout << "Bubble Sort" << endl;
	Print(sorted, 100);
	cout << endl << endl;

	//copies unsorted array.
	for (int i = 0; i < 100; i++) {
		sorted[i] = arr[i];
	}

	//prints the unsorted array
	cout << "Unsorted Array" << endl;
	Print(arr, 100);
	cout << endl << endl;

	CocktailSort(sorted, 100);

	//prints the sorted array
	cout << "Cocktail Sort" << endl;
	Print(sorted, 100);
	cout << endl << endl;

	//copies unsorted array.
	for (int i = 0; i < 100; i++) {
		sorted[i] = arr[i];
	}

	//prints the unsorted array
	cout << "Unsorted Array" << endl;
	Print(arr, 100);
	cout << endl << endl;

	ShellSortHalf(sorted, 100);

	//prints the sorted array
	cout << "Shell Sort #1" << endl;
	Print(sorted, 100);
	cout << endl << endl;

	//copies unsorted array.
	for (int i = 0; i < 100; i++) {
		sorted[i] = arr[i];
	}

	//prints the unsorted array
	cout << "Unsorted Array" << endl;
	Print(arr, 100);
	cout << endl << endl;

	ShellSortCiura(sorted, 100);

	//prints the sorted array
	cout << "Shell Sort #2" << endl;
	Print(sorted, 100);
	cout << endl << endl;

	delete[] arr;
	arr = NULL;

	//Write sorted array to a file
	for (int i = 0; i < length; i++) {
		out << sorted[i] << endl;
	}

	out.close(); //close the file
	
}



//Creates the array filled with random integers
int * CreateArray(int * arr, int length) {

	srand(time(NULL));
	arr = new int[length];

	//fill the array with 100 random integers
	for (int i = 0; i < 100; i++) {
		arr[i] = rand();
	}

	return arr;
}

void Print(int arr[], int length) {

	for (int i = 0; i < length; i++) {
		cout << left << setw(10) << setfill(' ') << arr[i];
	}
}

//Function for bubble sort, with swaps counted.
void BubbleSort(int arr[], int length) {

	int hold;             // will be used to swap
	bool swapped = true;  //boolean to check if a swap was made
	
	for (int i = 0; i < length; i++) {

		if (swapped == true) {  //check after each loop to see if a swap was made
			swapped = false;

			for (int j = length - 1; j > i; j--) {
				if (arr[j] < arr[j - 1]) {         //if the j is smaller move it up the array
					hold = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = hold;
					swapped = true;
				}

			}

			//if nothing was swapped stop the loop
			if (swapped == false) {
				i = length;
			}

		}
	}
}

//Function for cocktail sort, which functions much like Bubble Sort but switches direction
void CocktailSort(int arr[], int length) {

	int hold;             // will be used to swap
	bool swapped = true;  //boolean to check if a swap was made

	while (swapped) {   //Continue while swaps are being made

		swapped = false;

		for (int i = 0; i < length - 1; i++)
			if (arr[i+1] < arr[i]) {         //if the j is smaller move it up the array
				hold = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = hold;
				swapped = true;
			}

		//if nothing was swapped stop the loop
		if (!swapped) {
			break;
		}
	
		swapped = false;  //if there was a swap, reset the variable

		//Do another loop from the other side of the array
		for (int j = length - 1; j > 0; j--){

			if (arr[j] < arr[j - 1]) {
				hold = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = hold;
				swapped = true;
			}
		}
	}
}

//Function for ShellSort which sorts based on gaps which are in turn based on length of the array
void ShellSortHalf(int arr[], int length) {

	int gap = 2;         //start off with a gap of two
	int ind = 0;         //index to compare against
	int powr = 1;        //what gap will be raised to
	int flrGap = floor(length / gap);  //will be the true gap
	int hold = 0;                      //will be used to swap

	//Gaps in this case will be the floor of length divided by powers of 2.
	while (flrGap > 0) {
										   
		//Loop through at the gap size
		for (int i = flrGap; i < length; i++) {

			ind = i;          //will be checked against later  
			hold = arr[i];    //holds the value of the current index

			//while ind is greater than or equal to the gap and the index of their difference is greater than the held value
			//then swap them and decrement ind
			while (ind >= flrGap && arr[ind - flrGap] > hold){
				arr[ind] = arr[ind - flrGap];
				ind = ind - flrGap;
			}

			arr[ind] = hold;   //put the held value back into the array
		}

			powr++;
			gap = pow(2, powr);
			flrGap = floor(length / gap);  
			
	}
	
}

//Function for ShellSort which sorts based on gaps of various sizes
void ShellSortCiura(int arr[], int length) {

	int gap[6] = { 57, 23, 10, 4, 1 }; //array of gaps
	int ind = 0;                       //index to compare against
	int hold = 0;                      //will be used to swap

									  
	for (int i = 0; i < 6; i++) {

		//Loop through at the gap size
		for (int k = gap[i]; k < length; k++) {

			ind = k;          //will be checked against later  
			hold = arr[k];    //holds the value of the current index

			//while ind is greater than or equal to the gap and the index of their difference is greater than the held value
			//then swap them and decrement ind
			while (ind >= gap[i] && arr[ind - gap[i]] > hold) {
				arr[ind] = arr[ind - gap[i]];
				ind = ind - gap[i];
			}

			arr[ind] = hold;   //put the held value back into the array
		}
	}
}
