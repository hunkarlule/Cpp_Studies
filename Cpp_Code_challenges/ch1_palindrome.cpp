// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.

// solution-1
bool is_palindrome1(std::string str){

    // Write your code here
    bool isPalindrome = true;
    for (int i = 0; i <= str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    return isPalindrome;
}

// solution-2
bool is_palindrome(std::string str) {

    // Write your code here
    transform(str.begin(), str.end(), str.begin(), tolower); // transforming to lowercase.
    string reversedString = str;
    reverse(reversedString.begin(), reversedString.end()); // reversing the string


    return str == reversedString;
}

// Main function
int main(){
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}
