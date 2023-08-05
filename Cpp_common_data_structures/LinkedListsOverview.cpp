#include <iostream>
#include <list>

using namespace std;
// linked list conssists of nodes. Each node holda a valua and alos one/two pointers to point to other nodes.
// First node in the linked list is called head and last node is called tail.
// there are two types of list:
//-- single linked list: Each node holds a value also a pointer to the next node.
//-- double linked list Each node holds a value also a pointer to the next node and the previous node
// single linked list is going one direction(means you traverse this list only in one direction)
// Here is a representation of single linked list. see last node not pointing anywhere. It is pointer value is null.
//   n1(head node)        n2               n3            n4(tail node)  
// (1, a_of_n2) --> (2, a_of_n3) --> (3, a_of_n4) --> (4, null)


// double linked list is going both direction(means you traverse this list both forward and backward.)
// Here is a representation of single linked list. see last node not pointing anywhere. It is pointer value is null.
//   n1(head node)                   n2                       n3                 n4(tail node)  
// (1, a_of_n2, null) <--> (2, a_of_n3, a_of_n1) <--> (3, a_of_n4, a_of_n2) <--> (4, null, a_of_n3)
int main() {
	list<int> intList{ 1,2,3,4,5 };

	intList.push_back(6); // inserts element at the end of the list. now this is tail node in the list
	intList.push_front(0); // inserts an element to at the beginning of the list/ now, this is the head node.


	// we can also use iteretors to add elements to the list:
	// iterators are pointer-like object that points to an element in the list.

	// here we initilized/defined an iterator using begin func. this iterator points to the first element of the container.
	auto it = intList.begin();
	cout << *it << endl; // prints 0
	cout << *it << endl; // prints 0

	// we can use pointer arithmetic with iterators.
	it++; // now iterator points to 2nd element in the list.
	cout << *it << endl; // prints 1

	// we can advance iterator with advance function. so it will point to another element.
	std::advance(it, 2); //now we moved iterator 2 stspes. So it point the 4th element.
	cout << *it << endl; // prints 3

	// we can insert element at any place in the list without nay burden(o(n)) becuase we only need to cahnge the pointers of the node.
	// here insert function adding an element to list where the iterator is pointing(in this case it is poiniting the 4th element of the list)
	cout << *it << endl; // as a proof 3 is the 4th element. // prints 3
	intList.insert(it, -1); // here we added -1 as the 4th element.

	// as a proof -1 is the 4th element now.
	cout << " traversing list in forward direction." << endl;

	for (auto& element : intList) {
		cout << element << " ";
	}
	cout << endl;

	// we can also travers list using iterators
	for (auto it = intList.begin(); it != intList.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;


	// remove first and last elements from the list
	intList.pop_front(); // removed the first element(0). Now 1 is the firts element(head node)
	for (auto& element : intList) {
		cout << element << " ";
	}
	cout << endl;
	
	intList.pop_back();  // removed the last element(6). Now 5 is the firts element(tail node)
	for (auto& element : intList) {
		cout << element << " ";
	}
	cout << endl;

	// we can revers the list by using revrese() method.

	intList.reverse();  // reversed the list. before reverse: 1 2 - 1 3 4 5. Afet reverse: 5 4 3 - 1 2 1.
	for (auto& element : intList) {
		cout << element << " ";
	}
	cout << endl;

	// we can sort  list by sort() method.

	intList.sort();  // reversed the list. before sorting: 5 4 3 - 1 2 1. Afet sorting: -1 1 2 3 4 5.
	for (auto& element : intList) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}