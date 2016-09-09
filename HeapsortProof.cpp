//Programmer: Ryan Admire
//Project #2
//File: used in Heapsort Section, Part C

#include<string>
#include<time.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<cmath>
#include<iomanip>


using namespace std;

///////FUNCTION TO BE USED////////////////
int * CreateArray(int * arr, int length); //Creates an array based on the passed length
void Print(int arr[], int length);      //Prints an array
int HeapSort(int * arr, int length);   //sorts the passed array by making an ever decreasing heap
void Swap(int * arr, int a, int b);   //Swaps the elements of the passed array at the passed indices
void MaxHeapify(int * arr, int val, int size);  //re-establishes the heap behavior necessary for the sort
int BuildMaxHeap(int * arr, int len);//Builds the initial heap


int main() {

	int N = 1000;     //length of large array
	int len = 50;     //length of small array
	int * arr = NULL; //will hold the array
	int build_time = 0; //time constructin heap
	int tot = 0;        //time spent sorting
	double av = 0, bav = 0;     //averages because the program is too fast
	clock_t t1, t2;    //used to time HeapSort


	arr = CreateArray(arr, len); //create the array
	Print(arr, len);             //print the array
	cout << endl << endl;        //newlines
	HeapSort(arr, len);          //sort the array
	Print(arr, len);             //print the now sorted array
	cout << endl << endl;


	for (int i = 0; i < 1000; i++) {
		//garbage collection
		delete[] arr;
		arr = NULL;

		//Larger array section
		arr = CreateArray(arr, N); //create large array
		t1 = clock();
		build_time = HeapSort(arr, N); //sort it
		t2 = clock();
		tot = t2 - t1; //get the difference between starting and ending times

		//totals
		bav = double(build_time) + bav;
		av = double(tot) + av;
	}

	av = av / double(1000)/double(CLOCKS_PER_SEC); //convert to seconds
	bav = bav / double(1000) / double(CLOCKS_PER_SEC); //convert to seconds



	//section to output all pertinent data
	cout << "Array Size - " << N << endl
		<< "Total Time: " << av << " seconds" << endl
		<< "Build Time: " << bav << " seconds" << endl
		<< "Sort Time: " << av - bav << " seconds" << endl << endl;




	return  0;
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

//Prints the passed arrary
void Print(int arr[], int length) {

	for (int i = 0; i < length; i++) {
		cout << left << setw(10) << setfill(' ') << arr[i];
	}
}

//Sorts the passed array by making an ever smaller heap until only a sorted array remains
int HeapSort(int * arr, int length) {

	int heap_size = length;  //size of the heap
	int build_time = 0;      //time it takes to buld the heap

	build_time = BuildMaxHeap(arr, length); //builds the heap
	heap_size--;
    
	//from the end of the heap down to the second to last element
	for (int i = length - 1; i > 0; i--) {
		Swap(arr, 0, i); //swap the first and the ith element
		heap_size--;
		MaxHeapify(arr, 0, heap_size); //maintains heap qualities
	}

	return build_time;
}

//ensure the heap behavior necessary for the sort
void MaxHeapify(int * arr, int val, int size) {

	int l = 2 * val; //left child of val
	int r = 2 * val + 1; //right child of val
	int max = 0; //max value

				 //if the left child is in the heap and is larger than the array element at passed val
	if ((l <= size) && (arr[l] > arr[val])) {
		max = l; //max is left child
	}
	else {
		max = val; //max is passed val
	}

	//if the right child is in the heap and is larger than the array element at the current max
	if ((r <= size) && (arr[r] > arr[max])) {
		max = r; //right child is the max
	}

	//if max is not the passed val
	if (max != val) {
		Swap(arr, val, max); //swap array elements at val and max
		MaxHeapify(arr, max, size); //calls itself with max as the passed val
	}
}

//Build the initial heap
int BuildMaxHeap(int * arr, int len) {

	clock_t t1, t2; //clocks to track how long it takes to build the heap

	t1 = clock();
	//for loop to buid the array. Goes from the halfway mark downto the bottom
	for (int i = floor((len - 2) / 2); i >= 0; i--) {
		MaxHeapify(arr, i, len - 1); //call max_heapify
	}
	t2 = clock();

	return (t2 - t1);
}

//Swap elements in the passed array, at the passed indices
void Swap(int * arr, int a, int b) {

	int hold = 0; //will help swap vals

				  //swap the elements
	hold = arr[a];
	arr[a] = arr[b];
	arr[b] = hold;
}
