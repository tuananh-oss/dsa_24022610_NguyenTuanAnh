#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
	vector<int> queue;

public:
	bool isEmpty() {
		return queue.empty();
	}

	void insert(int value) {
		if (queue.empty()) {
			queue.push_back(value);
			return;
		}
		auto it = queue.begin();
		while (it != queue.end() && *it > value) {
			++it;
		}

		queue.insert(it, value);
	}

	int delMax() {
		if (isEmpty()) {
			cout << "Priority Queue is empty!" << endl;
			return -1; 
		}
		int x = queue.front(); 
		queue.erase(queue.begin());
		return x;
	}

	int max(){
		if (isEmpty()) {
			cout << "Priority Queue is empty!" << endl;
			return -1;
		}
		return queue[0];
	}

	size_t getsize() {
 		return queue.size();
	}

	void print() {
		cout << "Priority Queue: ";
		for (size_t i = 0; i < queue.size(); i++) {
			cout << queue[i] << " ";
		}
		cout << endl;
	}
};