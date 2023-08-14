
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

int main() {
    int answer {42};
    print("The answer is {}\n", answer);
}
