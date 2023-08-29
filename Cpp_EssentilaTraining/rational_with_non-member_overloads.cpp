
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
    //Rational operator + (const Rational&) const; // + operator // we implemented this a non-member function.
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

//+ operator as a member-function.
//Rational Rational::operator + (const Rational& rhs) const {
//    return Rational((n * rhs.d) + (d * rhs.n), (d * rhs.d));
//}


//+ operator as a non- member-function.
Rational operator + (const Rational& lhs, const Rational& rhs) {
    return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), (lhs.denominator()* rhs.denominator()));
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

    cout << "=====================================\n";
    // Initally we implemented  + operator as a member function. This is wotking.
    // compiler looks  first operand(b) is Rational. So, it looks for + operator in Rational class.
    // + operator expecting a Rational as rhs  but we passed an int(+). so compiler tries to convert/create a temp Rational
    // object out-of 14. Luckily, default constructor allows it. So this becomes like this: (b + temp Rational).str().
    // Therefore this is working.
    cout << format("b + 14 = {}\n", (b + 14).str());


    cout << "=====================================\n";
    // Below code is the same of the abov one. We tried to add  14 and b togeher. The difference is
    //  14 is the first operator. This is not working. WHY? ==>
    // Initally we implemented  + operator as a member function. 
    // compiler looks  first operand(14) is int. So, compiler looks for int operator for primitive int type.
    // + operator for primitive int type expecting an int as rhs  but we passed an Rational(b). 
    // so compiler tries to convert/create an int  out-of Rational b object.. However, there is nothing in Rational class
    // that allows/tells the compielr how to convert an int from Rational object. Therefore this is  NOT working.
    // What is the solutuon for this issue? ==> Answer: Implement + operator as a non-member function.
    // We implemented + operator as a non-member function. No compiler can convert int either on the lhs or rhs ro rational 
    // do the addition.
    cout << format("14 + b = {}\n", (14 + b).str());
}
