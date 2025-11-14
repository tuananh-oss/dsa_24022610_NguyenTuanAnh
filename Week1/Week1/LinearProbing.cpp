#include <iostream>
#include <vector>
using namespace std;

struct Entry {
    int key;
    int value;
    bool occupied;
    bool deleted;

    Entry() {
        occupied = false;
        deleted = false;
    }
};

class HashTableLP {
private:
    vector<Entry> table;
    int size;

    int hashFunc(int key) {
        return key % size;
    }

public:
    HashTableLP(int s) {
        size = s;              
        table.resize(size);    
    }


    void insert(int key, int value) {
        int index = hashFunc(key);
        int start = index;

        while (true) {
            if (table[index].occupied && table[index].key == key) {
                table[index].value = value;
                return;
            }
            if (!table[index].occupied || table[index].deleted) {
                table[index].key = key;
                table[index].value = value;
                table[index].occupied = true;
                table[index].deleted = false;
                return;
            }
            index = (index + 1) % size;
            if (index == start) {
				cout << "Bang day, khong the chen!" << endl;
                return;
            }
        }
    }

    bool search(int key) {
        int index = hashFunc(key);
        int start = index;

        while (true) {
            if (table[index].occupied && table[index].key == key) {
                cout << "Tim thay key " << key
                    << " voi value = " << table[index].value << endl;
                return true;
            }
            if (!table[index].occupied && !table[index].deleted) {
                cout << "Khong tim thay key " << key << endl;
                return false;
            }
            index = (index + 1) % size;
            if (index == start) return false;
        }
    }

    void removeKey(int key) {
        int index = hashFunc(key);
        int start = index;

        while (true) {
            if (!table[index].occupied && !table[index].deleted) break;
            if (table[index].occupied && table[index].key == key) {
                table[index].occupied = false;
                table[index].deleted = true;
                cout << "Da xoa key " << key << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        cout << "Khong tim thay key de xoa" << endl;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "] ";
            if (table[i].occupied)
                cout << table[i].key << ":" << table[i].value;
            else if (table[i].deleted)
                cout << "DELETED";
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};




