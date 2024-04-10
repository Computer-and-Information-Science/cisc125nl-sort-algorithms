// selection.h - Selection sort

#include <algorithm>

// findmax - Finds the index of the maximum valued element in an array
template <typename T>
int findmax (T a[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > a[max])
			max = i;
	return max;
}

// sort - Performs (a variation of) a selection sort on an array
template <typename T>
void sort (T a[], int n) {
	for (int size = n; size > 1; size--) {
		int max = findmax(a, size);
		std::swap(a[max], a[size - 1]);
	}
}
