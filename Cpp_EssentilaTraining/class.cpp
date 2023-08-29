
#include <format>
#include <iostream>

using std::format;
using std::cout;

// a very simple class
// a class is defulyprivate accessibility: means its members vannot be reached/used outside of the class.
// to open/make any class member(data-member, or member-function) to public(make it to be used outside of the class)
// we put them under public: keyword, like below.
class C1 {
    int c1val{}; // data-member(member variable)
public:
    void setvalue(int value);
    // to handle the error in line 67 we need to add const qualifier to getvalue function after the parameter paranthesis
    int getvalue() const; 

};

//function definitions
void C1::setvalue(int value) { c1val = value; } // function-member( or member-function)
int C1::getvalue() const { return c1val; } // function-member( or member-function)




// as an alternative, we can create two versions of a functions
// Here we created same/similar calss C2. this time we have two getvalue()  functions.
class C2 {
    int c2val{}; // data-member(member variable)
public:
    void setvalue(int value);
    
    int getvalue();
    int getvalue() const;

};

//function definitions
void C2::setvalue(int value) { c2val = value; } // function-member( or member-function)
int C2::getvalue()  { // function-member(or member-function)
    cout << "mutable getvalue() func.\n";
    return c2val; 
} 
int C2::getvalue() const {  // function-member( or member-function)
    cout << "const(not-mutable) getvalue() func.\n";
    return c2val; 
} 


//RULE:
// ==> const qualified function allways be called by const or mutable objects.
// ==> non-const qualified functions may only be called by  only non-cost/mutable objects.

int main() {
    C1 o1;

    // as we see here we cosnt qualified the getvalue() function in tthe class. both o1(non-cost) and o2(const) 
    // can call/use the same function.
    o1.setvalue(47);
    cout << format("value is {}\n", o1.getvalue());
    const C1 o2 = o1;
    // compiler error: the object has type qualifiers that are not compatible with the member function/ object type is: const C1
    // this errors says: yhe object o2 is const but the function we cal on it (getvalue()) is not const.
    // because compiler wants to make sure that the function(getvalue()) will not change it.
    cout << format("value is {}\n", o2.getvalue());
    cout << format("======================================\n");


    C2 o3;

    // here we 2 objects of C@ class. o3 is a non-const and o4 is const object.
    o3.setvalue(72);
    const C2 o4 = o3;
    cout << format("value is {}\n", o3.getvalue()); // this will call non-const version of getvalue()
    cout << format("value is {}\n", o4.getvalue()); // this will call const version of getvalue()

    
}
