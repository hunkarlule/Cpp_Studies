#include <iostream>
#include <queue>
using namespace std;

class CallCenter {
private:
	queue<int> callsQueue;

public:
	void receive_call(const int callID) {
		cout << "Call received with ID: " << callID << ". Adding call to the queue." << endl;
		callsQueue.push(callID);
	}

	int process_call() {
		if (callsQueue.empty()) {
			cout << "No calls is waiting in the queue to process." << endl;
			return -1;
		}

		int callToProcess = callsQueue.front();
		cout << "Processing call: " << callToProcess << endl;
		callsQueue.pop();

		return callToProcess;
	}
};

int main()
{
	CallCenter center; // Instantiate CallCenter object

	// Receiving some calls
	center.receive_call(101);
	center.receive_call(102);
	center.receive_call(103);

	// Processing all calls
	int call_id;
	while ((call_id = center.process_call()) != -1) {
		std::cout << "Successfully processed call: " << call_id << std::endl;
	}

	return 0;
}
