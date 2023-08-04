#include <iostream>
#include <queue>

// quese is a first-in-first-out data structure.
// So when you reach an element in the queue, it will be the element that added first to the queue.
// Think the queue like a  line-up(queue) of people at a chec-out in a store. The first person that in the line-up,means he/she added/joind the line-up
// will be the first one to be served adn removed from the line-up.
// or cars going into a tunnel(tunnel represents the queue). So first car that enters the tunnel will be the first that leaves the tunnel.
//so in queue, the elements are added/pushed to the back and removed from the front
using namespace std;

int main() {

	queue<int> intQueue;
	int arr[] = { 5, 10, 15, 20 };
	const int arrayLength = sizeof(arr) / sizeof(arr[0]);

	// here pusing elements from the arrat to a queue
	// push() puts the elements into queue from the back
	// this means when for each finishes the queue will be like this:  (this is back of queue)20 -- 15 -- 10 -- 5(this is front of queue)
	for (int i = 0; i < arrayLength; i++) {
		intQueue.push(arr[i]);
	}

	// front() returns the element frony of the queue
	// notes that front() does not remove the element. It onle returns the value of the elenet at the fron og the queue.
	// in other words fornt() porvides us to see what is in the front of the queue.
	cout << intQueue.front() << endl; // prints 5
	cout << intQueue.front() << endl; // still prints 5



	// pop() removes the element from front of the queue(tham means removes the first element from fromt of the queue)
	// note that pop() returns nothing
	cout << intQueue.front() << endl; // prints 5
	intQueue.pop(); // this will remove 5 from the queue
	cout << intQueue.front() << endl; // now prints 10


	// note that calling front() or pop() methods on an empty queue  causes  a program crash.
	// So always schek if queue is emoty before calling front() and pop() methods
	queue<int> intQueue2;
	// this to lines are causing program crash pecuse intQueue2 is empty.
	//cout << intQueue2.front() << endl;
	//intQueue2.pop();

	// correct usage

	if (!intQueue2.empty()) {
		cout << intQueue2.front() << endl;
		intQueue2.pop();
	}
	else {
		cout << "queue is empty" << endl;
	}

	// use while loop to iterate over a queue until it becomes emty.

	while (!intQueue.empty()) {
		cout << "removing from elements: " << intQueue.front() << endl;
		intQueue.pop();
	}

	if (intQueue.empty()) {
		cout << "queue is empty" << endl;
	}
	else {
		cout << "there are some elements in the queue." << endl;
	}





	return 0;
}