//Programmer: Ryan Admire
//Project #2
//File: used in Mergesort section, part A

#include<string>
#include<time.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<cmath>

using namespace std;

/////////FUNCTIONS TO BE USED/////////////
int * CreateArray(string file, int length);  //creates an array based on the passed file name
void CreateFile(string name, int length);    //creates a file of random integers of the passed length
void Append(string f1, string f2);           //Appends a smaller file to a larger one inside a new file
void Write(int arr[], int len, string name); //Writes an array's contents to a file
void Merge(int* arr, int p, int q, int r); //Mergesort will use this
void MergeSort(int* arr, int p, int r);    //Sorts with the help of Merge
void MergeFiles(string f1, string f2, string out);  //Merges two sorted files together

int main() {

	int length = 100; //length of the array
	int* arr = new int[length];  //will hold the array to be sorted
	srand(time(NULL)); //seed the random number generator to time

	//fill the array with random integers
	for (int i = 0; i < length; i++) {
		arr[i] = rand();
	}

	//Print the unsorted array
	for (int j = 0; j < length; j++) {
		cout << left << setw(10) << setfill(' ') << arr[j];
	}
	cout << endl << endl;

	MergeSort(arr, 0, 99); //sort the array

	//Print the sorted array
	for (int k = 0; k < length; k++) {
		cout << left << setw(10) << setfill(' ') << arr[k];
	}

	//garbage collection
	delete[] arr;
	arr = NULL;

	////////////Sorting & Merging Files Section////////////////////
	CreateFile("LargeTest.txt", 100);
	arr = CreateArray("LargeTest.txt", 100);
	MergeSort(arr, 0, 99);
	Write(arr, 100, "LargeTest.txt");

	//garbage collection
	delete[] arr;
	arr = NULL;


	CreateFile("SmallTest.txt", 10);
	arr = CreateArray("SmallTest.txt", 10);
	MergeSort(arr, 0, 9);
	Write(arr, 10, "SmallTest.txt");
	MergeFiles("LargeTest.txt", "SmallTest.txt", "TestComplete.txt");

	//garbage collection
	delete[] arr;
	arr = NULL;
}


//creates a file of random integers of the passed length returns an array of those values
void CreateFile(string name, int length) {

	ofstream out; //filestream to output integers to a file
	srand(time(NULL)); //seeds our number generator to time


	remove(name.c_str());  //remove the file if it exists
	out.open(name.c_str());

	//check if our file is open
	if (out.is_open()) {

		//loop until length is reached
		for (int i = 0; i < length; i++) {
			out << rand() << " ";
		}

		out.close(); //close the file

	}
}

//Creates an array absed on the passed file name
int * CreateArray(string file, int length) {

	int bs;                      //to throw stuff away
	int *arr = new int[length];  //array to hold the integers

	ifstream in(file.c_str()); //open the passed file


					   //if the file is successfully opened
	if (in.is_open()) {

		//fill the array with random integers
		for (int i = 0; i < length; i++) {
			in >> arr[i];      //read the number into the file
		}

		in.close();  //close the file
	}

	return arr;
}

//This function will do the heavy lifting of breaking and sorting, then merging in the mergesort function
void Merge(int* arr, int p, int q, int r) {

	int i, j, k;
	int n = q - p + 1;
	int m = r - q;

	int* L = new int[n];
	int* R = new int[m];

	for (i = 0; i < n; i++) {
		L[i] = arr[p + i];
	}
	for (j = 0; j < m; j++) {
		R[j] = arr[q + 1 + j];
	}

	i = j = 0;
	k = p;

	while (i < n && j < m) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < m) {
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
	L = R = NULL;

}

//This function will perform the Mergesort using Merge to do the heavy lifting.
void MergeSort(int* arr, int p, int r) {

	//as long as p remains smaller than r
	if (p < r) {
		int q = floor((r + p) / 2); //get the midpoint
		MergeSort(arr, p, q); //calls itself for the left
		MergeSort(arr, q + 1, r); //the right half
		Merge(arr, p, q, r);  //merges everything back together
	}
}

//Appends the second file to the first inside of a new third file
void Append(string f1, string f2) {

	ifstream inf1(f1.c_str()); //long file to be read from
	ifstream inf2(f2.c_str()); //short file to be read from
	ofstream out;      //longer file to be appended to
	int hold;          //integer to hold the data from the files

	remove("Appended.txt");          //remove the file if it exists
	out.open("Appended.txt");      //open the new file to be written to

								   ///if both files are open
	if (inf1.is_open() && inf2.is_open()) {

		//while the file still has data to be read
		while (!inf1.eof()) {
			inf1 >> hold;           //read an integer
			out << hold << " ";    //write it to file
		}

		//while the second file has data to be read
		while (!inf2.eof()) {
			inf2 >> hold;            //read
			out << hold << " ";     //write
		}

		//close both files
		inf1.close();
		inf2.close();
	}
}

//Writes the passed array to the passed file name
void Write(int arr[], int len, string name) {


	ofstream out;

	remove(name.c_str()); //remove the file if it exists
	out.open(name.c_str()); //open the file

					//write the array to the file one element at a time
	for (int i = 0; i < len; i++) {
		out << arr[i] << " ";
	}

	out.close(); //close the file
}

//Merges two completely sorted files together in a new file
void MergeFiles(string f1, string f2, string out) {

	int h1, h2;  //used to hold integers

				 //Open the files
	ifstream in(f1.c_str());
	ifstream in2(f2.c_str());
	ofstream outf(out.c_str());

	if (in) {
		in >> h1; //grab an integer
	}
	if (in2) {
		in2 >> h2; //grab a second integer
	}

	//while either file is still open
	while (in || in2) {

		//if both sre still open
		if (in && in2) {

			//if the second int is less than the first
			if (h2 <= h1) {
				outf << h2 << " ";  //output int
				in2 >> h2;          //read a new one in
			}
			else {
				outf << h1 << " ";  //output
				in >> h1;           //read in a new int
			}
		}
		//if one of the files is done
		else {
			if (!in) {
				outf << h2 << " "; //output the second files integers
			}
			else if (!in2) {
				outf << h1 << " "; //output the first files integers
			}


			//get an int from whichever is still open
			if (in) {
				in >> h1;
			}
			else if (in2) {
				in2 >> h2;
			}
		}
	}
}
