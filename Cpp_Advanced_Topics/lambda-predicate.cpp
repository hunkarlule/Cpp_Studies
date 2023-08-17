
#include <format>
#include <algorithm>
#include <vector>
#include <string>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
	fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

// disp_v: display vector
void disp_v(const auto& v) {
	if (!v.size()) {
		return;
	}

	for (auto e : v) {
		print("{} ", e);
	}

	print("\n");
}

int main() {
	std::vector<int> v1{ 1, 7, 4, 9, 4, 8, 12, 10, 20 };

	//is_div4 predicate
	auto is_div4 = [](int i) { return  i % 4 == 0; };

	// count numbers that div by 4
	// here we used the is_div4 lambda as our predicate with count_if function.
	auto count = std::count_if(v1.begin(), v1.end(), is_div4); 
	print("count1 is {}\n", count);

	// instead of above we can directly write lambda expression inside of count-if, istead of defining it outside.
	// so, if pedicate code is short like this and also we do not reuse it then it could be better to write it like this
	auto count1 = std::count_if(v1.begin(), v1.end(), [](int i) { return  i % 4 == 0; }); //exactly the same with above one
	print("count1 is {}\n", count1);

	// copy numbers div by 4s
	std::vector<int> v2{};
	std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2), is_div4);
	disp_v(v2);

	// char_upper operator
	auto char_upper = [](char c) -> char {
		if (c >= 'a' && c <= 'z') {
			return c - ('a' - 'A');
		}

		else return c;
	};

	std::string s1{ "big light in sky slated to appear in east" };
	std::string s2{};
	std::string s3{};

	print("\s1: {}\n", s1);

	// transform to upper-case using char_upper operator
	std::transform(s1.begin(), s1.end(), std::back_inserter(s2), char_upper);
	print("\s2: {}\n", s2);


	// title-case operator
	// note here: in the capture list of the lambda, we are capturing another lambda and using/calling that lamda in
	// the body of this lambda.
	auto title_case = [&char_upper](char c) {
		static char prev_c{ ' ' };
		char new_c{ prev_c == ' ' ? char_upper(c) : c };
		prev_c = c;
		return new_c;
	};

	// transform to title-cae using title-case operator
	std::transform(s1.begin(), s1.end(), std::back_inserter(s3), title_case);
	print("\s3: {}\n", s3);
	return 0;
}
