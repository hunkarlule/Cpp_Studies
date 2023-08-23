
#include <format>
#include <tuple>
#include <vector>

// structured-bindings make it easier to work with(use) structures like pairs, tuples or any contaguous primitive structure like a struct or an array.

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

auto newline = [] { print("\n"); };

struct thing {
    int alpha{};
    double bravo{};
    const char* charlie{};
};

int main() {
    // here we initialized all of them with initializer-list.
    thing x1{ 42, 73.2, "hello, world!" }; // an instance of thing strurct
    std::tuple<int, double, const char*> x2{ 42, 73.2 , "hello, world!" }; // a tuple
    std::pair<int, double> x3{ 47, 112.5 }; // a pair

    print("struct:\n");

    // here this is structured-binding. we use auto and square([]) braces. and then we assign a value to it
    // here we assigned x1(thing struct instance) to it.
    // when this line runs wil be: a1=42, b1=73.2 and c1="hello, world!" 
    const auto [a1, b1, c1] = x1; // structured biniding. a1, b1, c1 will be initialized with values from struct x1.
    print("a1==>{}, b1==>{}, c1==>{}\n", a1, b1, c1);
    newline();

    // Instead of using structured-binding, we can get values like below. but above one(using structured-binding) is easier adn efficient.
    print("struct:\n");
    const auto a2 = x1.alpha;
    const auto b2 = x1.bravo;
    const auto c2 = x1.charlie;
    print("a2==>{}, b1==>{}, c1==>{}\n", a2, b2, c2);
    newline();


    // we also could use structured-binding with tuples  like below.
    print("tuple:\n");
    const auto [a3, b3, c3] = x2; // structured biniding. a3, b3, c3 will be initialized with values from tuple x2.
    print("a3==>{}, b3==>{}, c3==>{}\n", a3, b3, c3);
    newline();

    // Instead of using structured-binding(like above), we can get values from tuple like below. but above one(using structured-binding) is easier adn efficient.
    print("tuple:\n");
    const auto a4 = std::get<0>(x2);
    const auto b4 = std::get<1>(x2);
    const auto c4 = std::get<2>(x2);
    print("a4==>{}, b4==>{}, c4==>{}\n", a4, b4, c4);
    newline();


    // we could also use structured-binding with pairs  like below.
    print("pair:\n");
    const auto [a5, b5] = x3; // structured biniding. a5, b5 will be initialized with values from pair x3.
    print("a5==>{}, b5==>{}\n", a5, b5);
    newline();

    // Instead of using structured-binding(like above), we can get values from pairs like below. but above one(using structured-binding) is easier adn efficient.
    print("pair:\n");
    const auto a6 = std::get<0>(x3);
    const auto b6 = std::get<1>(x3);
    print("a6==>{}, b6==>{}\n", a6, b6);
    newline();


    // we can also use references with structured-biniding. like below:
    print("pair:\n");
    auto& [a7, b7] = x3; // structured biniding. a7, b7 will be references values from the pair x3.
    print("a7==>{}, b7==>{}\n", a7, b7);
    newline();

    // now we can modify the pair using a7 and b7
    // because a7 and b7 is references to the values from pair x3. changing them(a7 and b7) will change pair itself.
    a7 = 212;
    b7 = 500.9;
    print("modified pair:\n");
    auto& [a8, b8] = x3; // structured biniding. a8, b8 will be references values from the pair x3.
    print("a8==>{}, b8==>{}\n", a8, b8);
    newline();

    // we could also use structured-binding with c-arrays like below.
    print("C - array:\n");
    const int x5[] { 1, 2, 3, 4, 5 }; // initizalied x9 c-array.
    auto [a9, b9, c9, d9, e9] = x5; // structured biniding. a9, b9, c9, d9, e9 will be initialized with values from the c-array x5.
    print("a9==>{}, b9==>{}, c9==>{}, d9==>{}, e9==>{}\n", a9, b9, c9, d9, e9);
    newline();

    // we could also use structured-binding with c-strings like below.
    print("C - string:\n");
    const char x6[]{ "four" }; // initizalied x6 c-string.
    // be careful here: we initilized x6 with "four". but becuse x6 is a c-string there is a null-character('\0') at the end.
    // in other words x6 initialzied like this: x6 = "four\0"
    auto [a10, b10, c10, d10, e10] = x6; // structured biniding. a10, b10, c10, d10, e10 will be initialized with values from the c-string x6.
    print("a10==>{}, b10==>{}, c10==>{}, d10==>{}, e10==>{}\n", a10, b10, c10, d10, e10);
    newline();
    print("a10==>x{:02x}, b10==>x{:02x}, c10==>x{:02x}, d10==>x{:02x}, e10==>x{:02x}\n", a10, b10, c10, d10, e10);
    newline();

    return 0;
}
