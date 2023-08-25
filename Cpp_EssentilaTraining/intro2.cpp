// hello.cpp by Bill Weinman [bw.org]
// updated 2022-05-19
#include <iostream>
#include <cstdio>
#include <format> // c++20
//#include <print> // will be available in C++23

// namespaces are used to aviod  collision between names that are defined.
// std name space(short for standard)  std is isue for all symbols in C++ standard library.
// :: ==> is scope resoulution operator. It tells the compiler to look/use this name space
// when lookin up for this symbol. for example "std::cout" is uses cout object from std namespace.


// we can also do this:
// this imports the name from the  name sapce. 
// so we do not need to use "std::cout" verytime in out code when we use the cout object.
using std::cout; 
int main() {

    const char* str{ "Hello, World!" };
    std::cout << "Hello, World!\n";
    std::cout << "The str is " << str << "\n"; // cout safer than printf.
    printf("The str is %s\n", str); // fast and smaller than cout

    std::cout << std::format("The str is {}\n", str);

    // because we importad the nema with(using std::cout;)
    // we can use the cout without porviding std(namespace) and(::) scope resoulution operator.
    // See that we still need to use fromat like this(std::format) becuase we did not imported it to our code with "using" statement.
    cout << std::format("The str is {}\n", str);

    //std::print("The str is {}\n", str); // this utulize format function. will be availbale with C++23.

    // return is optional in main . if you omit return in the main then it will assume that 0 is returned.
    return 0; // means main run and successfully and exited normally.
    //return 1; //  indicates an error occured.
}


// main with arguments.
// main can have arguments to pass from command line.
/*
        int main(int argc, char** argv) {
        //int main(int argc, char* argv[]) { //same as above line
            // argc:  repsresents the number of arguments passed from command line
            // argv: is an array of strings that contains theargumenrs passed from the command line

            std::cout << "Hello, World!\n";
            return 0; // means main run and successfully and exited normally.
            //return 1; //  indicates an error occured.
        }
*/