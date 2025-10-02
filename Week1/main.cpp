#include <iostream>
#include "LinkedList.h"
#include "List.h"
using namespace std;
int main() {
	cout << "Linked List" << endl;
	LinkedList list1;
	Node* head = new Node();
	list1.addFirst(1);
	list1.addFirst(2);
	list1.addFirst(3);
	list1.Print();
	list1.addpos(1, 4);
	list1.Print();
	list1.removeFirst();
	list1.Print();
	list1.removeLast();
	list1.Print();
	cout << endl;

	cout << "List" << endl;
	List list2;
	list2.size = 0;
	list2.addLast(1);
	list2.addLast(2);
	list2.addLast(3);
	list2.Print();
	list2.addFirst(0);
	list2.Print();
	list2.addpos(2, 5);
	list2.Print();
	list2.removeFirst();
	list2.Print();
	list2.removeLast();
	list2.Print();
	list2.removepos(1);
	list2.Print();
	cout << list2.search(1) << endl;
	list2.reversePrint();
	return 0;
}