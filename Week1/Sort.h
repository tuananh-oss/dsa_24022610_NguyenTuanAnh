#pragma once
#ifndef SORT_H
#define SORT_H

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
#endif
