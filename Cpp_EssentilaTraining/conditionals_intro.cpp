// working.cpp by Bill Weinman [bw.org]
// updated 2022-05-21
#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    auto x = 42;
    auto y = 7;
    if (x > y) {
        cout << "condition is true\n";
    }
    cout << "after1\n";

    // X < y returns a boolen value: either true or false.
    if (x < y) { // ==, >=, <=,  >, !=  could be used i n this comparisons.
        cout << "condition is true\n";
    }
    else {
        cout << "condition is false\n";
    }
    cout << "after2\n";

    if (true) {  // or we can use directly false
        cout << "condition is true\n";
    }
    else {
        cout << "condition is false\n";
    }
    cout << "after3\n";


    if (0) {  // 0 is considered as false and other than anyhingg different from 0 is considered true
        cout << "condition is true\n";
    }
    else {
        cout << "condition is false\n";
    }
    cout << "after4\n";


    if ("") {  // emty string is non-zero. so, it is evaluated to true. because "empty-string is an actually in address in C++.
        cout << "condition is true\n";
    }
    else {
        cout << "condition is false\n";
    }
    cout << "after5\n";

    // as long as there is only one staement in if or else we can put them like this without suing curly braces but be careful about them.
    if (0) cout << "condition is true\n";
    else cout << "condition is false\n";
    cout << "after6\n";

    // ternary-conditional operator:
    // if  this evaluates to true ==> them s willl be "yes" otherwise s will bo "no".
    auto s = x > y ? " yes" : "no";
    cout << format("answer is {}\n", s);
}
