
#include <format>
#include <iostream>
#include <cstdint>

using std::format;
using std::cout;

 // run the code yo see the pointer inrement /decrement effect.

 //using int_type = uint8_t; // here alias for uint8_t type.
//using int_type = uint16_t; // here alias for uint16_t type.
using int_type = uint32_t; // here alias for uint32_t type.

// pointers are stringly typed. and system know the size of the object that the pointer points to.
// therefore when you increment(++) or decrement(--) a pointer the increment and decrement will be
// that size(means size of the obhect that points to).
void printp(const int_type* p) {
    cout << format("pointer is {}, value is {}\n", static_cast<const void*>(p), *p);
}

int main() {
    int_type arr[] { 1, 2, 3, 4, 5 }; // same as: uint8_t arr[] { 1, 2, 3, 4, 5 };
    int_type* p = arr; // here we assigned arr(name of array) to pointer p. becuase array name holds the address of the array.
    
    // here printp function will be called with the initial value of p and after that p will be incremented.
    // because types of arr is "int_type" and it is "8bit unsignedn int"(means basically 1 byte). 
    // when p incremented it increments 1. see the address values below.
    // see the results when you run the same code(using  ==> using int_type = uint32_t;)
    // Sortly: when you increment/decrement the pointer it increments/decrements it so that the pointer can point to next/previous value.
    printp(p++);  // prints: pointer is 0x16cdb1f944, value is 1
    printp(p++);  // prints: pointer is 0x16cdb1f945, value is 2
    printp(p++);  // prints: pointer is 0x16cdb1f946, value is 3

    cout << format("=========================================\n");


    // note that prefix ++ and -- operators are more efficient than the postfix -- and ++ operators.
    // because postfix ++/-- operators first thay need to make a copy of the value before incrementing/decrementing it.
    // After that they will increment or decrement it. Finally, they will return value before increment/decrement(that copied value)
    // therefore postfix is less efficient(more costly) than the prefix version due to that extra copy.
    int_type arr1[]{ 1, 2, 3, 4, 5 }; // same as: uint8_t arr[] { 1, 2, 3, 4, 5 };
    int_type* p1 = arr; // here we assigned arr(name of array) to pointer p. becuase array name holds the address of the array.

    // here printp function will be called with the initial value of p and after that p will be incremented.
    // because types of arr is "int_type" and it is "8bit unsignedn int"(means basically 1 byte). 
    // when p incremented it increments 1. see the address values below.
    // see the results when you run the same code(using  ==> using int_type = uint32_t;)
    // Sortly: when you increment/decrement the pointer it increments/decrements it so that the pointer can point to next/previous value.
    printp(++p1);  // prints: pointer is 0x16cdb1f944, value is 1
    printp(++p1);  // prints: pointer is 0x16cdb1f945, value is 2
    printp(++p1);  // prints: pointer is 0x16cdb1f946, value is 3

}
