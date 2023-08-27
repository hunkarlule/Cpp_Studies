
#include <format>
#include <iostream>

using std::format;
using std::cout;


// a recursive funcsion is a function that refers to istels in its body. In other, words the function calls itself in its body.
// for every recursive call of the fantion memory allocated is for parameters, variables in the function, retunr values etc. and all of this is in the stack. this could be very costly if the values/objects are large.
// therefore useing normal loops could be more effcient in some cases.
unsigned long int factorial(unsigned long int n) {
    if (n < 2) return 1; // this condition is important because this end the recursive loop.
    return n * factorial(n - 1);
}

int main() {
    unsigned long n {5};
    cout << format("Factorial of {} is {}\n", n, factorial(n));
}
