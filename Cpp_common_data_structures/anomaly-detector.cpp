#include <iostream>
#include <list>
using namespace std;

class SensorData
{
private:
	list<int>sensorReadings{ };

public:
	void add_reading(double reading) {
		sensorReadings.push_back(reading);
	}


	void print_data() {
		if (!sensorReadings.empty()) {
			for (auto& reading : sensorReadings) {
				cout << reading << " ";
			}

			cout << endl;
		}
		else {
			cout << "There are no sensor readings." << endl;
		}
	}

	// solution-1
	/*
	void smooth_data() {
		if (sensorReadings.size() >= 2) {
			for (auto it = sensorReadings.begin(); it != sensorReadings.end(); it++) {
				if (it != sensorReadings.begin()) {
					if ((*it >= (*std::prev(it) * 2)) || (*it <= (*std::prev(it) / 2))) {
					  *it = *std::prev(it);
					}
				}
			}
		}
	}
	*/

	// solution-2
	void smooth_data() {
		auto prev = sensorReadings.begin();
		auto current = prev;
		++current;

		while (current != sensorReadings.end()) {
			if ((*current >= (*prev * 2)) || (*current <= (*prev / 2))) {
				*current = *prev;
			}
			++prev;
			++current;
		}
	}
};

int main()
{
	SensorData sensorData;
	sensorData.add_reading(10.0);
	sensorData.add_reading(24.0);   // spike
	sensorData.add_reading(6.0);
	sensorData.add_reading(2.0);    // dip
	sensorData.add_reading(4.0);

	cout << "Sensor data: ";
	sensorData.print_data();

	cout << "Normalized sensor data: ";
	sensorData.smooth_data();
	sensorData.print_data();

	return 0;
}