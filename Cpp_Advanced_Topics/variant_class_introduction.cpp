
#include <format>
#include <string_view>
#include <vector>
#include <variant>

// varian class is a type-safe tagged union
// a varian object may hold different values of different types but  one at a time.
// also, each value should/must fit in the same allocated memory space.

using std::string_view;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

constexpr auto newline = [] {print("\n"); }; // a lamda expressin as a constexpr.

//animal class
class Animal {
    string_view _name{};
    string_view _sound{};

public:
    Animal() = delete;
    Animal(string_view n, string_view s): _name{n}, _sound{s}{}
    
    void speak() const {
        print("{} says {}\n", _name, _sound);
    }

    void sound(string_view s) {
        _sound = s;
    }
};

class Cat : public Animal {
public:
    Cat(string_view n) : Animal(n, "meowwwww!") {}
};

class Dog : public Animal {
public:
    Dog(string_view n) : Animal(n, "arf arf!") {}
};

class Wookie : public Animal {
public:
    Wookie(string_view n) : Animal(n, "grrrrraarrgghhhh!") {}
};

struct animal_speaks {
    void operator()(const Dog& d) const { d.speak(); }
    void operator()(const Cat& c) const { c.speak(); }
    void operator()(const Wookie& w) const { w.speak(); }
};


int main() {
    // std::variant<Cat, Dog, Wookie>; ==> this varian type and in its template parameters there are three different types(Cat, Dog, Wookie). means that can hold one of these objects(varian objects).

    using v_animal = std::variant<Cat, Dog, Wookie>; // a type alias definition
    // here we defined a vector of v_animal(in other words vector of "std::variant<Cat, Dog, Wookie>")  ==> in this varian type  each one has an index: Cat ==>0 , dog ==>1, Wookie ==> 2.
    // we put 2 cats, 1 dog and 1 wookie in the vector. Becasue it is a vector of v_animal, which is a variant type and that can be a dog, a cat or a wookie.
    // each of these objects(Cat("Hobbes")) will be used to constrcut a variant oblect and pets will hold that variant objects.
    std::vector<v_animal> pets{ Cat("Hobbes"), Dog("Fido"), Cat("Bill"), Wookie("chewie") };

    //  same as bove line. we can write this instead of using name-alias but this becomes cluttered. 
    //std::vector<std::variant<Cat, Dog, Wookie>> pets{ Cat("Hobbes"), Dog("Fido"), Cat("Bill"), Wookie("chewie") };

    print("--get method\n");
    for (const v_animal& a : pets) {
        auto idx = a.index(); // index method retuns the index of the type for the object("std::variant<Cat, Dog, Wookie>")  ==> in this varian type  each one has an index: Cat ==>0 , dog ==>1, Wookie ==> 2.)
        if (idx == 0) { // means it is cat.
            get<Cat>(a).speak(); // get method return to reference to object( in this case to Cat) that contained in the variant.
        }
        if (idx == 1) {
            get<Dog>(a).speak();
        }
        if (idx == 2) {
            get<Wookie>(a).speak();
        }
    }

    newline();

    print("-- get_if method\n");
    for (const v_animal& a : pets) {
        if (const auto& o = get_if<Cat>(&a); o) { //get_if method gets a point to varian object and then retuns a pointer to actual object( CAt, Dog, or Wookie) that is contained in the variant or a nullptr.
            o->speak();
        }
        else if (const auto& o = get_if<Dog>(&a); o) {
            o->speak();
        }
        else if (const auto& o = get_if<Wookie>(&a); o) {
            o->speak();
        }
    }

    newline();
    print("-- visit method\n"); 
    for (const v_animal& a : pets) {
        // here we passed a animal_speak() object and varian object to visit function.
        std::visit(animal_speaks{}, a); // visit() asspect a polymorphic functor. So visit will call its function call operator with the object we specified in the second parameter.
    }
    return 0;
}

