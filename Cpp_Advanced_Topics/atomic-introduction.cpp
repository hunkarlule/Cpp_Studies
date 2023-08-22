
#include <format>
#include <string>
#include <list>
#include <thread>
#include <atomic>


// atomic class guarantees a single primitive object to be atomic.
// writing to atomic object is controlled but reaadings from atomic object may occur simultaneously.
// atomic may be used to synchronize access among different threads.
// standard atomic requires a trivial type, and all primitive types(bool, int, float, double etc) are trivial.
std::atomic_bool ready {};
std::atomic_uint64_t g_count{};

// std::atomic_flag is an atomic boolean type. Unlike all specializations of std::atomic, 
// it is guaranteed to be lock-free. 
// Unlike std::atomic<bool>, std::atomic_flag does not provide load or store operations.
std::atomic_flag winner{}; // lock-free boolean atomic type.

constexpr uint64_t max_count{ 1'000'000 };
constexpr int max_threads{ 100 };

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

std::string make_commas(const uint64_t& num) {
    auto s = std::to_string(num);
    for (auto l = static_cast<int>(s.length()) - 3; l > 0; l -= 3) {
        s.insert(l, ",");
    }
    return s;
}

void sleep_ms(auto ms) {
    using std::this_thread::sleep_for;
    using std::chrono::milliseconds;
    sleep_for(milliseconds(ms));
}

void countem(int id) {
    while (!ready) {
        std::this_thread::yield();
    }

    for (auto i = 0; i < max_count; ++i) {
        if (winner.test()) {
            return;
        }
        ++g_count;
    }
    // test_adn_set(): atomically sets the flag to true and obtains its previous value
    if (!winner.test_and_set()) {
        print("thread {:02} won!\n", id);
        // notify_all(): notifies all threads blocked waiting on the atomic object
        winner.notify_all();
    }
}


int main() {

    std::list<std::thread> swarm{};

    print("spawn {} thread\n", max_threads);
    for (auto i = 0; i < max_threads; ++i) {
        swarm.emplace_back(countem, i);
    }

    sleep_ms(25); // give the threads a beat to spawn
    print("Go!\n");
    ready = true;

    for (auto& t : swarm) {
        t.join();
    }
    print("global count {}\n", make_commas(g_count));
}
