
#include <format>
#include <initializer_list>
#include <vector>
#include <string>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

constexpr auto newline = [] { print("\n"); };

// print the elements of the vector
constexpr void pvec(const auto& v) {
    if (v.empty()) {
        print("[empty]\n");
    }
    else {
        for (const auto& i : v) {
            print("{} ", i);
        }
        print("\n");
    }
}

// constructors
template <typename T>
class thing {
    T v {};
    std::string state{ "undef" };

public:
    thing() : v(T{}) {
        print("default constructor\n");
        state = "zero";
    }

    thing(const T& p) : v(p) {
        print("copy constructor\n");
        state = "copied value";
    }

    thing(const std::initializer_list<T>& ilist) {
        print("initializer list: ");
        for (const auto& e : ilist) {
            print("{} ", e);
        }
        print("\n");
        const auto sz = ilist.size();
        auto pt = ilist.begin();
        if (sz > 1) {
            pt += sz / 2;
        }
        v = *pt;
        state = "list constructed";
    }

    thing(const size_t p1, const T& p2) {
        print("specific constructor: {} {}\n", p1, p2);
        if (p1 < 10) {
            return;
        }
        else {
            v = p2;
        }
        state = "specific value";
    }

    void status() const {
        print("status: {}, value {}\n", state, v);
    }
};

void initialize_this() {
    print("t1: ");
    // here t1 initialized with empty initializer-list. For classes, emppty initializer-list initializtion will call/use the defult constructor for initizalization.
    thing<int> t1 {};
    t1.status();
    newline();

    print("t2: ");

    // this will call/use initializer-list constructor(thing(const std::initializer_list<T>& ilist) ) from the thing calss.
    thing<int> t2{ 7 };
    //thing<int> t2{ 7, 12, 8, 14, 15, 2 };
    t2.status();
    newline();
    
    print("t3: ");
    // here we used normal(()) braces when  initialzing t3. this will call/use the copy contrcutor(thing(const T& p) : v(p)) for initizalization.
    thing t3(42);
    t3.status();
    newline();
  

    // this will call/use initializer-list constructor(thing(const std::initializer_list<T>& ilist) ) from the thing calss.
    print("t4: ");
    thing<int> t4{ 1, 2, 3, 4, 5 };
    t4.status();
    newline();

    // this will call/use initializer-list constructor(thing(const std::initializer_list<T>& ilist) ) from the thing calss.
    print("t5: ");
    thing<int> t5{ 1, 2 };
    t5.status();
    newline();

    // here we used normal(()) braces when  initialzing t6.  we have a constructo(we called it specific constructor) in thing class. So that constructor(thing(const size_t p1, const T& p2) ) will be called/used for initizalization.
    print("t6: ");
    thing<int> t6(1, 2);
    t6.status();
    newline();

    // here we used normal(()) braces when  initialzing t6.  we have a constructo(we called it specific constructor) in thing class. So that constructor(thing(const size_t p1, const T& p2) ) will be called/used for initizalization.
    print("t7: ");
    thing<int> t7(15, 2);
    t7.status();
    newline();
    
}

int main() {
    // here x is list-initilized with an empty list. curly-braces({}) are called "initilization list".
    // this({}) is considered the best way to initilize a simple scaler.
    // and emty list({}) is a specail case. this will "zero" initialize any primitive value.
    int x {}; // here x will be initilized with  zero(0).
    print("x is {}\n", x);

    int x1{5}; // here x1 will be initilized with  5. this is called list initialization.
    print("x1 is {}\n", x1);

    // alternative to above list-initializetion is below old-style(copy initialization)
    int x2 = 5; // copy initialization. it takes five. makes a copy of it and puts it into x2.
    print("x2 is {}\n", x2);

    // copy-initialization is same as list-initialization in practice/on-surface. however, it is different.  copy-initizalization is inherited from C and it hasa flaw in it.
    // see the following example: we tryr to initialize int x3 with 5.1. it is not compatibel value with the integer.
    // However it will compile and run. what happnes is this: there is a conversion here( called narrowing conversion).So, 5.1 is converted ot integer as 5. this is due to copy-initialization of C language.
    int x3 = 5.1; // copy initialization. 
    print("x3 is {}\n", x3);


    // however if a try to do the same thing with  list-initialization, the compiler will give an error: "conversion from 'double' to 'int' requires a narrowing conversion"	
    // here we tried to initialize  int x4 with 5.1 using list-initialization. We got error because initializer list does not allow implicit  narrowing type conversion.
    // therefore, initilizer-list initializtion is best and safest for initilizing primitive type likes int, double etc.
        //int x4 { 5.1 }; // list initialization.  -- error.
        //print("x4 is {}\n", x4);

    // here be carefuL: this will not initilize x5 to "empty string"!
    // x5 will be a null-pointer. and null-pointer is bad becuase null-pointer could point to anything. and this lead to memory leaks and bugs.
    // So here this zero(empty) initialization list initialize the value(x5) correctly but this primitive value is not a string. It is a pointer to a character.
    // So, if we want an empty string we need to give empty-string in the initializer list(as x6)
        //const char* x5{};
        //print("x5 is {}\n", x5);

    const char* x6{ "" };
    print("x6 is {}\n", x6);

    // here x7 is a vector of int and we initilizaed  the vector usinn  zero(empty) initializer list.
    std::vector<int> x7 {}; // this will create/initilzaie an emty vector.
    pvec(x7);

    // here x8 is a vector of int and we initilizaed  the vector using an initializer list.
    std::vector<int> x8 {5, 7}; // this will initalize a vector with 2 values: 5, 7
    pvec(x8);


    // here be careful about this. instead of curly({}) braces we used normal(()) braces to initialize the vector 
    // Nowe we get a completly a different result. we get a vecto of 5 elemetns( all of them 7)
    // because it calls a different constructor. first paramater is number-of-elements and second paremeter is value to put in the vector.
    std::vector<int> x9 (5, 7 ); // this will initalize a vector with 5 7s:  7,7,7,7,7
    pvec(x9);

    initialize_this();
}
