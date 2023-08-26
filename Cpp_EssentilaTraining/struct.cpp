// struct.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
#include <format>
#include <iostream>

using std::format;
using std::cout;


// is a good vay to collec and represent spearte variables in a single container.
// S has 3 members
// S is an compound/aggregate type.
struct S {
    int i {};
    double d {};
    const char * s {};
};

int main() {
    S s1 { 3, 47.9, "string one" }; // type of s1 is struct S. here we initilized s1 using initializer list.
    cout << format("s1: {}, {}, {}\n", s1.i, s1.d, s1.s); //accessing the members of struct using dot(.) notation.
    // we can also assign new values to members using . notation.
    s1.d = 73.4;
    s1.i = 42;
    cout << format("s1: {}, {}, {}\n", s1.i, s1.d, s1.s); //accessing the members of struct using dot(.) notation.

    // here sp is a pointer(ist type struct S pointer) and it points to s1.
    auto* sp = &s1;
    //so we can access members of the array using pointr with ->(arrow/pointer member dereference) operator.
    cout << format("s1: {}, {}, {}\n", sp ->i, sp->d, sp->s); //accessing the members of struct using dot(.) notation.

    // or we can write members with new values using pointer
    sp ->d = 82.7;
    sp ->i = 48;
    cout << format("s1: {}, {}, {}\n", sp->i, sp->d, sp->s); //accessing the members of struct using dot(.) notation.
    cout << format("s1: {}, {}, {}\n", (*sp).i, (*sp).d, (*sp).s); //accessing the members of struct using dot(.) notation and pointers.
}
