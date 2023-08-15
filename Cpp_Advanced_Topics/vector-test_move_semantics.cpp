#include <format>
#include <vector>
#include <string>
#include <utility>

// we have move(obj) template function in utility header file.
//the move function "returns an rvalue reference to arg."
// so we can use it with the move semantics. In other words, move(obj) function tells the compiler to treat the
// obj as a moveable rvalue. move looks(is a) function call but it actually works more like a type-cast.

using std::vector;
using std::string;

constexpr void print(const std::string_view str_fmt, auto&&... args) {
	fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
 }

void disp_v(auto& v, const string& label = "") {
	if (!label.empty()) {
		print("{}: ", label);
	}

	if (v.empty()) {
		print("[empty]");
	}
	else {
		for (auto& s : v) {
			print("{} ", s);
		};
	}
	print("\n");
}

// we can also use move semantics for swap operation.
// this is the swap function in our namespace "scope". int other words our name space(its is nameless)
// to refer it we need to use :: operator before swap function calls, so, to tell the compiler that we are calling this
// swap function.
// here how this swap works:
// -- first we created temp object(_temp) and ititialized it with move of a. this is a move-constrcutor, not copy-constructor.
// -- then we assigned of b to a with move. this assignment is a move-assignment istead of copy-assignment.
// -- then we assigned of _tmp to b with move. this assignment is a move-assignment istead of copy-assignment.
// because all these are move operations they are pretty fast compered to copy operations.
template <typename T>
void swap(T& a, T& b) {
	print("::swap\n");

	T _tmp(std::move(a));
	//disp_v(a, "a");
	//disp_v(b, "b");
	//disp_v(_tmp, "a_tmp");

	a = std::move(b);
	//disp_v(a, "a");
	//disp_v(b, "b");
	//disp_v(_tmp, "a_tmp");

	b = std::move(_tmp);
	//disp_v(a, "a");
	//disp_v(b, "b");
	//disp_v(_tmp, "a_tmp");
}


int main() {
	vector<string> v1 = {"one", "two", "three", "four", "five"};
	vector<string> v2 = {"six", "seven", "eight", "nine", "ten"};

	disp_v(v1, "v1");
	disp_v(v2, "v2");

	//v2 = v1; // here we copied the content of the v1 to v2. "=" is tretad as copy-assignment operator.

	/*
	// here we moved content of v1 to to v2. 
	// that means after running this line content of v1 will be moved v2 and v1 will be empty.
	// the advantage of this is that" it saves us all the overhead/cost of copying.
	// After move. previous content of v2 is is destroyed before the move and it replaced by content of v1.
	// also v1 stay in a valid empty state.
	*/
	//v2 = std::move(v1); 

	disp_v(v1, "v1");
	disp_v(v2, "v2");


	// here we used ::(scope resolution operator) before swap call to make sure that we are 
	// calling swap function that we created in our scope above.
	// becuase there is also another swap function in standard library in utility headr. so we need to put :: this to make sure that we
	// are calling our own swap function.
	::swap(v1, v2); //// this call our swap function from our scope(name-space).
	//std::swap(v1, v2); // this call the swap function from standar library.
	disp_v(v1, "v1");
	disp_v(v2, "v2");

	return 0;
}