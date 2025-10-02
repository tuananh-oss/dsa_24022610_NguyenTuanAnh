#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct List {
	int size;
	int a[100];

	// Truy cập O(1)
	int search(int index) {
		return a[index];
	}

	// Thêm phần tử đầu O(n)
	void addFirst(int value) {
		for (int i = size; i > 0; i--) {
			a[i] = a[i - 1];
		}
		a[0] = value;
		size++;
	}

	// Thêm phần tử cuối O(1)
	void addLast(int value) {
		a[size] = value;
		size++;
	}

	// Thêm phần tử ở vị trí index O(n)
	void addpos(int index, int value) {
		for (int i = size; i > index; i--) {
			a[i] = a[i - 1];
		}
		a[index] = value;
		size++;
	}

	// Xóa phần tử đầu O(n)
	void removeFirst() {
		for (int i = 0; i < size - 1; i++) {
			a[i] = a[i + 1];
		}
		size--;
	}

	// Xóa phần tử cuối O(1)
	void removeLast() {
		size--;
	}

	// Xóa phần tử ở vị trí index O(n)
	void removepos(int index) {
		for (int i = index; i < size - 1; i++) {
			a[i] = a[i + 1];
		}
		size--;
	}

	// Duyệt xuôi danh sách O(n)
	void Print() {
		for (int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	// Duyệt ngược danh sách O(n)
	void reversePrint() {
		for (int i = size - 1; i >= 0; i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
};
#endif	
