#include <iostream>
#include <vector>
#include "symbolTable.cpp"
using namespace std;
int main() {
	cout << "Symbol Table by Linked List" << endl;
	SymbolTable st;
	st.insert("a", 1);
	st.insert("b", 2);
	st.insert("c", 3);
	st.insert("d", 5);
	st.print();
	cout << "\nLookup 'c': " << st.lookup("c") << endl;
	st.remove("b");
	st.print();

	cout << "\nSymbol Table by Array" << endl;
	ST st1;
	st1.insert('a', 10);
	st1.insert('b', 20);
	st1.insert('c', 30);
	st1.print();
	st1.insert('f', 60);
	cout << "\nLookup 'a': " << st1.lookup('c') << endl;
	st1.remove('b');
	st1.print();



}