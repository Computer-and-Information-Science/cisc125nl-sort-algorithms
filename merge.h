// merge.h - Merge sort

// mergesort - Perform a merge sort on a portion of an array
template <typename T>
void mergesort (T a[], int first, int last) {

	int size = last - first + 1;
	if (size <= 1)
		return;

	int mid = (first + last) / 2;
	mergesort(a, first, mid);
	mergesort(a, mid + 1, last);

	T* tmp = new T[size];

	int i = first;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= last)
		tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= last)
		tmp[k++] = a[j++];

	for (int i = first, k = 0; k < size; i++, k++)
		a[i] = tmp[k];

	delete [] tmp;
}

// merge - Perform a merge sort on an array
template <typename T>
void sort (T a[], int n) { mergesort(a, 0, n - 1); }
