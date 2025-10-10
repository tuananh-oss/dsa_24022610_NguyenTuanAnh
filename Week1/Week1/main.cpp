#include <iostream>
#include <vector>
#include "BinaryHeap.cpp"
#include "PriorityQueue.cpp"
using namespace std;
int main() {
    cout << "HEAP" << endl;
    BinaryHeap h;
    h.insert(10);
    h.insert(30);
    h.insert(20);
    h.insert(5);
    h.insert(40);
    h.print();

    cout << h.delMax() << endl;
    h.print();
    cout << h.max() << endl;

    cout << h.getsize() << endl;

    cout << "PRIORITY QUEUE" << endl;
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(12);
    pq.insert(6);
    pq.insert(26);
    pq.print();
    
    if (!pq.isEmpty()) {
        cout << pq.delMax() << endl;
    }
    pq.print();

    cout << pq.max() << endl;
    pq.print();

    cout<< pq.getsize();

}