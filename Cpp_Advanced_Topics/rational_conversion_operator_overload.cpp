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

	// this is a an operator overload to cast/convert a Rational obkect to a string
	// see that this func  return a string but as we see we did not put any return type in func definition/decleration 
	// this is becuase function name already implies that  what will be the return of the function
	// see we commneted the return part of the function. ==> on the contrary if we open the comment adnd put the return type compiler will give us error: ==> "return type may not be specified on a conversion function"
	// /*std::string*/  operator string() { return str(); } 

	// also we can write the above conversion funcion(operator string() { return str(); } ) like below.
	// because it is returning a string, the compiler will figure it out that auto stands for string and it will create string conversion operator for us.
	operator auto() { return str(); }
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

Rational::~Rational() {
	n = 0;
	d = 1;
}

Rational operator+ (const Rational lhs, const Rational& rhs)  {
	print("adding {}  + {}\n", lhs.raw_str(), rhs.raw_str()); 
	return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator- (const Rational& lhs, const Rational& rhs)  {
	return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
	return Rational((lhs.numerator() * rhs.numerator()), (lhs.denominator() * rhs.denominator()));
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
	return Rational((lhs.numerator() * rhs.denominator()), (lhs.denominator() * rhs.numerator()));
}


// formatter specialization
template<>
struct std::formatter<Rational> : std::formatter<unsigned> {
	template<typename FormatContext>
	auto format(const Rational& o, FormatContext& ctx) {
		return format_to(ctx.out(), "{}", o.str());
	}
};

void printString(const std::string& s) {
	print("The string is {}\n", s);
}


// conversion operator allow us to determine how our custom types are casted/converted to other types.
int main() {
	Rational a{ 4, 3 };  // 1 1/3

	print("a + 20 = {}\n", a + 20);
	print("a + 20 = {}\n", a - 20);
	print("a + 20 = {}\n", a * 20);
	print("a + 20 = {}\n", a / 20);

	print("\n");

	print("20 + a = {}\n", 20 + a);
	print("20 - a = {}\n", 20 - a);
	print("20 * a = {}\n", 20 * a);
	print("20 / a = {}\n", 20 / a);

	string s{ "Rational is " };
    // this does not work. Compiler gives "no operator matches these operands ==> operand types are: std::string += Rational" error.
	// bescailly it says no += operator overload that accept string  as its firts(lhs) operand and Rational as its second(rhs) operand.
	// what is solution this? ==> answers: to overload a conversion operator for our Rational class to convert/cast a Rational object to string.
	// we defined operator string() conversion overlaod for the Rational class and now felow code is working.
	// how  this is wroking? ==> for += ooperator, the compiler expects a string for the rhs. But it is a rational. so, compiler looks for to convert the rhs(Rational) to a string. It looks for Rational class and see there is operator string() oevload.
	// so the compiler implicitly converts/cast rhs(a) to string using that cast/conversion operator.
	s += a;

	print("{}\n", s);

	// We have a printString function that takes a string argument. However we passed it a Ratinonal object(a). It is woking fine. But, how this is  working?
	// The compiler sees that we passed a Rational(a) to printtring function, whihc expects a string. So, compiler tries to cast Rational(a) to a string. So, it sees tah we have
	//  operator string() overload function in the Rational class. So it impicitly converts a to a string using that overload. Therefore, the following is working.
	printString(a);

	return 0;
}