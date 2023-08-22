
#include <format>
#include <list>
#include <chrono>
#include <future>

using std::chrono::steady_clock;
using secs = std::chrono::duration<double>;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}
struct prime_time {
    secs dur{};
    uint64_t count{};
};

prime_time count_primes(const uint64_t& max) {
    prime_time ret{};
    constexpr auto isprime = [](uint64_t n) {
        for (int64_t i{ 2 }; i < n / 2; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    };

    uint64_t start{ 2 };
    uint64_t end { max };
    auto time_thread_start = steady_clock::now();
    for (auto i = start; i <= end; ++i) {
        if (isprime(i)) {
            ++ret.count;
        }
    }

    ret.dur = steady_clock::now() - time_thread_start;
    return ret;
}

int main() {
    constexpr uint64_t max_prime{ 0x1FFFF };
    constexpr size_t num_threads{ 15 };
    std::list<std::future<prime_time>> swarm; // is a list of prim_time future objects.

    print("start parallel primes\n");
    auto time_start = steady_clock::now();
    for (auto i = num_threads; i; --i) {
        // async function runs a thread asynchronously and returns a value using the standar future class.
        // async allows like mus a rgular thread but also allows "returning values".
        // async create an asynchronous operation/thread and return a std::future object. 
        // so, we put/insert future object return from (std::async(count_primes, max_prime)) to the "swarm" list.
        // here async creates a thread and it returns a future object. this future object is created by a "promise object" under the hood.
        // The function template std::async runs the function f(count_primes in this case) asynchronously (potentially in a separate thread which might be a part of a thread pool) 
        // and returns a std::future that will eventually hold the result of that function call.
        // we do not see pormise object in our code anywhere. because, async is a wrapper that creates the thread using this promise-future paradigm.
        swarm.emplace_back(std::async(count_primes, max_prime));
    }

    // here we loop over swarm list, in whihc each element is a future object( future<prime_time>)
    // we sue get() member function on future object and get the value in it( the valeu it hold is a prime_time object in this case)
    for (auto& f : swarm) {
        static auto i = 0;

        // this way is structured binding
        // Structured Bindings give us the ability to declare multiple variables initialized from a tuple or struct.
        // here we call get() method on future object f. It returns a prime_time object with two attributes(secs dur{}; ,uint64_t count{};)
        // so we initilize dur with  durx attribute of returned prime_time object, so we initilize countx with  count  attribute of returned prime_time object
        // Note when we cal get() function on a future object, it blocks/waits for future obecjts to be availbale. In other words, the future object(f) is a result/return of a async thread.
        // So, in order to get the retuls from get() that future object needs to be available(means that a async function finisn its job and return the vale(future objec). After that get() function can give us the value from it.
        auto [durx, countx] = f.get(); //structured binding.
        print("thread {:02}: founr {} primes in {:.5}\n", ++i, countx, durx);
    }

    secs dur_total{ steady_clock::now() - time_start };
    print("total duration: {:.5}s\n", dur_total.count());

    return 0;
}
