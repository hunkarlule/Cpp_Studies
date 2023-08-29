// 08-challenge.cpp by Bill Weinman [bw.org]
// updated 2022-06-01
#include <format>
#include <iostream>

using std::format;
using std::cout;

/*
unsigned long factorial(unsigned long n) {
    auto result = n;
    while (n > 1) {
        result *= --n;
    }
    return result;
}
*/

// converting above factorial function to Template
template <typename T>
T factorial(T n) {
    auto result = n;
    while (n > 1) {
        result *= --n;
    }
    return result;
}

int main() {
    unsigned long n {5};
    cout << format("Factorial of {} is {}\n", n, factorial(n));

    int i{ 5 };
    cout << format("{}! is {}\n", i, factorial(i));

    long long unsigned int llui{ 15 };
    cout << format("{}! is {}\n", llui, factorial(llui));

    long double ld{ 25 };
    cout << format("{}! is {:-4.5}\n", ld, factorial(ld));
}
