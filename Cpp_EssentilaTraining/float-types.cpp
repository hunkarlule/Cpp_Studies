
#include <format>
#include <iostream>

using std::format;
using std::cout;

// a byte is 8 bits
const size_t byte {8};

int main() {
    float f {};
    double df {};
    long double ldf {};
    
    // sizeof() operator retutns the size of the object in bytes.
    cout << format("size of float f is {} bits\n", sizeof(f) * byte);
    cout << format("size of double df is {} bits\n", sizeof(df) * byte);
    cout << format("size of long double lddf is {} bits\n", sizeof(ldf) * byte);

    // sizeof() operator retutns the size of the type in bytes.
    cout << format("size of float type is {} bits\n", sizeof(float) * byte);
    cout << format("size of double type is {} bits\n", sizeof(double) * byte);
    cout << format("size of long double type is {} bits\n", sizeof(long double) * byte);

    float f1{ 500.0 }; // initializing f1 with 500.0
    cout << format("value of f1 is {}\n", f1);
    float f2{ 5e2 }; // initializing f2 with 500.0. but we used scientific notation here.
    cout << format("value of f2 is {}\n", f2);


    // scale and precision difference:
    // scale: how a number large or small a number can be
    // precision: is the accuracy of the representation to a certain number of significan digits.
    float f3 = 0.1 + 0.1 + 0.1; // here we expect f3 to be 0.3
    cout << format("value of f3 is {}\n", f3); // here it pritns as we ecpect
    cout << format("value of f3 is {:.20f}\n", f3); // here we printed f3 with 20 places to see its actual value better. it prints like: 0.30000001192092895508
    
    // however when we make this comparison it pritns flase because f is not excatly 0.3
    if (f3 == 0.3) cout << "true\n";
    else cout << "false\n";


    // scale and precision difference:
    // scale: how a number large or small a number can be
    // precision: is the accuracy of the representation to a certain number of significan digits.

    // we can represent very larga and very small numbers with floating point number ==> this is called scale.
    // however precision of these types are always limited. That means they are not representing the numbers excatly. As seen below..
    // if you want scale use floating points but be aware that you scarifice/lose some precision!.
    double df3 = 0.1 + 0.1 + 0.1; // here we expect df3 to be 0.3
    cout << format("value of df3 is {}\n", df3); // this print somethign like:  0.30000000000000004 so it is not 0.3
    cout << format("value of df3 is {:.20f}\n", df3); // here we pritnted df3 with 20 places to see it is value better

    // this prtints false becasue df3 is not actually 0.3
    if (df3 == 0.3) cout << "true\n";
    else cout << "false\n";

    
}
