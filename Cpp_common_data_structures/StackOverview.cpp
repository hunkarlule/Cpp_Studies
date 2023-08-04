#include <iostream>
#include <stack>

// stack is a last-in-first-out data structure.
// like a box(one end is closed) that you put the cards on top of each other.
// when you pick up a card from the box(whcihc will be top top card) it will be the last one that you put into.
using namespace std;

int main() {
	stack <int> intStack;

	// putting elemnet into stack
	intStack.push(5);
	intStack.push(10);
	intStack.push(15);
	intStack.push(20);

	// accessing top element in the satck.
	// note that top() function returns the top element from the stacj. But it does not remove it from the stack
	// in other words, top() function allows at to see what is the value of the top element.
	cout << "top element of the stack: " << intStack.top() << std::endl;  // rpints 20 because it is the top one(the last one that put into the stack)
	cout << "top element of the stack: " << intStack.top() << std::endl;  // still pints 20.

	// to actually remove an element from the stack use pop()
	// pop removes the top(the one last put in) element from the stack.
	// Note pop() returns nothing
	intStack.pop(); // removes 20 from the stack.


	cout << "top element of the stack: " << intStack.top() << std::endl;  // prints  15.

	// calling pop(0 or top() on a empty stack will throw an error.
	// it is good practice to check always if stack is epty before calling pop or top on a stack.
	stack <int> intStack2;
	//these two line will cause program crash because intStack2 is empty. If not then use top or pop. like below.
	//intStack2.pop();
	//intStack2.top();

	// checking is stack is mepty before doing top or pop operation.
	if (!intStack2.empty()) {
		intStack2.pop();
		intStack2.top();
	}


	// we can use while loop to travers a stack.
	// we removng elements from stack one-bye-one. until stack becomes "empty".
	//when while finished all elements will be removed and syak will be empty.
	while (!intStack.empty()) {
		cout << "removing element: " << intStack.top() << endl;
		intStack.pop();
	}

	if (intStack.empty()) {
		cout << "the stack is empty" << endl;
	}



	return 0;
}