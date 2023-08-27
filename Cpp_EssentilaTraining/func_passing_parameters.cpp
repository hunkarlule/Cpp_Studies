// func.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <format>
#include <iostream>
#include <string>

using std::format;
using std::cout;

// why pass-by-reference vs pass-by-value is important? ==> internally values passed from/to a fucntion on a smll data structure called "stack". 
// "stack" is relatively small space and requires processing power to manage. Passing large values to a function requires copying large amounts of data on the stack.
// this is time consuming and also can cause stackoverflow(if data is really big) and crach your program.
// so, better choice will be using pointer or reference paccisng large values to a function. this way there will not be large copies on the stack.

void func(int a) {
    cout << format("a is {}\n", a);
}

// a function paramter can have default value.
void func1(int a = 73) {
    cout << format("a is {}\n", a);
}


// in C++, by default, variables is passed-by-value to the functios.
void func2(int a) {
    a = 72;
    cout << format("in func2, a is {}\n", a);
}


// we can use +pass-by-reference". To do that we can use references.
// here, func3 acccepts a int reference.So hwne func3 is called a(in func3) will be a new name for that variable that is passed to the func3.
//this could can have unintented results. Therfore, always  make the variables const when using references.
void func3(int& a) {  // void func3(const int& a) { ==> prefer this when using references.if we make const we can not cahnge the value.

    a = 72;
    cout << format("in func3, a is {}\n", a);
}


// another alternative for pass-by-reference is using pointers.
// here, func4 acccepts an int pointer.So when func4 is called a(in func3) will be a pointer to the variable that is passed to the func4. in other words apointer in func4)  will point to the value that is passed.
void func4(int* a) { // void func4 (const int* a) { ==> we can also make this. if we make it const then we cannot change the value.
    *a = 72; // we cahnged the calue that a is pointing.
    cout << format("in func4, a is {}\n", *a);
}


void func5(const std::string& s) {
    cout << format("in func5 value is: {}\n", s);
}



int main() {

    int a{ 47 };

    cout << "this is main()\n";
    func(47);

    cout << format("==============================\n");

    func1();
    func1(47);

    cout << format("==============================\n");

    // see that we changed the value of a in func2. but after that function call value of a in main is still same. becuase
    // when func2 is called with a func2(a). a copy of a is creatd and that is passed to fuc2. this is called pass-by-value.
    // in other words, the value a in function is copletely seperate from the one that is passecto it.
    // when function is called, the varibale a(from main) is copied to a new variable(in func2) on a small data structure called "stack".
    cout << format("before func2 is called, a is {}\n", a);
    func2(a);
    cout << format("after func2 is called, a is {}\n", a);


    cout << format("==============================\n");
    a = 47;

    // see that we changed the value of a in func3. this is affected to value of a in main. this is called pass-by-reference.
    cout << format("before func3 is called, a is {}\n", a);
    func3(a);
    cout << format("after func3 is called, a is {}\n", a);


    cout << format("==============================\n");
    a = 47;

    // see that we changed the value of a in func4. this is affected to value of a in main. this is called pass-by-reference.
    cout << format("before func4 is called, a is {}\n", a);
    func4(&a); // here we passed the address of a because func4's paremeter is a int pointer.
    cout << format("after func4 is called, a is {}\n", a);
  

    cout << format("==============================\n");

    std::string s{ "this is a string." };
    // here when we called func5 with s, s is not copied to paramater s in func5. Because parameter s is a int reference. So, this is saved us to copiyng whole string to s in the stack.
    // assume that instead of a smalls string, s was really a big object. So, if we passed-by-value istead of passed-by-reference. that big object would be copied to stack. this would be very costly and even can couse stack-overflow and crach the problem.
    // however, passing-by reference, this ensured that all of data ins not copied to the new variable on the stack. Istead, it will be used in its origilan location through he reference.
    cout << format("before func5 is called, s is: {}\n", s);
    func5(s); 
    cout << format("after func5 is called, s is: {}\n", s);

    return 0;
}


