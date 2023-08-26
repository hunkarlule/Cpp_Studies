// qualifiers.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
#include <iostream>
#include <format>

using std::cout;
using std::format;


// qualifier are adjust qualities of objects and variables.
int func() {
    int x {7}; // here x is automiatic- duration. everytiem func() is called x will be created and when function finishes x will die.
    return ++x;
}


// func1() is competely same withj func(). only difference that x is defined with "static" in func1()
int func1() {
    // with this static keyword x will continue to live after  func1 finishes. life of x will be the life of main() funcion(program)
    // once func1 is called x will be created/defined. subsequent calss to func1 will not create x1 again. The will use the variable x that is created during the fist call of func1.
    static int x{ 7 }; // here everytim
    return ++x;
}



int main() {
    // here const and static qualifier.
    // const says the x will be immutabel/
    // static says the x will have static storage duration.
    const static int x{ 42 };
    //x = 45 // error because x is const


    // two types of qualifier in C++
    // CV(constant&volitile) qalifiers: const, mutable, volitile
        // const: marks a variable as read-only(immutable). si it value can not be cahnged once the cvariable is defined.
        // mutable: used with data-members of a class to make them writable from a const qualified member function. Means,  iy you makr a member-function with const, that means
                  // it will not cahnge the value of class's data-members. but if we mark data-members with "mutable" that we can change them from const member-functions.  
        // volitile: marks a variable that may be cahnged by another process. Rarely used. Partly deprecated by C++20.
        // 
    // Storage duration qualifiers: static, register, extern. These are used to define the duration or life time ofa variable.
    // By defult, a varaiab;e defined within a block has a automatic duration(life-time). the duration/life-time of variable is the duration of the block, in whihc it is defined. No need for a
    // qualifier for this(for atuomatic duration) because it is default.
        // static: variable defined with static qualifier have life bedond the execution fo the block, in whihc thay are defined.
                  // Static variable live for the duration of the program. Static variables are commonly used for keeping state between usages of a given function or a method.
                  // By default, a variable defined outside of a any block is static.
        // register: Register variables are sotred in processor registers. this makes them faster and easiers to access and process(operator on). However, if you defien a variable
                    // with rest qualifier then it will only be taken as a siggestion by the compiler. The compiler will deterine whether to actually store the variable in registers or not.
        // ester: Exter variables are defiend in separate translation unit and are linked with your code by the linker step of the compilation process.
    int i {42};
    i = 73; // OK.
    cout << format("The integer is {}\n", i);


    const int i1{ 42 }; // qualified with const
    //i1 = 73; // cmpiler error because i1 is const.
    cout << format("The integer is {}\n", i1);


    // all lines here print same result for func() calle.
    cout << format("func returns {}\n", func());
    cout << format("func returns {}\n", func());
    cout << format("func returns {}\n", func());


    // see here ecah line prints a different value.
    cout << format("func1 returns {}\n", func1());
    cout << format("func1 returns {}\n", func1());
    cout << format("func1 returns {}\n", func1());




    //
}
