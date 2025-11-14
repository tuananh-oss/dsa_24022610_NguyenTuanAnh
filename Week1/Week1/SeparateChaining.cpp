#include <iostream>
#include <cmath> 

using namespace std;

struct HashNode {
    int key;
    int value;
    HashNode* next; 
    HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
};

class SeparateChaining {
private:
    int capacity; 

    HashNode** table;

    int HashFunc(int key) {
        return abs(key) % capacity;
    }

public:
    SeparateChaining(int size) {
        this->capacity = size;
        table = new HashNode * [capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = nullptr;
        }
    }
    ~SeparateChaining() {
        for (int i = 0; i < capacity; ++i) {
            HashNode* entry = table[i];
            while (entry != nullptr) {
                HashNode* nodeToDelete = entry;
                entry = entry->next;
                delete nodeToDelete; 
            }
        }
        delete[] table;
    }

    void insert(int key, int value) {
        int index = HashFunc(key);
        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        HashNode* newNode = new HashNode(key, value);

        newNode->next = table[index];
        table[index] = newNode;    
    }

    void remove(int key) {
        int index = HashFunc(key);

        HashNode* current = table[index];
        HashNode* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            return; 
        }
        if (prev == nullptr) {
            table[index] = current->next; 
        }
        else {
            prev->next = current->next;
        }

        delete current;
    }
    int* search(int key) {
        int index = HashFunc(key);

        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return &(current->value);
            }
            current = current->next;
        }
        return nullptr;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            cout << "[" << i << "] ";
            HashNode* current = table[i];
            if (current == nullptr) {
                cout << "EMPTY";
            }
            else {
                while (current != nullptr) {
                    cout << current->key << ":" << current->value;
                    if (current->next != nullptr) {
                        cout << " -> ";
                    }
                    current = current->next;
                }
            }

            cout << endl;
        }
    }
};

int main() {
	SeparateChaining hashTable(5);
	hashTable.insert(1, 100);
	hashTable.insert(2, 200);
	hashTable.insert(3, 300);
	hashTable.insert(6, 600);
	hashTable.insert(11, 1100);
	hashTable.print();
	int* value = hashTable.search(3);
	if (value) {
		cout << "Tim thay key 3 voi value = " << *value << endl;
	}
	else {
		cout << "Khong tim thay key 3" << endl;
	}
	hashTable.remove(2);
	cout << "Sau khi xoa key 2:" << endl;
	hashTable.print();
	return 0;
}