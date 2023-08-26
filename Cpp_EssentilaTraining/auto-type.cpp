// auto-type.cpp by Bill Weinman [bw.org]
// updated 2022-05-25
#include <format>
#include <iostream>
#include <typeinfo>

using std::format;
using std::cout;
 
// auto type intorduced with C++11

int main() {
    std::string s {"This is a string"};

    // here we initilized x with as and we used auto to determine the type of x
    // so we do not need to write the type of x explisitly. compiler will deduce it from the type of s.
    auto x = s; 
    std::string x1 = s;

    cout << format("x is {}\n", x);
    cout << format("x1 is {}\n", x1);
    cout << format("type of x is {}\n", typeid(x).name());  // typeid(x).name():  this gives us internal reprsentation  of what the type is.

    // this is not allowed. and compiler error.
    // becuase auto needs an initilizer so compuler can determine/derive tthe tpye of x2 from it.
        //auto x2; 

    // we can do both below with auto
    // both x3 and x4 isnitilizaed with 5.
    // but becuae there is no ddanger of narrtoing when using auto. So with auto, initilizing with = is preferred.
    auto x3 = 5; // more preferred.
    auto x4{ 5 };
}
