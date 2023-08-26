
#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    int arr[] { 1, 2, 3, 4, 5 }; //array initilized with an initializer list. See we did not give a size to array. compiler will determine it from the initilizer list.
    int arr1[5]{ 1, 2, 3, 4, 5 }; // same as above here we also tell it is size also.
    int arr2[5]{ }; //here arr2 : is an array of int with size 5. All elements of arr2 is assigned to 0 due to {empty initilizer list({}).
    int arr3[5]; //here arr3 : is an array of int with size 5. Elements are not assigned. There are garbage values in them. Avoid this.

    for(const int& i : arr) { //fro-range loop. here we defined i as const int&. const means we cannot(do not want to) cahnge array using i. reference(&) makes there there is no copy.
        cout << format("{} ", i);
    }
    cout << '\n';


    auto x = arr[2]; // we can read  values values elements like this
    cout << format("x is {}\n ", x);

    arr[2] = 42; // we can assign new values to elements like this.
    cout << format("x is {}\n ", x);

    // array name is like a pointer to the array itself. It hold the address of the array. so we can assing it to pointer like below.
    auto* ptr = arr; // here we initilized pointer ptr with array name "arr" because array name holds the address of the array.

    auto y=  *ptr; // we can read  values values elements like this
    cout << format("y is {}\n ", y);

    //becuase array name holds the address of the arrya we can do the folowing.
    cout << format("first element is {}\n", *arr);

    *ptr = 34; // here assigned first element using ptr.

    cout << format("first element is {}\n", *arr); // *ptr



    for (const int& i : arr) { //fro-range loop. here we defined i as const int&. const means we cannot(do not want to) cahnge array using i. reference(&) makes there there is no copy.
        cout << format("{} ", i);
    }
    cout << '\n';


    // in C++ pointers are strongly typed. so, they know the size of what tyey point ot. so when you increment(decrement) the pointer it always increments by the size of
    // of the object or type it is defined with. Therefore ++ptr makes it point to next element.
    ++ptr; //we insremented the pointer. so now ptr will be poinitng to the second element.
    cout << format("second element is {}\n", *ptr);

    *ptr = 3; // assined new valut to the lement of the array that ptr is poiniting. in this case it second element.
    cout << format("second element is {}\n", *ptr);


    // first we increment the pointer and then assign a new value for the lement that points to.
    *(++ptr) = 99;
    for (const int& i : arr) { //fro-range loop. here we defined i as const int&. const means we cannot(do not want to) cahnge array using i. reference(&) makes there there is no copy.
        cout << format("{} ", i);
    }
    cout << '\n';

    //++arr; // compiler error. you cannot change the address of an array. It will give a compile time error. the operand of ++ must be a modifiable lvalue, and array expressions are not modifiable lvalues.
    //arr++; // compiler error. you cannot change the address of an array. It will give a compile time error. the operand of ++ must be a modifiable lvalue, and array expressions are not modifiable lvalues.

  




}
