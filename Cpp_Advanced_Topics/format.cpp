#include <format>
#include <iostream>


using std::format;
using std::cout;

int main() {
	const char* helloMsg{ "Hello, World," };
	cout << format("{}\n", helloMsg);
}