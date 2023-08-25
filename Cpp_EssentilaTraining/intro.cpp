// hello.cpp by Bill Weinman [bw.org]
// updated 2022-05-19
#include <iostream>
#include <cstdio>
#include <format> // c++20
//#include <print> // will be available in C++23

int main() {

    const char* str{ "Hello, World!" };
    std::cout << "Hello, World!\n";
    std::cout << "The str is " << str << "\n"; // cout safer than printf.
    printf("The str is %s\n", str); // fast and smaller than cout

    std::cout << std::format("The str is {}\n", str);

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