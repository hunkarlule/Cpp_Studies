// functor.cpp by Bill Weinman [bw.org]
// updated 2022-10-21
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

class MultBy {
    int mult{};

public:
    MultBy(int n = 1) : mult(n) {}

    // here we overloaded function call operatror("()") for  the MultBy class.
    // by doing this we can create MultBy objects and use/operate them as if they were a function.
    // this pattern is called as "functor"
    // functor gives as ability to keep the state between function calls.
    int operator() (int n) const { return mult * n; }
};

int main() {
    const MultBy times4(4);
    const MultBy times10(10);
    //const MultBy times15(15); // we commented this. isntead of this we defined times15 as a lambda expression.

    // we can  succeed same thing using lambda expresiions instead of functors:
    // here we defined a lamda expresiion and assigned it to variable times15. thr lamdsa accpests an int as an argument. It multiply the argumner by 15 adn returns theresult.
    // so we can use this lamda like a function.
    const auto times15 = [](int n) { return  n * 15; };

    // thimes4 object is a MultBy object and we pass it 5. so. multby object operatates as a function because we implemented function call operator overload, whihc accepts an int, in MultBy class.
    print("times4(5) is {}\n", times4(5)); 
    //print("times4(5) is {}\n", times4.operator()(5)); // this line is copemetly same with the above line. it gives the same result.
    print("times4(15) is {}\n", times4(15));
    //print("times4(5) is {}\n", times4.operator()(15)); // this line is copemetly same with the above line. it gives the same result.

    print("times10(5) is {}\n", times10(5));
    print("times10(15) is {}\n", times10(15));
    print("times15(5) is {}\n", times15(5));
    print("times15(15) is {}\n", times15(15));
}
