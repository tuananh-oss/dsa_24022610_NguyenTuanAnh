#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
	int value;
public:
	LinkedList() {
		head = nullptr;
		value = 0;
	}

	// Truy cập O(n)
	int search(int index) {
		Node* current = head;
		for (int i = 0; i < index; i++) {
			if (current == NULL) return -1;
			current = current->next;
		}
		return current->data;
	}

	// Thêm phần tử đầu O(1)
	void addFirst(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}

	// Thêm phần tử cuối O(n)
	void addLast(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

	// Thêm phần tử ở vị trí index O(n)
	void addpos(int index, int value) {
		if (index == 0) {
			addFirst(value);
			return;
		}
		Node* newNode = new Node();
		newNode->data = value;
		Node* current = head;
		if (current == NULL) {
			head = newNode;
			return;
		}
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}


	// Xóa phần tử đầu O(1)
	void removeFirst() {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	// Xóa phần tử cuối O(n)
	void removeLast() {
		if (head == NULL) return;
		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		Node* current = head;
		while (current->next->next != NULL) {
			current = current->next;
		}
		delete current->next;
		current->next = NULL;
	}

	// Xóa phần tử ở vị trí index O(n)
	void removepos(int index) {
		if (index == 0) {
			removeFirst();
			return;
		}
		Node* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}

	// Duyệt xuôi danh sách O(n)
	void Print() {
		Node* current = head;
		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	// Duyệt ngược danh sách O(n)

};

#endif

