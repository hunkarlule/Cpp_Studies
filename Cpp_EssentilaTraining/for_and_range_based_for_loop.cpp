
#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    int array[] { 1, 2, 3, 4, 5 };

    // thres expression ins for parantesis(()):
    // initializer ; condition; inrementer
    for (int i{ 0 }; i < 5; ++i) {
        cout << format("element {} is {}\n", i, array[i]);
    }

    cout << "after1\n";


    const char str[]{"string"};
    //const char* str{ "string" }; //same as above.
    for (int i{ 0 }; str[i]; ++i) { // here test condition is str[i]. becuase last char in C-string is null terminater chrater('\0') and that is evaluated as false.
        cout << format("element {} is {}\n", i, str[i]);
    }

    cout << "after2\n";


    // here we used pointer for the loop. we initilized the pointer p with the value of array(str)
    // in C and C++, the value of array is pointer to its firs elemment
    // our test expression is(*p).So when it reachs the last element/char of the str(it is null-terminator charcter)
    // so *p ==> returns  '\0'( null-terminator chracter).And that evaluated as false ad we go out of loop.
    for ( auto* p = str; *p ; ++p) { 
        cout << format("char is {}\n", *p);
    }

    cout << "after3\n";


    int arr[]{ 1, 2, 3, 4, 5 };

    // range-based for loop ==> came with C++11. 
    // makes it easy to loop over elements of a container.
    for ( const auto& e : arr) { // because we used & here we put const to make sure that we do not changing anything using reference by mistake!
        // here e will be a reference to element of the array.
        //e += 1; // comnpiler error because we defined e as  of type const auto&. So we can not use it to chane array elements
        cout << format("element is {}\n", e);
    }

    cout << "after4\n";

    // range-for loop for C-string
     const char str1[]{ "string" };
    //const char* str1{ "string" }; //same as above.
    for ( const auto& e : str1) { 
        if (e == 0) break;
        cout << format("element is {}\n",  e);
    }

    cout << "after5\n";



}
