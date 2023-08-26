
#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    auto x = 5;
    auto y = 47;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    cout << format("========================\n");


    // Nore that all of these opeerator creats a new temp object instead of chagning the objects used in the operatiosn.
    // at the end, that temo object is copied to x with assignment(=) operator.
    x = y; // assignment operaotr or copy operator.
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);
    cout << format("========================\n");
    
    // artimetic operators
    x = 5;
    x = y + x; 
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    cout << format("========================\n");

    x = 5;
    x = y - x;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    cout << format("========================\n");

    x = 5;
    x = y * x;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    cout << format("========================\n");

    x = 5;
    x = y / x; // note that this is in division and omits the reaminning.
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    cout << format("========================\n");

    x = 5;
    x = y % x; // module(reaminder) operatpr
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);


    // comparison operators: used to compare fro equalitiy or relative value.
    cout << format("========================\n");
    x = 5;
    if (x == y) cout << "true\n";
    else cout << "false\n";
    if (x > y) cout << "true\n";
    else cout << "false\n";
    if (x >= y) cout << "true\n";
    else cout << "false\n";
    if (x < y) cout << "true\n";
    else cout << "false\n";
    if (x <= y) cout << "true\n";
    else cout << "false\n";
    if (x != y) cout << "true\n";
    else cout << "false\n";

    cout << format("========================\n");
    // logical operaotros: for testing locical conditions

    bool a { true };
    auto b { false }; // or auto b = false; or bool b = false; or bool b {false}; or bool b {};

    cout << format("a is {}\n", a);
    cout << format("b is {}\n", b);

    cout << format("========================\n");

    // 0 is considered as false and any non-zero value is considered true.
    //bool a1 { 47 }; // error: conversion from 'int' to 'bool' requires a narrowing conversion
    bool a1 = 47; // we need to do this instead of above line.
    bool b1 = 0; 

    cout << format("a1 is {}\n", a1);
    cout << format("b1 is {}\n", b1);

    // bool type is impelemnted as smalles size possible. usally 8 bits.
    cout << format("size of a1 is {} bits\n", sizeof(a1) * 8);
    cout << format("size of b1 is {} bits\n", sizeof(b1) * 8);

    cout << format("========================\n");

    // three boolean logical operators
    if (a && b) cout << "true\n";
    else cout << "false\n";
    if (a || b) cout << "true\n";
    else cout << "false\n";
    if (!a) cout << "true\n";
    else cout << "false\n";

    cout << format("========================\n");
    // operands of boolean operatos could be any logical expressions.
    if (42 > 5 && b) cout << "true\n";
    else cout << "false\n";
    if (42 > 5 && a) cout << "true\n";
    else cout << "false\n";

    cout << format("========================\n");

    // && and || operatos perform "short circuiting evaluation: that means they first evaluate the left-side
    // of the operand. If its result is enouhg to determine whole result of logical operator(&& or ||) 
    // then right hand sied ins not evaluated.

    // here operands of || operator: left-side: (42 > 5), right side: a
    // so first left-side is evaluated and it returns true. so
    // condition becomes  fi(true || a) ==> after that point the rigth-side will ne be evaluated because for "||"
    // if one of the operands is true then whole condition((42 > 5) || a) will be true.
    // Therefore compiler will not evaluate the right-side.
    if ((42 > 5) || a) cout << "true\n";
    else cout << "false\n";


    // here operands of && operator: left-side: (42 < 5), right side: a
    // so first left-side is evaluated and it returns false. so
    // condition becomes  if(false || a) ==> after that point the rigth-side will ne be evaluated because for "&&"
    // if one of the oerands is false then whole condition((42 < 5) || a) will be false.
    // Therefore compiler will not evaluate the right-side.
    if ((42 < 5) && a) cout << "true\n";
    else cout << "false\n";


    cout << format("========================\n");

    // compound assignment operators: combine assignment with artimetic operators.

    x = 5;
    y = 47;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);


    cout << format("========================\n");
    // this one(y += x;) adss x to y.
    // this is equal to writing:  y = y + x;
    // then what is the difference? ==> Difference is with y += x; ==> the y is only evaluated ONCE. so they are more efficient.
    // this subtle difference could make some diffference in terms of persormance in some circumstances.
    y += x;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    x = 5;
    y = 47;
    y -= x;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    y *= x;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    y /= x;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    y %= x;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

}
