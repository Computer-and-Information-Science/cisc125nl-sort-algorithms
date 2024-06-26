// srttest2.cpp - Sort test program #2
//
// Performs a sort on an array of random strings. Ensures that the array is,
//	in fact, sorted upon completion of calling the sort function. Also, reports
//	the elapsed time required to sort the array. Note, however, that this
//	program does not ensure that the values in the sorted array are the same
//	values as in the original unsorted array.

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "bubble.h"

void print (string a[], int n);
bool is_sorted (string a[], int n);
string rstring ();

int main () {

	string* s;		// Array of strings, allocated dynamically
	int size;		// Size of array s

	// Initialize random number generator
	srand(time(0));

	// Get size of array to be sorted
	cout << "Enter array size: ";
	cin >> size;

	// Set debug mode if <=96 elements. In debug mode, displays array
	//	before and after sorting.
	bool DEBUG = size <= 96;

	// Allocate array of int's.
	s = new string[size];

	// Fill array with random strings.
	for (int i = 0; i < size; i++)
		s[i] = rstring();

	// Show array, if DEBUG set.
	if (DEBUG) {
		cout << endl << "Before sort:" << endl;
		print(s, size);
		cout << endl;
	}

	// Sort the array.
	cout << "Sorting... ";
	cout.flush();
	clock_t t = clock();
	sort(s, size);
	t = clock() - t;

	// Show result.
	cout << (is_sorted(s, size) ? "success." : "FAILED") << endl;

	// Show array, if DEBUG set.
	if (DEBUG) {
		cout << endl << "After sort:" << endl;
		print(s, size);
		cout << endl;
	}

	// Show run time.
	cout << "Run time: " << fixed << setprecision(2) <<
		((double)t) / CLOCKS_PER_SEC << " seconds." << endl;

	// Deallocate array.
	delete [] s;

#ifdef _MSC_VER
	system("pause");
#endif
	return 0;
}

// print - Prints all values in an array, formatted for readability. Assumes
//	each value is fewer than 5 digits.
void print (string a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i && !(i % 8))
			cout << endl;
		cout << "  " << a[i];
	}
	cout << endl;
}

// is_sorted - Checks an array to see if the values are sorted.
bool is_sorted (string a[], int n) {
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			return false;
	return true;
}

// rstring - Generate a randon 6-character string.
string rstring () {
	string s;
	for (int i = 0; i < 6; i++)
		s += ('a' + rand() % 26);
	return s;
}
