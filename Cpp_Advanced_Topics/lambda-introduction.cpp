
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

int main() {

    // a lambda expression is an anonoymous function that can saved in a variable to be used later. 
    // Or it can be passed or rturn from the functions and call from different contexts.
    // It is like a regular function but mobility of data.
    // in lambda experssion we have a capture list between ([]) and then we have lambda code between({}).
    // Here we defined a lambda, whihc pritns a message to console. and save it to variable x.
    // Later, we called lambda like a regualr function using variabl name and function call operator(()).
    auto x = [] {print("Hello, world!\n"); };
    x();

    // here we have lambda that returns a value.
    // note that we did not specify the reurnt type for lambda. It refers the return type from the return statement.
    auto x1 = [] { return "Hello, world!"; };
    print("{}\n", x1());


    // we cane xplicitly specify the return type for lambda using "trailin return type notation.
    // here "const char*" after the arrow is the return type of the lambda.
    // also here parantehesis(()) before the arrow are the paramater paranthesis. If you need to pass any parameters
    // to lambda you willl put them here.
    auto x2 = []() -> const char* { return "Hello, world!"; };
    print("{}\n", x2());


    // Here we are passing an argument to lambda.
    auto x3 = [](auto p) -> const char* { return p; };
    print("{}\n", x3("Hello, world!"));



    // Capture list allow us to capture and use values in lambda from the context where lamda is defined.
    // here we have a varibale called "greeting" and we want to use it in our lambda.
    // However, if we do that compiler gives error: "an enclosing-function local variable cannot be referenced in a 
    // lambda body unless it is in the capture list" 
    // To handle this we put  variable "greeting" in the capture list of the lambda like below.
    // Note that: Capture list is used to capture variables from the scope where lambda is  "defined", Not from
    // the scope where lambda is "called"!
    const char* greeting{ "Hello, world!" };
    //auto x4 = []() -> const char* { return greeting; }; // gives error
    auto x4 = [greeting]() -> const char* { return greeting; }; // fixed version.
    print("{}\n", x4());


    // here is the full syntax of a lamda expression:
    // [capture list] ==> could be empty of you can put variable names there to capture. Capture list is used to capture variables from the scope where lambda is  "defined", Not from
    // the scope where lambda is "called"!
    //  (parameters) ==> this is optional you can leave paranthesis empty(()) or you can completely remove the 
    // parameter paranthesis unless there is a return type of qualifiers  is explicily written.
    // <qualifiers> ==> optional. L ambda is default is "const" means that it can not change the variables 
    // from the capture list. If you want to change them then mark the lambda with "mutable" qualifier.
    // O
    // <return type> ==> optional. lamda refers its return type from the return statement.
    // {body} ==> where lamda code is written. mandatory.
    // [capture list](parameters) <qualifiers(like: mutable / constexpr / noexcept) > -> <return type> {body}

    // Here is a full lambda with capture list, parameter, qualifier, return type and body.
    const char* greeting2{ "Hello, world!" };
    auto x5 = [greeting2](auto p) mutable -> const char* { 
        print("{}\n", p);
        print("I am from moon!\n");
        greeting2 = "Hello, moon!";
        return greeting2; 
    }; 

    print("{}\n", x5("Hello, world!"));

    return 0;
}
