
#include <format>
#include <deque>
#include <thread>
#include <mutex>

// producer-consumer idiom works like this: there are two processes. One porcess produce the data and other process consumes the data. However, there is only one container that holds the data.
// So, there shoule be some coordination between  producer-consumer processes to manager the container. So, there will not be any unwanted side-effects.

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
	fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

using namespace std::chrono_literals;


constexpr size_t num_items{ 10 };
constexpr auto delay_time{ 250ms };

std::mutex p_mtx{}; // producer mutex
std::mutex c_mtx{}; // consumer mutex
std::deque<size_t> q{}; // is a queue is a caontainer. to pass the data from producer to consumer. producer will put data there and the consumer will consume from there.

//std::atomic_flag is an atomic boolean type. Unlike all specializations of std::atomic, it is guaranteed to be lock-free. Unlike std::atomic<bool>, std::atomic_flag does not provide load or store operations.
std::atomic_flag finished{}; // this flag will be used to notify the consumer when producer finished sending the data.

void sleep_ms(const auto& delay) {
	std::this_thread::sleep_for(delay);
}

void producer() {
	for (size_t i{}; i < num_items; ++i) {
		sleep_ms(delay_time);
		print("push {} on the queue\n", i);
		std::lock_guard<std::mutex> lck{ p_mtx };
		q.push_back(i);
	}

	std::lock_guard<std::mutex> lck{ p_mtx };
	finished.test_and_set();
}

void consumer() {
	while (!finished.test()) {
		sleep_ms(delay_time * 8);
		std::lock_guard<std::mutex> lck{ c_mtx };
		while (!q.empty()) {
			print("pop {} from the queue\n", q.front());
			q.pop_front();
		}
	}
}

int main() {

	std::thread t1{ producer };
	std::thread t2{ consumer };

	t1.join();
	t2.join();

	print("finished!\n");
}
