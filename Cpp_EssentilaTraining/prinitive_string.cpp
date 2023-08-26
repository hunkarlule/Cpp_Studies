// working.cpp by Bill Weinman [bw.org]
// updated 2022-05-21
#include <format>
#include <iostream>

using std::format;
using std::cout;

// primitive string is a special case of an array.
// primitive strings are C-string. Thay are not same with the C++'s string class from Standard template library.
// a primitive string is a psecila case of an array of characters.
int main() {
    // here is a primitive string (C-string). It is simply an array of sharacters. But, be aware that
    // when we do this initilization compiler adds a null-terminatos character('\0') at the end for us. So it makes it a C-string!.
    // that means
    const char s[]{ "String" }; 
    cout << format("{}\n", s);

    
     // becuase C-string is a array of charcters we can do the following instead of above.
    // however in this case we need also add null-teminator character('\0') to the arary as a last element to the array.
    // Otherwise s1 will Not be a C-String. Adding null-terminator character makes s1 a C-string
    const char s1[]{ 'S', 't', 'r', 'i', 'n', 'g', '\0'}; // '\0' or 0 is for null-terminator character.
    //const char s[]{ 'S', 't', 'r', 'i', 'n', 'g', 0  };
    cout << format("{}\n", s1);

    // here no null-terminator character. S2 is also an array of charcters but s2 in not a C-String.
    const char s2[]{ 'S', 't', 'r', 'i', 'n', 'g'};
    cout << format("{}\n", s2); // you see this print is weird becuase there is no null-terminator charates in s2. be careful!


    // we can loop over C-string like a normal array.
    // because there is a null-terminator charcter at the and this for-loop will also pirnt that. To avoid that we can put the folloing if check.
    for (const auto& c : s) {
        if(c) { // null-terminater charcter( '\0' or 0) will be evaluated as false.
        cout << format("{}\n", c);
        }
    }
    cout << "============================\n";
    // isntead of above we can use this loop. traditional loop using pointer
    // we initilized ptr with string name(array name) s becuase array names is address of the array.
    for (const auto* ptr = s; *ptr; ++ptr) { // *ptr is testing for null-terminater. So it evaluates folase when prt points to null-terminater character.
            cout << format("{}\n", *ptr);
    }

    cout << "============================\n";
     // but most common way of delating a C-string is like below:
    // so s3 is a char pointer that points to  contant string " Strinh
    const char* s3{ "String" };
    //const char* s3 = "String" ; // or like this
    for (const auto* ptr = s3; *ptr; ++ptr) { // *ptr is testing for null-terminater. So it evaluates folase when prt points to null-terminater character.
        cout << format("{}\n", *ptr);
    }

    // note that is we define a sonstand string with a pointel liek s3. then we can not use the range-base-for loop
        //for (const auto& c : s3) {
        //    if (c) { // null-terminater charcter( '\0' or 0) will be evaluated as false.
        //        cout << format("{}\n", c);
        //    }
        //}

}
