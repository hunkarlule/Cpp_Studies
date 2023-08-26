// working.cpp by Bill Weinman [bw.org]
// updated 2022-05-21
#include <format>
#include <iostream>

using std::format;
using std::cout;


// unary operators( ++ and --):  to increment(++) and decrement(--) values.
int main() {
    auto  x{ 5 };


    // here is prefix version of  ++ and -- operators.
    // here ++x ==> first increments the value and then returns the incremented value.
    cout << format("x is {}\n", ++x); // pritns 6. becuase ++ incremenrs x from 5 to 6 and then retirns that incremented value(6)
    cout << format("x is {}\n", ++x); // 7
    cout << format("x is {}\n", ++x); // 8.

    cout << format("==================================\n");

    x = 5;

    // here --x ==> first decrements the value and then returns the decremented value.
    cout << format("x is {}\n", --x); // pritns 4. becuase -- decrements x from 5 to 4 and then returns that decremented value(4)
    cout << format("x is {}\n", --x); // 3
    cout << format("x is {}\n", --x); // 2.

    cout << format("==================================\n");

    // here is postfix version of  ++ and -- operators.
    x = 5;

    // here x++ ==> first returns the value that is hold in the x and then the increments the x.
    cout << format("x is {}\n", x++); // pritns 5. becuase ++ first returns the initial value(value before increment) of x(it is 5). Then increments x from 5 to 6.
    cout << format("x is {}\n", x++); // 6
    cout << format("x is {}\n", x++); // 7.

    cout << format("==================================\n");

    x = 5;

    // here x-- ==> first returns the value that is hold in the x and then the decrements the x.
    cout << format("x is {}\n", x--); // pritns 5. becuase -- first returns the initial value(value before decrement) of x(it is 5). Then decrements x from 5 to 4.
    cout << format("x is {}\n", x--); // 4
    cout << format("x is {}\n", x--); // 3.
}
