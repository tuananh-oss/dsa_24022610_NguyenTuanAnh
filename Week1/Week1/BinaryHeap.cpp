#include <iostream>
#include <vector>
using namespace std;

class BinaryHeap {
private:
	vector<int> heap;

public:

	bool isEmpty() {
		return heap.size() == 0;
	}

	void swim(int k) {
		while (k > 0) {
			int parent = (k - 1) / 2;
			if (heap[k] > heap[parent]) {  
				swap(heap[k], heap[parent]);
				k = parent;
			}
			else break;
		}
	}

	void sink(int k) {
		int n = heap.size();
		while (true) {
			int left = 2 * k + 1;
			int right = 2 * k + 2;
			int largest = k;

			if (left < n && heap[left] > heap[largest])
				largest = left;
			if (right < n && heap[right] > heap[largest])
				largest = right;

			if (largest == k) break;
			else {
				swap(heap[k], heap[largest]);
				k = largest;
			}
		}
	}
	void insert(int value) {
		if (heap.size() == 0) {
			heap.push_back(value);
			return;
		}
		else {
			heap.push_back(value);
			size_t i = heap.size() - 1;
			swim(int(i));
		}
	}

	int delMax() {
		int i = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		if (!isEmpty()) sink(0);
		return i;
	}

	int max() {
		return heap[0];
	}

	size_t getsize() {
		 return heap.size();
	}

	void print() {
		cout << "Binary Heap: ";
		for (size_t i = 0; i < heap.size(); i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}
};