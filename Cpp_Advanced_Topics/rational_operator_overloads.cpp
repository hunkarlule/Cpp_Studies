#include <format>
#include <string>

using std::string;

constexpr void print(const std::string_view str_fmt, auto&&... args) {
	fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

const string nanstr{ "NAN" };

// a class for representing rational numbers
class Rational {
	int n{ 0 };
	int d{ 1 };


public:
	Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {} // default constructor
	Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) {} // copy constructor
	~Rational();
	int numerator() const { return n; };
	int denominator() const { return d; };
	Rational reduce() const; // reruce fraction
	string str() const; // return a formatted STL string
	string raw_str() const; // return a non-reduced STYL string
	Rational& operator= (const Rational& rhs); // assingment operator overload
	//Rational operator+ (const Rational& rhs) const; // + operator overload // commneted this because we implemented this as a non-member function.
	Rational operator- (const Rational& rhs) const; // - operator overload
	Rational operator* (const Rational& rhs) const; // * operator overload
	Rational operator/ (const Rational& rhs) const; // / operator overlad
};

Rational Rational::reduce() const {
	if (n == 0 || d <= 3) {
		return *this;
	}
	for (auto div = d - 1; div; --div) {
		if (n % div == 0 && d % div == 0) {
			return Rational(n / div, d / div);
		}
	}
	return *this;
}


string Rational::str() const {
	if (d == 0) {
		return nanstr;
	}
	if (d == 1 || n == 0) {
		return std::to_string(n);
	}

	auto abs_n = abs(n); // absolute value of n

	if (abs_n > d) {
		auto whole = n / d;
		auto remainder = abs_n % d;
		if (remainder) {
			return std::to_string(whole) + " " + Rational(remainder, d).str();
		}
		else {
			return std::to_string(whole);
		}
	}
	else {
		return reduce().raw_str();
	}
}

string Rational::raw_str() const {
	return std::to_string(n) + "/" + std::to_string(d);
}

Rational& Rational::operator= (const Rational& rhs) {
	if (this != &rhs) {
		n = rhs.numerator();
		d = rhs.denominator();
	}

	return *this;
}

// commneted this because we implemented this as a non-member function.
//Rational Rational::operator+ (const Rational& rhs) const {
//	//print("op+ rhs {}\n", rhs.raw_str()); // this is for testing for 14 + b case.
//	return Rational((n * rhs.d) + (d * rhs.n), d * rhs.d);
//}

Rational Rational::operator- (const Rational& rhs) const {
	return Rational((n * rhs.d) - (d * rhs.n), d * rhs.d);
}

Rational Rational::operator* (const Rational& rhs) const {
	return Rational((n * rhs.n), (d * rhs.d));
}

Rational Rational::operator/ (const Rational& rhs) const {
	return Rational((n * rhs.d), (d * rhs.n));
}


Rational::~Rational() {
	n = 0;
	d = 1;
}



Rational operator+ (const Rational lhs, const Rational& rhs)  {
	print("adding {}  + {}\n", lhs.raw_str(), rhs.raw_str()); 
	return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}


// formatter specialization
template<>
struct std::formatter<Rational> : std::formatter<unsigned> {
	template<typename FormatContext>
	auto format(const Rational& o, FormatContext& ctx) {
		return format_to(ctx.out(), "{}", o.str());
	}
};

int main() {
	Rational a{ 7 };         // 7/1
	print("a is: {} = {}\n", a.raw_str(), a);

	Rational b(25, 15);     // 5/3
	print("b is: {} = {}\n", b.raw_str(), b);

	auto c = b;     // copy constructor
	print("c is: {} = {}\n", c.raw_str(), c);

	Rational d;     // default constructor
	print("d is: {} = {}\n", d.raw_str(), d);

	d = c;          // assignment operator
	print("d is: {} = {}\n", d.raw_str(), d);

	auto& e = d;    // reference
	d = e;          // assignment to self!
	print("e is: {} = {}\n", e.raw_str(), e);
	print("d is: {} = {}\n", d.raw_str(), d);

	print("\n");
	print("a + b = {}\n", a + b);
	print("a - b = {}\n", a - b);
	print("a * b = {}\n", a * b);
	print("a / b = {}\n", a / b);


	// here we adding 14(an integer) to a rational number(b).==>  ( b + 14)
	// how this is working? ==> we overloaded + operator for class Rational as a member function but it is adding 2 rationals.
	// Here compiler sees birst operand(b) and then operator +. It looks that operator+ is overloaded. Then he tries to promote the
	// 14(integer) to rational number. It can do that becise the constructor for Rational class allows it(makes it possible). So,
	// compiler creates a temporary Rational object out of 14 using constructor(Rational(int numerator = 0, int denominator = 1)).
	// so the operation becomes b + tenmRational. Therefore following code is working.
	print("b + 14 = {}\n", b + 14);



// here we changed the operation above and did adding a rational(b) to an integer(14). => 14 + b.
// Now this code is not working and compiler gives error:  no operator matches these operands ==> operand types are: int + Rational
// why? => becuase, compiler looks first opearand(14-int) then looks if it has an + operator for int(answer is yes). However, 
// it looks the second operator, which is a Rational. So, compiler looks if it has a + operator with lfs is integer abd rhs is Rational ==> answer is no
// It laso tries to implicityl convert Rational to int so the operation could be int + int. However, it does not know how to convert a Rational to
// an int. Ao, it gives the error for the operation below( 14 + b => int + Rational)
// How to make this work? ==> Answer is to define a operator+ function that will take two operators( lfs a Rational + rhs a Rational)
// So, we need the define operator+ overload as a non-member function that will take two operators( lfs a Rational + rhs a Rational)
// Now, compiler implicitly promoting 14(integer) to a Rational(creates a temporary  Rational out of 14(int)) using the constructor.
// then it uses non=member operator+ overload function to do the addition.

// as a rule: Whenver a constrcutor allows implicit conversions like ours(	Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {})
// Tehere could be some advantage to implement overload functions(like + operator oerload in our example) as
// non-member functions.
	print("b + 14 = {}\n", 14 + b);
	return 0;
}