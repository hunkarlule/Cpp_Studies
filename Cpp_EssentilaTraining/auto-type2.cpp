// auto-type2.cpp by Bill Weinman [bw.org]
// updated 2022-05-25
#include <format>
#include <iostream>
#include <typeinfo>
#include <vector>

using std::format;
using std::cout;

int main() {
    std::vector<int> vi { 1, 2, 3, 4, 5 };
   
    // here we are iterating vector using iterators.
    // fist we initilized iteraaotr it. its type is std::vector<int>::iterator. that is cumbersome.
    // before the auto type we need to write that type manually and correctly. But with aout we can do that more easily.
    for(std::vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        cout << format("int is {}\n", *it);
        cout << format("type of it is {}\n", typeid(it).name());
    }

    // here same for loop using iterators but we used auot when initilizing iterator it. Thsi is so easy. Also more safer than the above.
    // here we initilized it with "it.begin()" that return as iterator. so compiler deduce/determine the type  of it using that return value.
    for (auto it = vi.begin(); it != vi.end(); ++it) {
        cout << format("int is {}\n", *it);
        cout << format("type of it is {}\n", typeid(it).name());
    }
}
