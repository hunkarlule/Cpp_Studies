
#include <format>
#include <iostream>
#include <string>
#include <map>
#include <functional>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

const char prompt(const char* p) {
    auto char_upper = [](char c) -> char {
        if (c >= 'a' && c <= 'z') {
            return c - ('a' - 'A');
        }
        else {
            return c;
        }
    };
    
    std::string r {};
    print("{} > ", p);
    getline(std::cin, r, '\n');

    if (r.size() < 1) {
        return '\0';
    }
    else if(r.size() > 1) {
        print("Response is too long!\n");
        return '\0';
    }
    else {
        return char_upper(r.at(0));
    }
}

bool jump(const char select) {
    // here we creaate a type-alias named "jumpfunc". it is
    // a pointer to a function returning void and accepting no parameters.
    using jumpfunc = void(*)();
    //typedef void (*jumpfunc)(double); // same as above.


    // We can define same alies as follows.
    // using jumpfunc = std::function<void()>; //std::function requires the <functional> header
    

    // create a map object called  jumpmap
    const std::map<char, jumpfunc> jumpmap{
        {'A', []() {print("func A\n"); }},
        {'B', []() {print("func B\n"); }},
        {'C', []() {print("func C\n"); }},
        {'D', []() {print("func D\n"); }}
    };

    // Searches the container for an element with a key equivalent to passed parameter(select in this case) 
    // and returns an iterator to it if found, otherwise it returns an iterator to map::end.
    const auto it = jumpmap.find(select);
    if (it != jumpmap.end()) {
        // the iterator we got from find method points to an elemend from the jumbmap.
        // each element in jumpmap is a pair(whihc has charater at its first object- key 
        // and a function pointer as its second object - this is value)
        // so with this: it->second we accessing to the second object- value of the pair.
        // becuase it is a fuction pointer we use function call operator(()) to call the function pointed by it.
        it->second(); 
        //(*it).second(); // same as above line.
    }
    else {
        print("Invalid response!\n");
        return false;
    }
    return true;
}



int main() {
    const char* pstr{ "what to do? (A/B/C/D/X)" };

    for (auto key = prompt(pstr); key != 'X'; key = prompt(pstr)) {
        if (key) jump(key);
    }
    print("Bye!\n");
}
