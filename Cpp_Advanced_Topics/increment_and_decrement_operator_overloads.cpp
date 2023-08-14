#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}


class num {
    int value{};

public:
    num(int x = 0) : value{ x } {}

    int getvalue() const { return value; }
    void setvalue(int x) { value = x; }

    operator int() { return value; } //cast/conversion operator that cast a num object to int.

    num& operator++(); // pre-increment operator overload
    num operator++(int); // post-increment operator overload
    num& operator--(); // pre-idecrement operator overload
    num operator--(int); // post-idecrement operator overload
};

// As a note: post-fix versions  are a little bit more expensive than the pre-fix version. Becuase in post-fix version we are creating a temp object!.

// As we see signatures of post and pre decrement are completlty same :  num::operator-- () and num::operator-- (int)
// The only difference is that we have int keyword between parameter paranthesis in post-decrement case.
// this does not mean it is expecting an int as an argument. "int" keyword is only a way to tell you the compiler that
// this is the post-decrement version. In other words "int" keyword is  ony a placeholder/marker so that compiler can distinguish
// post and pre decrement versions.

// pre-increment operator overload: we are returning the incremented value
num& num::operator++() {
    print("pre-increment: ");
    value += 1;
    return *this;
}

// post-increment operator overload: we are returning the value before increment
num num::operator++(int) {
    print("post-increment: ");
    auto temp = *this;
    value += 1;
    return temp;
}


// As we see signatures of post and pre increment are completlty same :  num::operator++ () and num::operator++ (int)
// The only difference is that we have int keyword between parameter paranthesis in post-increment case.
// this does not mean it is expecting an int as an argument. "int" keyword is only a way to tell you the compiler that
// this is the post-inrement version. In other words "int" keyword is  ony a placeholder/marker so that compiler can distinguish
// post and pre increment versions.

// pre-idecrement operator overload: we are returning the decremented value
num& num::operator--() {
    print("pre-devrement: ");
    value -= 1;
    return *this;
}

// post-idecrement operator overload: we are returning the value before decrement
num num::operator--(int) {
    print("post-decrement: ");
    auto temp = *this;
    value -= 1;
    return temp;
}


// formatter specialization
template<>
struct std::formatter<num> : std::formatter<unsigned> {
    template<typename FormatContext>
    auto format(const num& o, FormatContext& ctx) {
        return format_to(ctx.out(), "{}", o.getvalue());
    }
};


int main() {
    num n(42);
    print("value is: {}\n", n);
    print("value is: {}\n", n++);
    //print("value is: {}\n", ++n);
    print("value is: {}\n", n);

    print("=======================================\n");

    num m(50);
    print("value is: {}\n", m);
    //print("value is: {}\n", m--);
    print("value is: {}\n", --m);
    print("value is: {}\n", m);


    return 0;
}