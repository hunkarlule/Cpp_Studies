
#include <format>
#include <concepts>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
	fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}


//a constraint is a seris of requirement on template parameters
//we can combine constraints with logical operators and operands.
// here requires clause specifes a concept to use as a constraint for tempalte parameters.
// <concepts> header includes useful, predifend concepts we can use when defining our constraints.
template<typename T>
	requires std::integral<T> // this means the template parameter that we will pass to this function should satisyf integral concepts.
T arg42(const T& arg) {
	return arg + 42;
}


// conatraints are logical expresiion. So we can write something like below.
// that means we bascailly do not put any constrain on template parameter.
// this is bascailly equivalent/equal to no constraint case(like commentin that line completely)
template<typename T>
requires true
T arg42_v1(const T& arg) {
	return arg + 42;
}


// we can combine constratins with boolean operators(||, &&).
// here we combined like this: std::integral<T> || std::floating_point<T>
// this means  arg42_v3 function will accpet an integral type or floating type as argument.
// if we try to pass anything else it will give a compiler error
template<typename T>
	requires std::integral<T> || std::floating_point<T>
T arg42_v2(const T& arg) {
	return arg + 42;
}

int main() {
	auto n = 7.9;
	// gives following compiler error.
	// no instance of function template matches the argument list argument types are: (double)
	// because our consrtaint clause in template function definition constraint T to be an intergral type.
	// but we passed a floating point(n) the the function. Se we get compiler error.
		 //print("The answer is [{}]\n", arg42(n));


	// test: arg42_v1

	auto n1 = 7.9;
	print("The answer is [{}]\n", arg42_v1(n1));

	auto n2 = 7;
	print("The answer is [{}]\n", arg42_v1(n2));

	// arg42_v1 is written with requires true ==> means bassically no constratins so
	// passing  const char * is not working as expected.
	auto n3	 = "7.9";
	print("The answer is [{}]\n", arg42_v1(n3)); // compiling but gicing unexpedted results(memoryleak)


	// test: arg42_v2

	auto n4 = 7.9;
	print("The answer is [{}]\n", arg42_v2(n4)); // works, because n4 is floating point type

	auto n5 = 7;
	print("The answer is [{}]\n", arg42_v2(n5)); // works, because n5 is intergral type


	// compiler error  because n6(a sonct char*) is neither floating-point nor intergral rtype.
	auto n6 = "7.9";
	//print("The answer is [{}]\n", arg42_v2(n6)); // compiler error 

}
