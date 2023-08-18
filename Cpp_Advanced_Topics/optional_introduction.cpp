
#include <format>
#include <optional>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

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

int main() {
    long a{ 42 };
    auto x = factor(a);

    // after calling factor function for a number we check return_ struct to detemine the result.
    if (x.have_value) {
        print("lowest factor of {} is {}\n", a , x.value );
    }
    else {
        print("{} is a prime number.", a);
    }



    long b{ 43 };
    auto y = factor(b);

    if (y.have_value) {
        print("lowest factor of {} is {}\n", b, y.value);
    }
    else {
        print("{} is a prime number.", b);
    }

    return 0;
}