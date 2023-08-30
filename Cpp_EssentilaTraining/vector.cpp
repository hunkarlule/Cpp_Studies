// vector.cpp by Bill Weinman [bw.org]
// updated 2022-06-04
#include <format>
#include <iostream>
#include <string>
#include <vector>

using std::format;
using std::cout;
using std::vector; // think vector is as an object-orineted array. it is a tem,plate class in vector header.

int main() {
    cout << "vector from initializer list:\n";
    vector <int> vi1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // creating vector of ints. using initilizer list

    cout << format("size: {}\n", vi1.size());
    cout << format("front: {}\n", vi1.front());
    cout << format("back: {}\n", vi1.back());
    cout << '\n';

    // iterator
    cout << "iterator:\n";
    auto itbegin = vi1.begin();
    auto itend = vi1.end();
    for (auto it = itbegin; it < itend; ++it) {
        cout << format("{} ", *it);
    }
    cout << "\n\n";

    // access a element at a specific index
    cout << "access a element at a specific index:\n";
    cout << format("element 5: {}\n", vi1[5]);   // this does not make range cjecking
    cout << format("element 5: {}\n", vi1.at(5)); // at methid does range checkinh.

    // using range-basd for loop with vector
    cout << "range-based for loop:\n";
    for (const auto& i : vi1) {
        cout << format("{} ", i);
    }
    cout << " \n\n";
    
    // insert an element at a specific postion.
    cout << "insert 42 at begin + 5:\n";
    vi1.insert(vi1.begin() + 5, 42);
    cout << format("size: {}\n", vi1.size());
    cout << format("element 5: {}\n", vi1.at(5));

    cout << "vector after insert:\n";
    for (const auto& i : vi1) {
        cout << format("{} ", i);
    }
    cout << " \n\n";
    
    // remove/erase an element at a specific postion.
    cout << "erase at begin + 5:\n";
    vi1.erase(vi1.begin() + 5);
    cout << format("size: {}\n", vi1.size());
    cout << format("element 5: {}\n", vi1.at(5));

    cout << "vector after erase:\n";
    for (const auto& i : vi1) {
        cout << format("{} ", i);
    }
    cout << " \n\n";


    // insert/push element at tyhr ned of the vector.
    cout << "push_back 47:\n";
    vi1.push_back(47);
    cout << format("size: {}\n", vi1.size());
    cout << format("vi1.back(): {}\n", vi1.back());
    cout << '\n';

    cout << "vector after push_back:\n";
    for (const auto& i : vi1) {
        cout << format("{} ", i);
    }
    cout << " \n\n";

    // create a vector from C-array
    const size_t size{ 10 };
    int ia[size]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // C-array
    cout << "vector from C-array:\n";
    // here we give two pointers hwen creating vector from c-array
    // first beginning of the c- array adn secon one is the end of c-array.
    vector<int> vi2(ia, ia + size); 
    
    for (const auto& i : vi2) {
        cout << format("{} ", i);
    }
    cout << "\n\n";
    
    // vector of strings
    cout << "vector of strings:" << std::endl;
    vector<std::string> vs{ "one", "two", "three", "four", "five" };
    for (const auto& v : vs) {
        cout << format("{}\n", v);
    }
}
