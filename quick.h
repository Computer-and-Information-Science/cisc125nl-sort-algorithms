//template <typename T>
//void swap (T& a, T& b) { T tmp = a; a = b; b = tmp; }

template <typename T>
int partition (T a[], int first, int last, int pivot) {
	T value = a[pivot];
	swap(a[pivot], a[last]);
	pivot = first;
	for (int i = first; i < last; i++) {
		if (a[i] < value) {
			swap(a[i], a[pivot]);
			pivot++;
		}
	}
	swap(a[pivot], a[last]);
	return pivot;
}

template <typename T>
void quicksort (T a[], int first, int last) {
	if (first >= last)
		return;

	int pivot = (first + last) / 2;
	pivot = partition(a, first, last, pivot);
	quicksort(a, first, pivot);
	quicksort(a, pivot + 1, last);
}

template <typename T>
void sort (T a[], int n) { quicksort(a, 0, n - 1); }
