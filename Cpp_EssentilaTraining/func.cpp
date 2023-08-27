// func.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <format>
#include <iostream>

using std::format;
using std::cout;

// definition of func. a definition is a decleration at the same time.
void func() {
    cout << "this is func()\n";
}

// decleration of func1. 
// decleration contains function signature  + semicolon(;).
void func1();

// variable declared in functions is defaulf  ot"automatic-storage"
//that means everytime a function is called the variables defiend in fucntion will be created and will die when the function execution fiinihed.
// everytime func2 is called i will be initilized with 5. Here we increment i in the func2. But this will not affect the subsequens calls because i will be created again wiht every call to func2.
// these variables(automatic-vstorage varibales) are stored in stack. It is not good for using large objects. Because it can cause stack-oerflow. So, for large object use static storage.
void func2() {
    auto i = 5;
    ++i;
    cout << format("i is {}\n", i);
}


// alternative to "automatic-stoarage/duration" is statis storage. To do that we define/marc valus in function with static keyword.
// with static keyword, variables will continute to live even after function is finised its execution. More correctly, variable will live until ned of the main(program)
// so static variables defied in the function will be created once(with the first call) and subsequesnt calls to fucntion will use the that same(only) variable. And that variables life-time is equal to porgram's life time.
// static variables will be stored in permanent storage.
void func3() {
    static auto i = 5;
    ++i;
    cout << format("i is {}\n", i);
}


int main() {
    cout << "this is main()\n";
    func();

    // a function sohuld be declared(or defined) before it is called.
    // here we called func1. but, when the below line tries to execute the compiler does not know anything about what is func1? ==> so it is compilatio error: 'func1': identifier not found
    // compiler at least needs the decleration of func1. so it can compile the below line. To handel this error we put the decleration of func1(void func1();) above main. So now, compiler know what is func1 when it tris to compiler below line.
    // note that still func1 is not defined. it is only decleration compiler saw above the main but this is enough for it to compile below line.
    func1();

    // all these line prints the same value.
    func2();
    func2();
    func2();

    cout << format("==============================\n");

    // all these line prints different value.
    func3();
    func3();
    func3();
}

// definition of func1.
void func1() {
    cout << "this is func()\n";
}
