// bubble.h - Bubble sort

#include <algorithm>

// pass - Performs a bubble pass on an array
template<typename T>
void pass(T a[], int n) {
	for (int i = 0; i < n - 1; i++)
		if (a[i + 1] < a[i])
			std::swap(a[i], a[i + 1]);
}

// sort - Performs a bubble sort on an array
template<typename T>
void sort(T a[], int n) {
	for (int i = 0; i < n - 1; i++)
		pass(a, n);
}
