//Programmer: Ryan Admire
//Project #1
//File: used for part A2

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <fstream>

//Function prototypes
int * CreateArray(int * arr, int length);
void BubbleSort(int arr[], int length);
void CocktailSort(int arr[], int length);
void ShellSortHalf(int arr[], int length);
void ShellSortCiura(int arr[], int lenght);



using namespace std;

int main() {

	int * arr = NULL;     //pointer to be used for our array of random numbers
	int length = 0;       //will hold our length at various points
	double av = 0;        //double to hold the average execution time of the functions
	int tot = 0;          //int to hold the total of the execution times added together
	int duration = 0;     //duration of a code fragment
	ofstream out;          //stream for the files that will be written to

	//For 10 random arrays of size 500
	for (int i = 0; i < 10; i++) {
		length = 500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		BubbleSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0)/CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into seconds

	//output for the average
	cout << "Average Times of Bubble Sort:" << endl
		 << "500  elements - " << av << " seconds" << endl;

	tot = 0;

	//For 10 random arrays of size 1000
	for (int i = 0; i < 10; i++) {
		length = 1000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		BubbleSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "1000 elements - " << av << " seconds" << endl;
	
	tot = 0;

	//For 10 random arrays of size 2500
	for (int i = 0; i < 10; i++) {
		length = 2500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		BubbleSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "2500 elements - " << av << " seconds" << endl;
	
	tot = 0;

	//For 10 random arrays of size 5000
	for (int i = 0; i < 10; i++) {
		length = 5000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		BubbleSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "5000 elements - " << av << " seconds" << endl;

	/////////////////////////////////BEGIN COCKTAIL SORT HERE//////////////////////////////////////////////////

	tot = 0;

	cout << endl;

	//For 10 random arrays of size 500
	for (int i = 0; i < 10; i++) {
		length = 500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		CocktailSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into seconds

										  //output for the average
	cout << "Average Times of Cocktail Sort:" << endl
		<< "500  elements - " << av << " seconds" << endl;

	tot = 0;

	//For 10 random arrays of size 1000
	for (int i = 0; i < 10; i++) {
		length = 1000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		CocktailSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "1000 elements - " << av << " seconds" << endl;

	tot = 0;

	//For 10 random arrays of size 2500
	for (int i = 0; i < 10; i++) {
		length = 2500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		CocktailSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "2500 elements - " << av << " seconds" << endl;

	tot = 0;

	//For 10 random arrays of size 5000
	for (int i = 0; i < 10; i++) {
		length = 5000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		CocktailSort(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "5000 elements - " << av << " seconds" << endl;


	/////////////////////////////////BEGIN SHELL SORT 1 HERE//////////////////////////////////////////////////

	tot = 0;

	cout << endl;

	//For 10 random arrays of size 500
	for (int i = 0; i < 10; i++) {
		length = 500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortHalf(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into seconds

										  //output for the average
	cout << "Average Times of Shell Sort #1:" << endl
		<< "500  elements - " << av << " seconds" << endl;

	tot = 0;

	//For 10 random arrays of size 1000
	for (int i = 0; i < 10; i++) {
		length = 1000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortHalf(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "1000 elements - " << av << " seconds" << endl;

	tot = 0;

	//For 10 random arrays of size 2500
	for (int i = 0; i < 10; i++) {
		length = 2500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortHalf(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "2500 elements - " << av << " seconds" << endl;

	tot = 0;

	//For 10 random arrays of size 5000
	for (int i = 0; i < 10; i++) {
		length = 5000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortHalf(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;
	}

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into second

	cout << "5000 elements - " << av << " seconds" << endl;

	/////////////////////////////////BEGIN SHELL SORT 2 HERE//////////////////////////////////////////////////


	tot = 0;

	cout << endl;

	out.open("500.txt");

	//For 10 random arrays of size 500
	for (int i = 0; i < 10; i++) {
		length = 500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortCiura(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;

		//Fill the file
		for (int j = 0; j < length; j++) {
			out << arr[j] << endl;
		}

		out << endl; //add an extra line
	}

	out.close();  //close the file

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into seconds

	//output for the average
	cout << "Average Times of Shell Sort #2:" << endl
		<< "500  elements - " << av << " seconds" << endl;


	tot = 0;

	out.open("1000.txt");

	//For 10 random arrays of size 1000
	for (int i = 0; i < 10; i++) {
		length = 1000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortCiura(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;

		//Fill the file
		for (int j = 0; j < length; j++) {
			out << arr[j] << endl;
		}

		out << endl; //add an extra line
	}

	out.close();

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into seconds

	cout << "1000 elements - " << av << " seconds" << endl;

	tot = 0;

	out.open("2500.txt");

	//For 10 random arrays of size 2500
	for (int i = 0; i < 10; i++) {
		length = 2500;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortCiura(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;

		//Fill the file
		for (int j = 0; j < length; j++) {
			out << arr[j] << endl;
		}

		out << endl; //add an extra line

	}

	out.close();

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into seconds

	cout << "2500 elements - " << av << " seconds" << endl;

	tot = 0;

	out.open("5000.txt");

	//For 10 random arrays of size 5000
	for (int i = 0; i < 10; i++) {
		length = 5000;
		arr = CreateArray(arr, length);
		clock_t t1, t2;
		t1 = clock();
		ShellSortCiura(arr, length);
		t2 = clock();
		duration = t2 - t1;
		tot += duration;

		//Fill the file
		for (int j = 0; j < length; j++) {
			out << arr[j] << endl;
		}

		out << endl; //add an extra line
	}

	out.close();

	av = (tot / 10.0) / CLOCKS_PER_SEC;   //average number of clock ticks, then convert that into seconds

	cout << "5000 elements - " << av << " seconds" << endl;

	delete[] arr;
	arr = NULL;

}



//Creates the array filled with random integers
int * CreateArray(int * arr, int length) {

	srand(time(NULL));
	arr = new int[length];

	//fill the array with 100 random integers
	for (int i = 0; i < length; i++) {
		arr[i] = rand();
	}

	return arr;
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
			if (arr[i + 1] < arr[i]) {         //if the j is smaller move it up the array
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
		for (int j = length - 1; j > 0; j--) {

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
			while (ind >= flrGap && arr[ind - flrGap] > hold) {
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
