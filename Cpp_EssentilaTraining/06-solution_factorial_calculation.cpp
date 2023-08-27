// 06-solution.cpp by Bill Weinman [bw.org]
// updated 2022-06-01
#include <format>
#include <iostream>

using std::format;
using std::cout;

unsigned long int factorial(unsigned long int n) {
    if (n < 2) return 1;
    auto result = 1;

    for (auto i = n; i > 1; --i) {
        result *= i;
    }

    return result;
}

//solution-2
        //unsigned long factorial(unsigned long n) {
        //    auto result = n;
        //    while (n > 1) {
        //        result *= --n;
        //    }
        //    return result;
        //}

int main() {
    unsigned long n {5};
    cout << format("Factorial of {} is {}\n", n, factorial(n));
}
