// variables.cpp by Bill Weinman [bw.org]
// updated 2022-06-12
#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    // defines an integer i. also allocates space in memory to hold an integer.
    // {} braces initialize the variable i with defaul value(0 for integer).
    // {} braces is special cae and it initilize any time with its default value.
    int i{}; 
    cout << format("i is {}\n", i);

    i = 47;
    cout << format("i is {}\n", i);


    // j is not initilized. so these can cause bugs in the program. 
    // it is good practice to always initilize the variables with a value upon definition.
    int j; 
    cout << format("j is {}\n", j); // this will print a a random /meaningless value!!! - be careful.


    // defines an integer k. also allocates space in memory to hold an integer.
    // {47} braces initialize the variable k with value 47.
    int k{47};
    cout << format("k is {}\n", k);


    // defines an integer k1. also allocates space in memory to hold an integer.
    // initialize the variable k1 with value 47.
    // we used = instead of {} to initilize k1.
    // both are doing same thing. = is C way to initilize.
    // {} is modern C++ way. Prefer this one. this is more efficient and safer.
    int k1 = 47;
    cout << format("k1 is {}\n", k1);

    // const qualifier
    // indeed with this type of m becomes "const int". qaulifier becomes part of the type.
    const int m{}; // m is const means we can not change it is value after it is defined.
    cout << format("m is {}\n", m);
    //m = 47; // compiler error because m is "const"

    // used auto here. so compiler will determine tyep of the n according to the value we assigned to it.
    // so, here we assigned 47(a integer literal) so compiler will determine type of n as int.
    // advantage of using auto: some types type names are so long and complex. so it is diffcult to write them.
    // with auto we can easily manage this becuase we will assing an right value and compiler will deduce the type from it.
    auto n = 47;    
    cout << format("n is {}\n", n);
    
    //compiler error: can not use auto without initilizing with an initila value. 
    // compiler can not deduce the type of n1
        //auto n1; 

    //compiler error: can not use auto with only empty braces({}) for initilization.
    // compiler can not deduce the type of n2
        //auto n2{}; // compiler error

     // this is OK.
     auto n3{47}; 
     //auto n3 = 47; // with auto it is more common to use = for initialization.
     cout << format("n3 is {}\n", n3);
}
