
#include <format>
#include <compare>

// three-way comparison operator(spaceshiip oerator)(<=>) is to provide a unified comparison operators for objects.
// spaceship operator(<=>) is not used to compare values. Rather it is used a a comparison operator in a class.
// 

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

class num {
    int a;
    
public:
    num() = delete;
    constexpr num(const int& n) : a(n) {}
    constexpr int get() const { return a; }
    // here we ahve all conparison operator overloads for class num and they are working as expected.
    // however we ca repalce all this fuctions(operator overloads) with one operator(spaceship operator)
        //constexpr bool operator == (const num& rhs) const { return a == rhs.a; }
        //constexpr bool operator != (const num& rhs) const { return !(a == rhs.a); }
        //constexpr bool operator < (const num& rhs) const { return a < rhs.a; }
        //constexpr bool operator > (const num& rhs) const { return rhs.a < a; }
        //constexpr bool operator <= (const num& rhs) const { return !(rhs.a < a); }
        //constexpr bool operator >= (const num& rhs) const { return !(a < rhs.a); }

    // here we relaced all obave with spaceship operator.
    // spaceship operator(<=>) is a strong ordering object from compare header.
    // we can not usei ti like an regular/normal operator.
    // it is only aimed to be used as a comparison operator in a class.
    // this uses a feature called "rewritten expressions"
    // when we ste it default like below then we do not need all other comparison operators.
    // Even we do not need non-member comparison operators.
    // we we caommented all comparison operators and only put this spaceship operator overload and
    // our code(see main)is still wotking as expected.
    // this workw out-of-box for simple scaler types like our num class(integer wrapper)
    // for complex types we only need to add == operator to our class.
    auto operator <=>(const num& rhs) const = default;
};

int main() {
    num n {42};
    print("The num is {}\n", n.get());

    constexpr num na {7};
    constexpr num nb {7};
    constexpr num nc {42};
    //static assert: Performs compile-time assertion checking
    // if the condition is false provided as an argument then compiler will thor an error.
    static_assert(na < nc);
    //static_assert(na > nc); // error static assertion failed. because an > nc is false.
    static_assert(nc > na);
    static_assert(na == nb);
    static_assert(na <= nb);
    static_assert(na <= nc);
    static_assert(nc >= na);
    static_assert(na != nc);
    print("done.\n");
}
