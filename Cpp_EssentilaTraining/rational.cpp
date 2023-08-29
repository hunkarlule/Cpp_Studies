
#include <format>
#include <iostream>
#include <string>

using std::format;
using std::cout;
using std::string;

// this is in static-memory space becuase it is defined outside of all blocks.
const string nanstr{ "[NAN]" };

class Rational {
    int n{ 0 };
    int d{ 1 };
public:
    // this one is default constructor. It has parameters but all parameters have default values. so
    // this is considered as defaut constrcutor. In short, any constrcutor that can be called with passing zero
    // argument are called default-constructor.
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) { cout << "default constructor\n"; }
    Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) { cout << "copy constructor\n"; } // copy constructor.
    ~Rational();
    int numerator() const { return n; }
    int denominator() const { return d; }
    Rational reduce() const; // reduce raction
    string str() const; // return a formatted STL string
    string raw_str() const; // return a non-reduced STL string
    Rational& operator = (const Rational&); // assignment operator.
    Rational operator + (const Rational&) const; // + operator
    Rational operator - (const Rational&) const; // - operator.
    Rational operator * (const Rational&) const; // * operator
    Rational operator / (const Rational&) const; // / operator
};

Rational Rational::reduce() const {
    if (n == 0 || d <= 3) return *this;

    for (auto div = d - 1; div; --div) {
        if (n % div == 0 && d % div == 0) {
            return Rational(n / div, d / div);
        }
    }
    return *this;
}

string Rational::str() const {
    if (d == 0) return nanstr;
    if (d == 1 || n == 0) return std::to_string(n);

    auto abs_n = abs(n); // absolute value of n.

    if (abs_n > d) {
        auto whole = n / d;
        auto remainder = abs_n % d;
        if (remainder) return std::to_string(whole) + " " + Rational(remainder, d).str();
        else return std::to_string(whole);
    }
    else {
        return reduce().raw_str();
    }
}

string Rational::raw_str() const {
    return std::to_string(n) + "/" + std::to_string(d);
}

Rational& Rational::operator = (const Rational& rhs) {
    cout << "assignment operator\n";
    if (this != &rhs) {
        n = rhs.numerator();
        d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + (const Rational& rhs) const {
    return Rational((n * rhs.d) + (d * rhs.n), (d * rhs.d));
}

Rational Rational::operator - (const Rational& rhs) const {
    return Rational((n * rhs.d) - (d * rhs.n), (d * rhs.d));
}

Rational Rational::operator * (const Rational& rhs) const {
    return Rational((n *  rhs.n), (d * rhs.d));
}

Rational Rational::operator / (const Rational& rhs) const {
    return Rational((n * rhs.d) , (d * rhs.n));
}

Rational::~Rational() {
    n = 0;
    d = 1;
}

int main() {
       
    Rational a{ 7 }; // 7/1
    cout << format("a is: {} = {}\n", a.raw_str(), a.str());

    cout << "=====================================\n";
    Rational b(25, 15);     // 5/3
    cout << format("b is: {} = {}\n", b.raw_str(), b.str());

    cout << "=====================================\n";
    auto c = b;     // copy constructor
    cout << format("c is: {} = {}\n", c.raw_str(), c.str());

    cout << "=====================================\n";
    Rational d;     // default constructor
    cout << format("d is: {} = {}\n", d.raw_str(), d.str());

    cout << "=====================================\n";
    d = c;          // assignment operator
    cout << format("d is: {} = {}\n", d.raw_str(), d.str());

    cout << "=====================================\n";
    auto& e = d;    // reference ==> this is a referenece. see here no constructor(either defaulr or copy) called!
    d = e;          // assignment to self!
    cout << format("e is: {} = {}\n", e.raw_str(), e.str());
    cout << format("d is: {} = {}\n", d.raw_str(), d.str());


    cout << "=====================================\n";
    cout << '\n';
    cout << format("a + b = {}\n", (a + b).str()); // (a +b ) == returns a Rational object. that is a anonymous temp object. we call str() method on temp object!.
    cout << format("a - b = {}\n", (a - b).str());
    cout << format("a * b = {}\n", (a * b).str());
    cout << format("a / b = {}\n", (a / b).str());
}
