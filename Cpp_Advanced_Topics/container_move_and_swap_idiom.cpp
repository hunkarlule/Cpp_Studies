/*
 Rule of THREE:
 If you define any of the these three member functions ( destructor, copy constructor or copy-assignment operator) in your class, then you NEED TO DEFINE ALL OF THREE. Of course, compiler provides as with defult versions of them. However,
 if you need to define any of them that means default version are not enough/sufficent for you and you need to define all three of them explicitly.
 In other words, if you defining any of these in your class that means you are managing some data(like allocated emmory etc). So defult versions will not be enough and you need to define all theree.

 Rule of FIVE:
 With the move semantics Tule of three becomes rule-of-five.
 If you define any of the these three member functions (destructor, copy constructor or copy-assignment operator) in your class and also yuo want moe semantics then you need to define all 5 of them(destructor, copy constructor,copy-assignment operator
 move constructor and move asigment operator)
*/




#include <format>
#include <string>
#include <vector>
#include <initializer_list>

using std::string;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

template<typename T>
class container {
    std::vector<T> things {};
public:
    container() { print("default ctor\n"); }   // default ctor
    container(std::initializer_list<T> il);    // il ctor
    container(const container& rhs);           // copy ctor
    container(container&& rhs) noexcept;       // move ctor
    ~container();
    //container<T>& operator = (const container& rhs); // copy-assignment operator 
    //container<T>& operator = (container&& rhs) noexcept; // move-assignment operator
    void reset();
    string str() const;


    // we can make assignment operator more efficient..
    // so instead of copy-assignment operator we are developing copy&swap assignment operator.
    //while implementhin this copy&assinment operator we get rid of bot copy and move assignment operators. In other words, this replaced bot of them and this is more efficient.
    container<T>& operator = ( container rhs); // copy$swap assignment operator
};

// initializer-list ctor
template<typename T>
container<T>::container(std::initializer_list<T> il) : things {il.begin(), il.end()} {
    print("initializer-list ctor\n");
}

// copy ctor
template<typename T>
container<T>::container(const container& rhs) : things {rhs.things} {
    print("copy ctor\n");
}

// move ctor
template<typename T>
container<T>::container(container&& rhs) noexcept
: things {std::move(rhs.things)} {
    print("move ctor\n");
}

// copy assignment operator
//template<typename T>
//container<T>& container<T>::operator = (const container& rhs) {
//    print("copy assignment operator\n");
//    if(this != &rhs) {
//        things = rhs.things;
//    }
//    return *this;
//}

// copy&swap assignment operator

template<typename T>
container<T>& container<T>::operator = (container rhs) {
    print("copy&swap assignment operator\n");
    std::swap(things, rhs.things); // we cal standart swap function and swap property value(things vector) of our current object and argument(rhs) object.
    return *this;
}

//// move assignment operator
//template<typename T>
//container<T>& container<T>::operator = (container&& rhs) noexcept {
//    print("move assignment operator\n");
//    if(this != &rhs) things = std::move(rhs.things);
//    return *this;
//}

// dtor
template<typename T>
container<T>::~container() {
    print("dtor\n");
}

template<typename T>
void container<T>::reset() {
    things.clear();
}

template<typename T>
string container<T>::str() const {
    string out {};
    if(things.empty()) return "[empty]";
    for(auto i : things) {
        if(out.size()) out += ':';
        out += format("{}", i);
    }
    return out;
}

int main() {
    container<string> a {"one", "two", "three", "four", "five"};
    container<string> b {"five", "six", "seven"};

    print("a: {}\n", a.str());
    print("b: {}\n", b.str());

    // here copy-assignment operator is called. However we commented the copy-assignment operator nad implemented copy&swap assignment operator. Now, see how it behaves.
    // here copy const is called when a is passed to the copy%swap member function(container<T>& operator = ( container rhs);). that is all.
    // After that destructor is called when function finishes its jon to destruc the temp object.
    b = a; 

    print("a: {}\n", a.str());
    print("b: {}\n", b.str());




    container<string> d{ "one", "two", "three", "four", "five" };
    container<string> e{ "five", "six", "seven" };

    print("d: {}\n", d.str());
    print("e: {}\n", e.str());

    // we can improve the above case more with assigning e with the  std::move(d), means with the rvalue of d.
    // however it gives error because. compiler could not decides which assignment operator to use.
    //to solve this we will even  comment  out the move-assignment operator in the container class.
    // in this case,  move const is called when std::move(d) is passed to the copy%swap member function(container<T>& operator = ( container rhs);). that is all.
    // see d is empty after this assignment it is because of the move constructor.
    e = std::move(d);

    print("d: {}\n", d.str());
    print("e: {}\n", e.str());
}
