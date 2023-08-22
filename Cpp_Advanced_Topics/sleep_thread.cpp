
#include <format>
#include <chrono>
#include <thread>

using std::chrono::steady_clock; // provides us with chrono time point object
using std::chrono::duration; // provides us with chrono duration object
using std::this_thread::sleep_for; 
using std::this_thread::sleep_until;

using namespace std::chrono_literals; // we use this for seconds and miliseconds literals

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}


int main() {
    print("let's wait a bit...\n");

    auto t1 = steady_clock::now();

    print("sleep for 2.5 seconds\n");
    // this func is from thread header. 
    // It takes a duration and makes thread sleep during that duration.
    // this function operates on current thread
    sleep_for(2s + 500ms);

    print("sleep for 3 seconds\n");
    // this func is from thread header. 
    // It takes an end-time on and makes thread sleep until that time.
    // this function operates on current thread
    sleep_until(steady_clock::now() + 3s);

    duration<double> dur1 = steady_clock::now() - t1;
    print("total duration: {:.05}\n", dur1);

    return 0;
}


