
#include <format>
#include <optional>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

/* Instead of all doing this we can utilize optional class from optional header file.

// this is like how to handle optinals.
// but it is a little messy.
// Instead of doing this we can handle this using optioanl header file and optional calss from that header file.
struct return_status {
    long value;
    bool have_value;
};


// here factor function returns either a lowest factor of a number or
// a false status that indicates that number is a prime.
// to do that we return a struct(return_status) from the factor func.
// return_status struct has two attributes. ==> value and has_value.
// if a number is prime then factor function will return  (return_status with value = 0 and has_value = false)
// if a number has a factor then factor function will return  (return_status with value = <lowest factor> 
// and has_value = true)
return_status factor(long n) {
    return_status rs{ 0, false };

    for (long i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            rs.value = i;
            rs.have_value = true;
            return rs;
        }
    }

      return rs;
}
*/



// we do not need this anymore when using optional class
//struct return_status {
//    long value;
//    bool have_value;
//};


//
std::optional<long> factor(long n) {
    for (long i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return i; // here we returnin a lon optional that contains value i.
        }
    }

    return {}; // here we return an empty optional(means there is no value in it)
    //return std::nullopt; // here we return an empty optional(means there is no value in it)  // same as above line.
}

int main() {
    long a{ 42 };
    auto x = factor(a);

    // after calling factor function for a number we can check its result as below:
    if (x.has_value()) { // has value() member function:  returns true if *this contains a value, false if *this does not contain a value.
        print("lowest factor of {} is {}\n", a , x.value() ); //value(0 member function returns the value contained in the optional.
    }
    else {
        print("{} is a prime number.", a);
    }



    long b{ 43 };
    auto y = factor(b);

    if (y.has_value()) {
        print("lowest factor of {} is {}\n", b, y.value());
    }
    else {
        print("{} is a prime number.\n", b);
    }



    long c{ 45 };
    auto z = factor(c);

    // even we can simplfy it like this(if (z)):
    // because therei s a bool operator overload in optonal class. so that bool operator overload return : true if *this contains a value, false if *this does not contain a value.
    if (z.operator bool()) {  // same as wrting:  if (bool(z)) or  if((bool)z) or  z.operator bool()
        print("lowest factor of {} is {}\n", c, *z); //optioanl class has overload for deference operator. So, we can find value containe it like this (*z)
        print("lowest factor of {} is {}\n", c, z.operator*());  // same as above line
        print("lowest factor of {} is {}\n", c, *(z.operator->())); // same as above line
        print("lowest factor of {} is {}\n", c, ((&z) -> value())); // same as above line
    }
    else {
        print("{} is a prime number.", c);
    }

    return 0;
}