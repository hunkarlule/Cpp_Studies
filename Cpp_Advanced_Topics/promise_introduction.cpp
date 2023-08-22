
#include <format>
#include <list>
#include <chrono>
#include <future>

using std::chrono::steady_clock;

using launch = std::launch;
using secs = std::chrono::duration<double>;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

struct prime_time {
    secs dur{};
    uint64_t count{};
};

void count_primes(const uint64_t& max, std::promise<prime_time> pval) {
    prime_time ret{};
    constexpr auto isprime = [](uint64_t n) {
        for(uint64_t i {2}; i < n / 2; ++i) {
            if(n % i == 0) return false;
        }
        return true;
    };
    uint64_t start {2};
    uint64_t end {max};
    auto t1 = steady_clock::now();
    for(auto i = start; i <= end ; ++i) {
        if(isprime(i)) ++ret.count;
    }
    ret.dur = steady_clock::now() - t1;

    // here we set that value for promise object that we passed to function.
    // the value we seet is a prime_time object.
    pval.set_value(ret);
}

int main() {
    constexpr uint64_t max_prime{ 0x1FFFF };  // largest uint64_t is 0xFFFFFFFFFFFFFFFF
    constexpr size_t num_threads{ 15 };
    std::list<std::future<prime_time>> swarm; // list to hold future objects that will be returned from the threads.

    print("start parallel primes\n");
    auto t1 = steady_clock::now();
    for (auto i = num_threads; i; --i) {
        // Note instead of doung all this  in for we can manage the same thing with asyn function in one line:
        // asyn function help us with wrappin all  promise and future paradigm. it simpifies it for us.
            // swarm.emplace_back(std::async(count_primes, max_prime));

        std::promise<prime_time> promise_o{}; // we create an empty promise object.
        auto future_o = promise_o.get_future(); // we are creating a future object from the promise object using get_future func.
        // we move  the future object to swarm list. Note that future_object can not be copied so we move it.
        swarm.emplace_back(std::move(future_o));

        // we create the threa with count_primes function, which thread will be running, max_prime and promise object.
        // ahain promise object could not be copied so we move it.
        // Note here: the promise object we passed here( std::move(promise_o)), we are setting its value in the
        //  count_primes function like this(  pval.set_value(ret);)
        std::thread t(count_primes, max_prime, std::move(promise_o));

        //Separates the thread of execution from the thread object, allowing execution to continue independently. 
        // Any allocated resources will be freed once the thread exits.
        //After calling detach* this no longer owns any thread.
        t.detach();
    }

    for (auto& f : swarm) {
        static auto i = 0;
        auto [dur, count] = f.get();    // structured binding (C++17)
        print("thread {:02}: found {} primes in {:.5}\n", ++i, count, dur);
    }

    secs dur_total{ steady_clock::now() - t1 };
    print("total duration: {:.5}s\n", dur_total.count());
}
