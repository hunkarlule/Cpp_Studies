
#include <format>
#include <utility>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

// using comparision operators to compare different type of integers may not  always
// give the expected rsults. In these caes, it is better to  use "integer-safe comparision functions" whihc inroduced by C++20.



int main() {
    int x {-3}; // a signed int
    unsigned int y{ 7 }; // an unsigned int


    // here we expect it to print to true becuase -3 < 7.
    // However it prints false. why? ==> becuase we comapring tow different types of integer(signed int and
    // unsigned int) using comparison operator(<). Unfortunately, signed int and unsigned int subtly different
    // representations of integer.
    // why this is happneing? ==> becuse default behaviour of comparison operators is to cast signed int to unsigned int
   // integers on most modern processors use two's complements notations for negative numbers.
   // this means it sets a sign bit and it uses a very large number and it's just like less than the maximum by that amount.
   // so that  number(unsigned cast ox x --see the print below that prints the unsigned cast of x.) is not less than 7 so our comparison above returns false.
    if (x < y) {
        print("true\n");
    }
    else {
        print("false\n");
    }

   // we can try to cast to x(signed int) to unsigned int and it prints a very large value. why?
   // because integers on most modern processors use two's complements notations for negative numbers.
   // this means it sets a sign bit and it uses a very large number nad it's just like less than the maximum by that amount.
   // so that  number is not less than 7 so our comparison above returns false. Because ==> standard comparison
    print("x is {}\n", (unsigned)x);

    // to overcome above issue we can use comparison functions from utlity header.
    // here we did the same comparison but we used  cmp_less() function.
    // utility header provides full-set of these functions.
    // these comparison functions to use to compare different type of integers.
    if (std::cmp_less(x, y)) {
        print("true\n");
    }
    else {
        print("false\n");
    }


}
