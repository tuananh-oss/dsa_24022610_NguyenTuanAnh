#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

void BubbleSort(int a[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void InsertionSort(int a[], int n) {
	int index, new_number;
	for (int i = 1; i < n; i++) {
		index = i;
		new_number = a[i];
		while (index > 0 && a[index - 1] > new_number) {
			a[index] = a[index - 1];
			index--;
		}
		a[index] = new_number;
	}
}

bool binarySearch(int a[], int x, int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == a[mid])
			return true;
		else if (x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}

void Partition(int A[], int a, int b, int& k)
{
	int pivot = A[a];
	int left = a + 1;
	int right = b;
	do {
		while (left <= right && A[left] <= pivot) {
			left++;
		}
		while (left <= right && A[right] > pivot) {
			right--;
		}
		if (left < right)
		{
			swap(A[left], A[right]);
			left++;
			right--;
		}
	} while (left <= right);
	swap(A[a], A[right]);
	k = right;
}
void QuickSort(int A[], int a, int b)
{
	if (a < b)
	{
		int k;
		Partition(A, a, b, k);
        if (a <= k - 1) {
            QuickSort(A, a, k - 1);
		}
		if (k + 1 <= b) {
			QuickSort(A, k + 1, b);
		}
	}
}

void Merge(int A[], int a, int c, int b) {
	int i = a;
	int j = c + 1;
	int k = 0;
	int n = b - a + 1;
    int* arr = new int[n];
	while ((i < c + 1) && (j < b + 1)) {
		if (A[i] < A[j]) {
			arr[k++] = A[i++];
		}
		else {
			arr[k++] = A[j++];
		}
	}
	while (i < c + 1) {
		arr[k++] = A[i++];
	}
	while (j < b + 1) {
		arr[k++] = A[j++];
	}
	i = a;
	for (k = 0; k < n; k++) {
		A[i++] = arr[k];
	}
	delete[] arr;
}
void MergeSort(int A[], int a, int b)
{
	if (a < b)
	{
		int c = (a + b) / 2;
		MergeSort(A, a, c);
		MergeSort(A, c + 1, b);
		Merge(A, a, c, b);
	}
}

void heapify(int a[], int n, int i) {
	int largest = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	if (left < n && a[left] > a[largest]) {
		largest = left;
	}
	if (right < n && a[right] > a[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void HeapSort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}



