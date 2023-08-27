
#include <format>
#include <iostream>
#include <string>

using std::format;
using std::cout;


// void means func return nothing.
void func() {
    cout << format("This is func()\n");
}


int func1(int a ) {
    cout << format("This is func1()\n");
    return a * 2;
}


const std::string func2(int a) {
    static std::string s = format("value is {}", a * 2); //we make this static becauseit could be too big and we do not want store i on the stack
    cout << format("This is func1()\n");
    return s;
}





int main() {

    int a{ 42 };

    cout << "this is main()\n";
    func();

    cout << format("==============================\n");

    //what happens here is:
    // 1- value of a (42) is pushed to the stack.
    // 2- same value 42 is popped from the stack and a in func1 is initilized with that.
    // 3- func1 returned a * 2 = 84. That value 84 is poushed to the stack.
    // 4 - values 84 from the satck is popped and with that x is initilized.
    // as we see all this things ahppnes on the stack therefore be careful do not pass large value by value. That can cause issue with the program becuase stack has a limited space.
    int x = func1(a);
    cout << format("value of x is {}\n", x);

    cout << format("==============================\n");


    //what happens here is:
// 1- value of a (42) is pushed to the stack.
// 2- same value 42 is popped from the stack and a in func1 is initilized with that.
// Because we returning a string refernce the return value(s) will not be copied to the stack. this saves us a lot interms of stack storage andp erformance.
    const auto& y = func2(a);
    cout << format("y is:  {}\n", y);

    cout << format("==============================\n");



    return 0;
}


