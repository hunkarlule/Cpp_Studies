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
    container() { print("default ctor\n"); }    // default ctor
    container(std::initializer_list<T> il);     // il ctor
    container(const container& rhs);            // copy ctor
    container(container&& rhs) noexcept;        // move ctor
    ~container();
    container<T>& operator = (const container& rhs); // copy assignment operator
    void reset();
    string str() const;

    // 1- argument could not be const becasue we will be claerinf ti. in other words. it is value will be moved and it will be in a valid empty state.
    // 2 we make this "noexcept" so this makes this operation work without any interruption.
    container<T>& operator = (container&& rhs) noexcept; // move-assignment operator
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
template<typename T>
container<T>& container<T>::operator = (const container& rhs) {
    print("copy assignment operator\n");
    if(this != &rhs) things = rhs.things;
    return *this;
}

// move-assignment operator
template<typename T>
container<T>& container<T>::operator = (container&& rhs) noexcept {
    print("move-assignment operator\n");
    if (this != &rhs) things = std::move(rhs.things);
    return *this;
}

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

template <typename T>
container<T> f(container<T> o) {
    return o;
}

int main() {
    container<string> a {"one", "two", "three", "four", "five"};
    container<string> b {"five", "six", "seven"};

    print("a: {}\n", a.str());
    print("b: {}\n", b.str());

    container<string> c{}; // this calls default constrcutor

    c = a; // this calls copy assignment operator

    print("a: {}\n", a.str());
    print("c: {}\n", c.str());



    container<string> d{}; // this calls default constrcutor

    // here wwe assigned d using std::move(a) function.  move() retutns an rvalue of a( in other words it casts a to an rvalue). However, still copy assigment operator is called when
    // assigning it to d because there is no move assignment operator defiend in the container class. To make it we need to move-assignment-operator in container class.
    // we defined move-assignemnt operator( container<T>& operator = (container&& rhs) noexcept; ) in container class. Now, move-assignment operator will be called when assigning value of a to do.
    // see hoe a bocomes emty after the assignment dute to move-assignment operator effect.
    d = std::move(a); // this calls move-assignment operator

    print("a: {}\n", a.str());
    print("d: {}\n", d.str());
}
