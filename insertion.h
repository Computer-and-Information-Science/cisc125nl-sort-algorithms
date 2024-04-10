// insertion.h - Insertion sort

#include <algorithm>

// sort - Performs an insertion sort
template <typename T>
void sort (T a[], int n) {
	for (int i = 1; i < n; i++)
		for (int j = i; j && a[j] < a[j - 1]; j--)
			std::swap(a[j], a[j - 1]);
}
