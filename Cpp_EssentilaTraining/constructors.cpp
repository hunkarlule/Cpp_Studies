
#include <format>
#include <iostream>
#include <string>

using std::format;
using std::cout;
using std::string;


// these two are in static memeory space becuae they are definec outside of any block.
const string unk{ "unknown" };
const string clone_prefix{ "clone-" };

// interface
class Animal {
    string a_type{};
    string a_name{};
    string a_sound{};
public:
    // no return types for constrcutors.
    Animal(); // default costructor. because it has no parameters and it will initialize the object to a default state.
    Animal(const string& type, const string& name, const string& sound);
    Animal(const Animal&); // copy constructor
    ~Animal(); // destructor
    Animal& operator = (const Animal&); // copy/assignment operator.
    void print() const;
};

// implementation
Animal::Animal() : a_type(unk), a_name(unk), a_sound(unk) {
    cout << "default constructor\n";
}

Animal::Animal(const string& type, const string& name, const string& sound) : a_type(type), a_name(name), a_sound(sound) {
    cout << "constructor with arguments\n";
}

Animal::Animal(const Animal& a) {
    cout << "copy constructor\n";
    a_name = clone_prefix + a.a_name;
    a_type = a.a_type;
    a_sound = a.a_sound;
}

Animal::~Animal() {
    cout << format("destructor: {} the {}\n", a_name, a_type);
}

Animal& Animal::operator = (const Animal& o) {
    cout << "assignment operator\n";
    if (this != &o) {
        a_name = clone_prefix + o.a_name;
        a_type = o.a_type;
        a_sound = o.a_sound;
    }
    return *this;
}

void Animal::print() const {
    cout << format("{} the {} says {}\n", a_name, a_type, a_sound);
}


// note tah: object will be destroyed in the opposeite orer of  creation. In other words
// object creation-destrcutison works in FIFO preciple. Fist object created will be destroyed last.
// here we created Animal a,b, c in this order. so, they will be destroyed in c, b, a order.
int main() {
    Animal a{};
    a.print();
    
    cout << ("================================\n");
    const Animal b("goat", "bob", "baaaah");
    b.print();
    
    cout << ("================================\n");
     Animal c = b;
    c.print();
    
    cout << ("================================\n");
    a = c;
    a.print();

    cout << ("================================\n");
    cout << "end of main\n";
    return 0;
}
