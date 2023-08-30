
#include <format>
#include <iostream>
#include <string> //string container is in this header.
using std::format;
using std::cout;
using std::string;

// string container class operates on the caratcters in much the same 
// way as any sequence container operates on other types.
// string class implement as sequence container of characters.

int main() {
    string s1{ "This is a string" }; // creating a string object.
    cout << format("String is : {}\n", s1);

    // size & length
    cout << format("length is same as size: {}\n", s1.length());
    cout << format("size is same as length: {}\n", s1.size());
    cout << "\n";
    
    // + for concatenation
    cout << "concatenated strings with +: ";
    string s2 = s1 + ":" + "this is also a string";
    cout << s2;
    cout << "\n\n";

    // comparing string with ==
    cout << format("is s1 == s2? : {}\n", s1 == s2 ? "yes" : "no");
    cout << "\n";

    // copy-assign strings
    cout << "copy-assign s2 = s1\n";
    s2 = s1; // assigning s1 to s2
    cout << format("is s1 == s2? : {}\n", s1 == s2 ? "yes" : "no");
    cout << "\n";

    string otherstr{ "other string" };

    // compare string with >, < operators.
    cout << format("is s1 > otherstr? : {}\n", s1 > otherstr ? "yes" : "no");
    cout << format("is s1 < otherstr? : {}\n", s1 < otherstr ? "yes" : "no");
    cout << format("is otherstr > s1? : {}\n", otherstr > s1 ? "yes" : "no");
    cout << format("is otherstr < s1? : {}\n", otherstr < s1 ? "yes" : "no");
    cout << "\n";

    // iterate over string suing range-based for loop
    cout << "each character: ";
    for (const auto& c : s1) {
        cout << format("{}", c);
    }
    cout << "\n\n";
    
    // insert & erase character to/from string with an iterator
    s1.insert(s1.begin() + 5, 'X'); // inserting 'X' at index 5 to the string.
    cout << format("s1 after insert: {}\n", s1);
    cout << '\n';

    s1.erase(s1.begin() + 5); // erasing character at index 5 from the string.
    cout << format("s1 after erase: {}\n", s1);
    cout << '\n';

    // replace a part of string with a new one.
    s1.replace(5, 2, "ain't"); // starting position at 5 replace 2 character with "ain't"
    cout << format("s1 after replace: {}\n", s1);
    cout << '\n';

    // find sunstring of string. 

    cout << format("substr: {}\n", s1.substr(5, 5)); // find substring of 5 character stating position at 5.
    cout << format("substr: {}\n", s1.substr(5, 4)); // find substring of 4 character stating position at 5.
    cout << '\n';

    // find first "s"(this is a substring) in the string s1. This will return index/position of first s.
    size_t pos = s1.find("s");
    cout << format("find first \"s\" in s1 (pos): {}\n", pos);
    cout << '\n';


    // find first "sxxx"(this is a substring) in the string s1. This will return index/position of first "sxxx".
    pos = s1.find("sxxx");
    cout << format("find first \"sxxx\" in s1 (pos): {}\n", pos);
    cout << '\n';


    // find last "s"(this is a substring) in the string s1. This will return index/position of first s.
    // this is basically doing the same thing but di=oing from from trh right-hand-side.
    pos = s1.rfind("s");
    cout << format("find last \"s\" in s1 (pos): {}\n", pos);
    cout << '\n';
}
