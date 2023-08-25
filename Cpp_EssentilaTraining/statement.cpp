// statement.cpp by Bill Weinman [bw.org]
// updated 2022-05-19
#include <format>
#include <iostream>

using std::cout;
using std::format;


// statement is a unit of code. ends with a "semi-colon". it is treted a nuit of execution.
// an expresiion is anything that returns a value. whether or not the value is used.
// an expresiion can be a part of the staemnet or may be an entire statement.

int main() {
    int x;
    x = 42; // this is an expression(x =42). even 42 by itels f is an expression. but line also is astaement because ending with ;.
    // (12 + 14) -- is an expression
    // 42 * (12 + 14) -- is an expression
    // x = 42 * (12 + 14) -- is an expression
    // x = 42 * (12 + 14); -- is an statement.

    x = 42 * (12 + 14);
    auto str = format("x is {}\n", x);
    cout << str;
}
