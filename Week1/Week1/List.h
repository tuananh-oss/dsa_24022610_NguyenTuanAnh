#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct List {
	int size;
	int a[100];

	List() {
		size = 0;
	}

	void set(int index, int value) {
		if (index >= 0 && index < size)
			a[index] = value;
	}
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
	int removeFirst() {
		int x = a[0];
		for (int i = 0; i < size - 1; i++) {
			a[i] = a[i + 1];
		}
		size--;
		return x;
	}

	// Xóa phần tử cuối O(1)
	int removeLast() {
		int x = a[size - 1]; 
		size--;
		return x;
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

struct stack {
	List ds;

	int n = ds.size - 1;

	bool isEmpty() {
		return ds.size == 0;
	}

	void push(int item) {
		ds.addLast(item);
	}

	int pop() {
		int x = ds.search(n);
		ds.removeLast();
		return x;
	}

	int top() {
		return ds.search(n);
	}

	int size() {
		return ds.size;
	}
};

struct queue {
	List ds;

	bool isEmpty() {
		return ds.size == 0;
	}

	void enQueue(int item) {
		ds.addLast(item);
	}

	int deQueue() {
		return ds.removeFirst();
	}

	int front() {
		return ds.search(0);
	}

	int size() {
		return ds.size;
	}
};
#endif	
