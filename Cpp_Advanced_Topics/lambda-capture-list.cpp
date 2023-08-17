
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

int main() {
    const char* greeting {"Hello, earthlings"};

    // compiler gives this error for the below line: "an enclosing-function local variable cannot be referenced 
    // in a lambda body unless it is in the capture list" ==> that means: "greeting" varibale is outside of lexical 
    // scope of the lambda and, therefore that can not be used in lambda. Unless,  we list it in lambda capture list([]).
        //auto x = []{ return greeting; };
        //print("{}\n", x());

    // to fix the above, we list the "greeting" varibale in the lambda's capture list.
    //shortly, capture list allows lambda to capture symbols/varibales from outside its lexical scope and use them inside the lambda.
    auto x = [greeting] { return greeting; }; // fixed version
    print("{}\n", x());

    // lambda can capture multiple variables/symbols
    const char* greeting1{ "Hello" };
    const char* greeting2{ "earthlings" };

    // Note that: capture list default to "copy", like function parameters. this means,  items in capture list (greeting1, greeting2 in the folloing example)
    // create temporary objects to be used withing the scope of the lambda.
    auto x1 = [greeting1, greeting2] { return std::format("{}, {}", greeting1, greeting2); }; // fixed version
    print("{}\n", x1());

    // Instead of capturing with copy, we can capture by reference.
    // Note that: if we capture by reference we can change their values in the lambda.
    // Even after lamda runs and finishes, the chnge will be persistent after/outside of the lambda.
    auto x2 = [&greeting1, &greeting2] { 
        greeting2 = "world";
        return std::format("{}, {}", greeting1, greeting2); }; // fixed version
    print("{}\n", x2());


    // Instead of capturing symbols by-one-one, we can capture all symbols with "=" sign in capture list like below. But, note that this again will capture all symbols "by copy"
    auto x3 = [=] { return std::format("{}, {}", greeting1, greeting2); }; // fixed version
    print("{}\n", x3());


    // Instead of capturing symbols by-one-one, we can capture all symbols with "&" sign in capture list like below. But, note that this again will capture all symbols "by reference"
    auto x4 = [&] { return std::format("{}, {}", greeting1, greeting2); }; // fixed version
    print("{}\n", x4());

    // Note: it is better to capture symbols one-by-one with using their name instead of capturing all symbolw with = or & symbol.
}
