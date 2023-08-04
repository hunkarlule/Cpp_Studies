#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(const string &input) {

    stack<char> charStack;

    for (char ch : input) {
        charStack.push(ch);
    }

    string reversedString = "";

    while (!charStack.empty()) {
       char topElementFromStack = charStack.top();
       charStack.pop();
       reversedString += topElementFromStack;
    }

    return reversedString;
}

int main()
{
    string str = "Hello, World!";
    string revStr = reverseString(str);

    cout << reverseString("Hello, World!") << endl;

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << revStr << endl;

    return 0;
}
