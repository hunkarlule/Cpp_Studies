
#include <format>
#include <concepts>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

// here is a template function that takes an argumenr. Adds 42 to it and returns it
template<typename T>
T arg42(const T& arg) {
    return arg + 42;
}


// here is the same template function with constratins added.
// from the concepts headr we added two named constraints(std::integral and std::floating_point)
// to the our template using requires keyword. note that we used ||(logical or) when adding them together.
// this basically says: The template function requires T to be "an intergral type" or "floating point type"
// to run. Otherwise, compiler will give us an error.
template<typename T>
requires std::integral<T> || std::floating_point<T>
T arg42_with_constraints(const T& arg) {
    return arg + 42;
}

// Even we can define our own concepts and use ti as constraints.
// Here we defined a custom concept called Numeric and we are suing it as constraint in  arg42_with_constraints1
// template function.
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template<typename T>
requires Numeric<T> // we need to use T here because Numeric is a template concept.
T arg42_with_constraints1(const T & arg) {
    return arg + 42;
}


// Even we can simpify our template function as below using Numeric concept we defined above.
template<Numeric T>
T arg42_with_constraints2(const T& arg) {
    return arg + 42;
}


// Even we can simpify our template function as below using Numeric concept  with abbreviated templates
// like below
// Note that we put aout constraint/concept  in the argumenr parantesis in this case.
auto arg42_with_constraints3(const Numeric auto& arg) {
    return arg + 42;
}



int main() {
    // here template function workd well with floating point number
    auto n = 7.9;
    print("The answer is {}\n", arg42(n));

    //template function works also well with integer
    auto n1 = 7;
    print("The answer is {}\n", arg42(n1));


    // here n2 is a const cahr*(const char pointer). So we are passing it tothe template function.
    // In the function we are adding 42 to it. Tham makes the pointer to point to an arbitrary place in the memory that
    // does not belong to us. So, this is a memory leak and caising issue when we run the program. 
    // Ity doees not produce a meningful result.
    auto n2 = "7.9";
    print("The answer is [{}]\n", arg42(n2)); // note workin properly. cauign memory leak
    print("The answer is {}\n", arg42(n2)); // note workin properly. cauign memory leak

    // we calling  arg42_with_constraints wiht n3(a floating point type) and it works as expected.
    auto n3 = 7.9;
    print("The answer is {}\n", arg42_with_constraints(n3));

    // we calling  arg42_with_constraints wiht n4(an intergal type) and it works as expected.
    auto n4 = 7;
    print("The answer is {}\n", arg42_with_constraints(n4));


    //we calling  arg42_with_constraints wiht n5(a const char *) and compiler gives an error to us.
    // it gives error:  "no instance of function template matches the argument list argument types are: (const char *)"
    // On the conrtaty to previous version(arg42) we catch the issue at the compile time and we do not have a memory leak.
    // because n5 does not satisfy the constraints(requires std::integral<T> || std::floating_point<T>) we put in the
    // template func definition.
    auto n5 = "7.9";
    //print("The answer is [{}]\n", arg42_with_constraints(n5)); // compilation error
    //print("The answer is {}\n", arg42_with_constraints(n5)); // compilation error


    // Here,  arg42_with_constraints1 works as expected.

     // we calling  arg42_with_constraints1 wiht n3(a floating point type) and it works as expected.
    auto n6 = 7.9;
    print("The answer is {}\n", arg42_with_constraints1(n6));

    // we calling  arg42_with_constraints1 wiht n4(an intergal type) and it works as expected.
    auto n7 = 7;
    print("The answer is {}\n", arg42_with_constraints1(n7));

    //we calling  arg42_with_constraints1 wiht n5(a const char *) and compiler gives an error to us.
    // it gives error:  "no instance of function template matches the argument list argument types are: (const char *)"
    // On the conrtaty to previous version(arg42) we catch the issue at the compile time and we do not have a memory leak.
    // because n5 does not satisfy the constraints(requires std::integral<T> || std::floating_point<T>) we put in the
    // template func definition.
    auto n8 = "7.9";
    //print("The answer is [{}]\n", arg42_with_constraints1(n8)); // compilation error
    //print("The answer is {}\n", arg42_with_constraints1(n8)); // compilation error



  // Here,  arg42_with_constraints2 works as expected.

     // we calling  arg42_with_constraints2 wiht n3(a floating point type) and it works as expected.
    auto n9 = 7.9;
    print("The answer is {}\n", arg42_with_constraints2(n9));

    // we calling  arg42_with_constraints2 wiht n4(an intergal type) and it works as expected.
    auto n10 = 7;
    print("The answer is {}\n", arg42_with_constraints2(n10));

    //we calling  arg42_with_constraints2 wiht n5(a const char *) and compiler gives an error to us.
    // it gives error:  "no instance of function template matches the argument list argument types are: (const char *)"
    // On the conrtaty to previous version(arg42) we catch the issue at the compile time and we do not have a memory leak.
    // because n5 does not satisfy the constraints(requires std::integral<T> || std::floating_point<T>) we put in the
    // template func definition.
    auto n11 = "7.9";
    //print("The answer is [{}]\n", arg42_with_constraints2(n11)); // compilation error
    //print("The answer is {}\n", arg42_with_constraints2(n11)); // compilation error


      // Here,  arg42_with_constraints3 works as expected.

     // we calling  arg42_with_constraints3 wiht n3(a floating point type) and it works as expected.
    auto n12 = 7.9;
    print("The answer is {}\n", arg42_with_constraints3(n12));

    // we calling  arg42_with_constraints3 wiht n4(an intergal type) and it works as expected.
    auto n13 = 7;
    print("The answer is {}\n", arg42_with_constraints3(n13));

    //we calling  arg42_with_constraints3 wiht n5(a const char *) and compiler gives an error to us.
    // it gives error:  "no instance of function template matches the argument list argument types are: (const char *)"
    // On the conrtaty to previous version(arg42) we catch the issue at the compile time and we do not have a memory leak.
    // because n5 does not satisfy the constraints(requires std::integral<T> || std::floating_point<T>) we put in the
    // template func definition.
    auto n14 = "7.9";
    //print("The answer is [{}]\n", arg42_with_constraints3(n14)); // compilation error
    //print("The answer is {}\n", arg42_with_constraints3(n14)); // compilation error

}
