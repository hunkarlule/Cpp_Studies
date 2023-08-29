
#include <format>
#include <iostream>

using std::format;
using std::cout;

// in C++, classes are based on structs. Indeed you can create a class using either "class" or "struct"
// keyword. 
// Struct and class are identical only with one difference. In Struct. members is "default public access"
// and in class members are default private access.

struct A {
    //private : // if we put this keywor here. Struct B will be exactly same with Class B A.
    int ia{};
    int ib{};
    int ic{};
};

// Here  class B is completely same with struct A. the differencei s taht we used class keyword when defining it.
class B {
//public: // if we put this keywor here. Class B will be exactly same with Struct A.
    int ia{};
    int ib{};
    int ic{};
};

int main() {
    // Because struct has default public we can initilize it like that and acess its member using dot operator.
    A o1{ 47, 73, 103 };
    cout << format("ia: {}, ib: {}, ic: {}\n", o1.ia, o1.ib, o1.ic); //. is calld dot operator(element selection oeprator or member operator)
    
    cout << format("===================================\n");

    // here we getting compiler eror becuse for class memebrs are default privet. so we can not acess them outside of class directly.
        //B o2{ 47, 73, 103 };
        //cout << format("ia: {}, ib: {}, ic: {}\n", o1.ia, o1.ib, o1.ic); //. is calld dot operator(element selection oeprator or member operator)
        //return 0;
}
