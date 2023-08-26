// typedef.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
#include <format>
#include <iostream>
#include <cstdint> // uint32_t, uint64_t defined here. spesific integers: uint32_t ==> unsigned 32 bits integer, uint64_t ==> unsigned 64 bit integer

using std::format;
using std::cout;


// typedef is very handy when type declaration becomes too long and cumbersome. Or if types may vary on different target systems.
// they makes it easy to write and read programs.
    //typedef uint32_t points_t; //here points_t is a alias for type "uint32_t" in our program
    //typedef uint64_t rank_t; // here rank_t is a alias for type "uint64_t" in our program

// moder way of creating type aliases is to use "using" keyword.
// here these two lines doing exactly the same thins that we did above suing "typedef".
// this is more preferebale to above one. use this version.
    using points_t =  uint32_t; //here points_t is a alias for type "uint32_t" in our program
    using rank_t = uint64_t; // here rank_t is a alias for type "uint64_t" in our program

struct score {
    points_t p {}; // completely same with writing: uint32_t p {}; ==> p is type of uint32_t
    rank_t r {}; // completely same with writing: uint64_t r {}; ==> r is type of uint64_t
};


int main() {

    score s { 5, 1 };
    cout << format("score s had {} points and a rank of {}\n", s.p, s.r);
}
