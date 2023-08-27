// working.cpp by Bill Weinman [bw.org]
// updated 2022-05-21
#include <format>
#include <iostream>

using std::format;
using std::cout;


// here func accepts an integer. so when func is called the values will be pass it "by value". 
void func(int a) {
    a++;
    cout << format("in func(0 ==> value a is {}\n", a);
}


// here func accepts an integer. so when func is called the values will be pass it "by value". 
void func1(int* p) {
    ++(*p);
    cout << format("in func1 ==> value *p is {}\n", *p);
}

// we can  also implenet "call-by_reference" using reference types.
// when a value is passed to func2. Then then there is no  copy made to r. becuae  r is a reference. So, r basically becomes anew name for the value passed to func2. 
// so when we cahnge the r, indeed we are changing the value that is passed  becuae r is aonly a nick-name for taht value. 
void func2(int& r) {
    ++r;
    cout << format("in func1 ==> value r is {}\n", r);
}


// It is better to implement call-by-reference using pointers.

int main() {
    cout << "Hello, World!\n";
    // argument is passed to the functions by value. that means when you pass a value to a function a copy iscreated and that is given to the function.
    // if you change that value in the function caller's copy will remain unchanged.
    int a = 5;
    cout <<  format("a is {}\n", a);
    // this is like func(int a =5) ==> that means when function is called the paramter of the function is initilized with the value that passed to it
    // that means it is completely a separate copy  from that passed value. This is called  "passing by value"
    // os in function we incremented it but  this does not affect the caller's copy(a  defined in main).
    func(a); 
    cout << format("a is {}\n", a);

    cout << format("=================================\n");

    // alternative to "bass-by-value" is "pass-by-reference". this is implemented by using pointers.
    a = 5;
    cout << format("a is {}\n", a);
    // Here we pass address of a to func1. Indeed, this is still a call-by-value. But we passing a address to func1. Because p is a pointer that makes this case "call-by-reference" Pointer p in func1 is still pointing to a(defined in main)
    //so  in function we incremented it wiht ++(*p) == > this indeed increments the value a a.
    func1(&a);
    cout << format("a is {}\n", a);


    cout << format("=================================\n");

    // alternative to "bass-by-value" is "pass-by-reference". this is also implemented by using reference.
    a = 5;
    cout << format("a is {}\n", a);
    // Here we pass a to func2. The r in func2 will become a new name for a. So wehen we canhge  the valu of r in func2 the a will be changing. this is called call-by-reference.
    // but here there is nothing that shoing us that the func2 is accpeting a reference(unless we see definition/decleration of func2). Therefore, this could be dangerous. Be careful about it.
    func2(a);
    cout << format("a is {}\n", a);


}
