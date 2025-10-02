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
		if (index == 0) {
			return head->data;
		}
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
	int removeFirst() {
		Node* temp = head;
		int x = temp->data;
		head = head->next;
		delete temp;
		return x;
	}

	// Xóa phần tử cuối O(n)
	void removeLast() {
		if (head == NULL) return;
		if (head->next == NULL) {
			int x = head->data;
			delete head;
			cout << x;
		}
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		int x = current->data;
		delete current;
		cout << x;
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

	bool empty() {
		return head == NULL;
	}

	int size() {
		int count = 0;
		while (head != NULL) {
			head = head->next;
			count++;
		}
		return count;
	}

	// Duyệt ngược danh sách O(n)

};

struct stack {
	LinkedList ds;

	bool isEmpty() {
		return ds.empty();
	}

	void push(int item) {
		ds.addLast(item);
	}

	int pop() {
		ds.removeLast();
	}

	int size() {
		ds.size();
	}

	int top() {
		ds.search(ds.size());
	}
};

struct queue {
	LinkedList ds;

	void enQueue(int item) {
		ds.addLast(item);
	}

	int deQueue() {
		return ds.removeFirst();
	}

	bool isEmpty() {
		return ds.empty();
	}

	int front() {
		return ds.search(0);
	}

	int size() {
		ds.size();
	}
};
#endif

