// constraints.cpp by Bill Weinman [bw.org]
// updated 2022-08-23
#include <format>
#include <concepts>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
T arg42(const T& arg) {
    return arg + 42;
}

// instread of above we can define our own concept
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// then we can use that concept like this when defining the template functions
template<typename T>
    requires Numeric<T>
T arg42_v1(const T & arg) {
    return arg + 42;
}

// or we can use that concept like this when defining the template functions
template<Numeric T>
T arg42_v2(const T& arg) {
    return arg + 42;
}

// or even we can use the concept in abbreivated function template synyax.
auto arg42_v3(const Numeric auto& arg) {
    return arg + 42;
}

 // even we can define concepts that do not rely on concepts library.
// here we defined a concept that says type T needs to a type that can be 1 or can be multiplied by 1.
// even we can comment out the <concepts> include becuase Numeric1 concept does not rely on it.
template <typename T>
concept Numeric1 = requires(T a) {
    a + 1;
    a * 1;
};


auto arg42_v4(const Numeric1 auto& arg) {
    return arg + 42;
}

int main() {
    auto n = 7.9;
    print("The answer is [{}]\n", arg42(n));

    // testing Numeric concept
    auto n1 = 7.9;
    print("The answer is [{}]\n", arg42_v1(n1));

    auto n2 = 7.9;
    print("The answer is [{}]\n", arg42_v2(n2));


    auto n3 = 7.9;
    print("The answer is [{}]\n", arg42_v3(n3));

    // testing Numeric1 concept

    // works fine because we passed n4(a floating point). 
    // so a floating point can be added 1 and multiplied 1. So it satisfies Numeric1 concept.
    auto n4 = 7.9;
    print("The answer is [{}]\n", arg42_v4(n4));

    // compilation error because we passed n5(a const char *). 
    // so a const char * cannot be added 1 and cannot be multiplied 1. So it DOES NOT satisfy Numeric1 concept.
    auto n5 = "7.9";
    //print("The answer is [{}]\n", arg42_v4(n5)); // compiler error!

    return 0;
}
