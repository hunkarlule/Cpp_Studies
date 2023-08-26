
#include <format>
#include <iostream>

using std::format;
using std::cout;



int main() {

	// a flag to track if a value is prime of not.
	bool is_prime{ false };

	// outer loop for prime candidates 2-99
	for (auto i = 2; i < 100; ++i) {
		is_prime = true;
		// test candidate for being prime or not.
		for (auto j = 2; j <= i / 2; ++j) {
			if (i % j == 0) {
				is_prime = false;
				break; // either use this one  or use the for condition like this  for (auto j = 2; j <= i / 2 && is_prime; ++j)
			}
		}

		// print if it's prime
		if (is_prime) {
			cout << format("{} ", i);
		}
	}
	cout << "\n";

	return 0;
}
