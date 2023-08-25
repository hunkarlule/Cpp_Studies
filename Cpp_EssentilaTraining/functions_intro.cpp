
#include <format>
#include <iostream>

using std::format;
using std::cout;

// for C+= a function and procedure is same.
// function consistes of: returnt type + function name+ paramter paranthesis + body.
void func() {
     cout << "this is func()\n";
}

// function with parameters.
void func1(int i, const char* s) {
    cout << format("i is {} and s is {}\n", i, s);
    cout << "this is func1()\n";
}

// function with return type.
int func2(int i, const char* s) {
    cout << format("i is {} and s is {}\n", i, s);
    cout << "this is func2()\n";

    return i * 2;
}


int main()
{
    cout << "this is main()\n";
    func();
    func1(42, "forty-two");

    auto x = func2(42, "forty-two");
    cout << format("x is {}\n", x);
}
