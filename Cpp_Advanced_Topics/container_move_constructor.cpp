#include <format>
#include <string>
#include <vector>
#include<initializer_list>
#include <utility>

using std::string;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}


template <typename T>
class container {
    std::vector<T> things;

public:
    container() { // default constructor
        print("default constructor\n");
    }
    container(std::initializer_list<T> il); // initializer-list constructor
    container(const container& rhs); // copy constructor
    ~container(); // destructor
    void reset();
    container<T> operator=(const container& rhs); // copy assignment operator
    string str() const;

   // 1- we put 'noexcept' specifier to make sure that this operation will not be interruppted.
   // 1- we do not put "const" specifier in the parameter because we will be changinh the parameter(rhs). when this compiler run it will leave the rhs in a valid empty state.
    container( container&& rhs) noexcept; // move constructor. 
};

// initializer-list constructor
template <typename T>
container<T>::container(std::initializer_list<T> il) : things(il.begin(), il.end()) {
    print("initializer list constructor\n");
}

// copy constructor
template <typename T>
container<T>::container(const container& rhs) : things(rhs.things) {
    print("copy constructor\n");
}

// copy assignment operator
template <typename T>
container<T> container<T>::operator=(const container& rhs) {
    if (this != &rhs) {
        things = rhs.things;
    }

    return *this;
}

// destructor
template <typename T>
container<T>::~container() {
    print("destructor\n");
}

// reset()
template <typename T>
void container<T>::reset() {
    things.clear();
}

// str()
template <typename T>
string container<T>::str() const {
    string out{};
    if (things.empty()) {
        return "[empty]";
    }
    for (auto i : things) {
        if (out.size()) {
            out += ':';
        }

        out += format("{}", i);
    }

    return out;
}

// move constructor
template <typename T>
container<T>::container(container&& rhs) noexcept : things(std::move(rhs.things))  {
    print("move constructor\n");

}


// return of a temporary object from a function is considered as  "movable rvalue".
// because the temporary object will be destroyed anyway. So, it maks is an rvalue.
// So, whenever this faction is called what is return is an rvalue.
template <typename T>
container<T> f(container<T> o) {
    return o;
}



// see difference between this and the above one.
// here argument is rvalue reference.
template <typename T>
container<T> ff(container<T>&& o) {
    return o;
}

int main() {
    container<string> a{ "one", "two", "three", "four", "five" };// this will call initilizer-list constructor
    container<string> b{ "five", "six", "seven" }; // this will call initilizer-list constructor

    print("a: {}\n", a.str());
    print("b: {}\n", b.str());


    container c(a); // this will call copy constructor
    //container c{ a }; // same as above line
    print("a: {}\n", a.str());
    print("c: {}\n", c.str());


    // if we do this instead  of above, still copy-constructor will be called when creating object d. why?
    // => becuase, even if we cal std::move(a) and pass ot it a. the only things move does is casting "a" to movable rvalue.
    // However we do not have any constructor in our class that can can use(take advantage of) that rvalue and create d by moving. therefore copy-constructor is used.
    // to mkae this we need to write/define move constructor in our container class.
    // se we defined move constructor(container( container&& rhs) noexcept; ) in our container class.
    // now, move construtor will be called when creating d because argument (std::move(a)) is an rvalue.
    container d(std::move(a));
    print("a: {}\n", a.str());
    print("d: {}\n", d.str());



    container<string> n{ "one", "two", "three", "four", "five" };// this will call initilizer-list constructor

    // here what happens:
    // when f is called with n ==> copy constructpr is called and argument of f(container<T> o) is ititiilcatec by that copy constructor.
    // then f returns o. This return creaates remporary object and it is a r value. so we are initilizing the e with the rvalue return of function f. Therefore. move constructor is called when creating e because return of f is an rvalue.
    container e(f(n));
    print("n: {}\n", n.str());
    print("e: {}\n", e.str());


    container<string> m{ "one", "two", "three", "four", "five" };// this will call initilizer-list constructor

    // here what happens:
    // when ff is called with std::move(m) ==> it is an rvalue reference.
    // then ff returns o. This return creaates temporary object and it is a rvalue. so we are initilizing the g with the rvalue return of function ff. Therefore. move constructor is called when creating g because return of ff is an rvalue.
    // so, here in total, only a move constructor is called.
    container g(ff(std::move(m)));
    print("m: {}\n", m.str());
    print("g: {}\n", e.str());

    return 0;
}