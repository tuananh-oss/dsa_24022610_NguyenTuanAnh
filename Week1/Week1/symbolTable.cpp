#include <iostream>
#include <string>
#include "List.h"

using namespace std;

struct Node {
string key;
int value;
Node* next;

Node(string Key, int Value) {
	key = Key;
	value = Value;
	next = nullptr;
}
}; 

class SymbolTable {
private:
Node* head;
public:
SymbolTable() {
	head = nullptr;
}
void insert(string key, int value) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->key == key) {
			temp->value = value;
			return; 
		}
		temp = temp->next;
	}
	Node* newNode = new Node(key, value);
	newNode->next = head;
	head = newNode;
}
int lookup(string key) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->key == key) {
			return temp->value;
		}
		temp = temp->next;
	}
	return -1;
}
void remove(string key) {
	Node* temp = head;
	Node* prev = nullptr;
	while (temp != nullptr) {
		if (temp->key == key) {
			if (prev == nullptr) {
				head = temp->next;
			}
			else {
				prev->next = temp->next;
			}
			delete temp;
			return;
		}
		prev = temp;
		temp = temp->next;
	}
}
void print() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->key << ": " << temp->value << " ";
		temp = temp->next;
	}
}
};

class ST {
private:
	List values;
	char keys[100];
	int size;
public:
	ST() {
		size = 0; 
	}
	void insert(char key, int value) {
		int posKey = lookup(key);
		if (posKey == -1) {
			values.addLast(value);
			keys[size] = key;
			size++;
		}
		else {
			values.addLast(value);
			if (size >= 100) {
				throw std::overflow_error("Symbol table is full.");
			}
            keys[size] = key;
			size++;
		}
	}

	int lookup(char key) {
		for (int i = 0; i < size; i++) {
			if (keys[i] == key) {
				return values.a[i];
			}
		}
		return -1;
	}
	
	void remove(char key) {
		for (int i = 0; i < size; i++) {
			if (keys[i] == key) {
				values.removepos(i);
				for (int j = i; j < size - 1; j++) {
					keys[j] = keys[j + 1];
				}
				size--;
				return;
			}
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << keys[i] << ": " << values.a[i] << " ";
		}
		cout << flush;
	}
};