
#include <format>
#include <chrono>
#include <thread>

using std::thread;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

void sleepms(const unsigned int ms) {
    using millis = std::chrono::milliseconds; // defining a name alias named "millis" for "std::chrono::milliseconds"
    std::this_thread::sleep_for(millis(ms));
}

void thread_func(const int n) {
    print("This is t{}\n", n);
    auto slp_dur = 500 * n;

    for (auto i = 0; i < 5; ++i) {
        sleepms(slp_dur);
        print("t{} ({}ms): loop {}\n", n, slp_dur, i + 1);
    }

    print("Finishing t{}\n", n);
}

// a thread object represents a thread of execution.
// there is one-to-one relationship between object and thread 
// One object represents one thread and thread is represented by one thread.

int main() {
    thread t1(thread_func, 1);
    thread t2(thread_func, 2);

    // see difference between  deatch() and join()
    // when we use detach then main  does not wait that other treads to be completed.
   // in other words, with detach,  t1 and t2 sruns but main(min thread) does not wait t1 and t2 to complete.
   // in this case: this print "print("main() sleep 2 secs \n");" will be printed at the top
    // in toher words, these threads runc concurrently with the main thread.
    t1.detach();
    t2.detach();

    // when we use join() then main waits that other treads to be completed then it continues its execution.
    // in other words t1, and t2 blocks the execution of main(main thread) until they finish their work.
    // in this case: this print "print("main() sleep 2 secs \n");" will wair until t1 and t2 finihes their job.
 /*   t1.join();
    t2.join();*/

    print("main() sleep 2 secs \n");
    sleepms(2000);
    print("end of main()\n");

    return 0;
}
