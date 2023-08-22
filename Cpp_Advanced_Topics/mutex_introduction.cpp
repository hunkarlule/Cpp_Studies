
#include <format>
#include <string_view>
#include <thread>
#include <future>
#include <mutex>
#include <list>
#include <optional>

// the term "mutex" refersto "mutually exclusive access to shared resources".
// mutes is used "to avoid data corruption nad race conditions" when multiple  threads of execution tries/attempts to access the same data.
// A mutes will generally use "locks" to restrict access to one thread at a time.
// 

// RAII: Resource Acquisition Is Initialization or RAII, is a C++ programming technique which binds the life cycle of a resource that must be acquired before use(allocated heap memory,
// thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime of an object.

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

std::mutex animal_mutex{};  // a mutex object

class Animal {
    using friend_t = std::list<Animal>; // an type alias named friend_t that  corresponds to type list of animals type(std::list<Animal>)
    std::string_view s_name{ "unk" };
    friend_t l_friends{}; // holds the friends of animal.

public:
    Animal() = delete;
    Animal(const std::string_view n) : s_name(n) {};

    bool operator==(const Animal & o) const {
        return s_name.data() == o.s_name.data();
    }

    bool add_friend(Animal& o) noexcept {
        print("add firend {} -> {}\n", s_name, o.s_name);
        if (*this == o) {
            return false;
        }

        // lack-guard is a class acquires ownership for the current thread and it refesr to a mutes to keep that owenership straight.
        // lock-guard will block or wait of ownership is not available.
        // lock-gurad follows "RAII protocal", whihc means resource acquisations is initialization. What this means is when the lack-guard goes out of scope, the lock will be released.
        // to see the effect of lock_gurad comment-out the lines(std::lock_guard<std::mutex> l{ animal_mutex };) in the function and run the program.

        // When a lock_guard object is created, it attempts to take ownership of the mutex it is given. 
        // When control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and the mutex is released.

        /*
       std::lock_guard<std::mutex> l{ animal_mutex };
Notice that the lock_guard references the global mutex animal_mutex. That is, the same mutex for all three threads. What lock_guard does is essentially this:

Upon construction, it locks animal_mutex and keeps a reference to it.
Upon destruction (i.e. when the guard's scope is left), it unlocks animal_mutex.
The mutex is always the same one, it has nothing to do with the scope. The point of lock_guard is just to make locking and unlocking the mutex easier for you. For example,
if you manually lock/unlock, but your function throws an exception somewhere in the middle, it will never reach the unlock statement. 
So, doing it the manual way you have to make sure that the mutex is always unlocked. 
On the other hand, the lock_guard object gets destroyed automatically whenever the function is exited – regardless how it is exited.
        */
        std::lock_guard<std::mutex> l{ animal_mutex };
        if (!is_friend(o)) {
            l_friends.emplace_back(o);
        }

        if (!o.is_friend(*this)) {
            o.l_friends.emplace_back(*this);
        }
        return true;
    }

    bool delete_friend(Animal& o) noexcept {
        print("delete_friend {} <-> {}\n", s_name, o.s_name);
        if (*this == o) {
            return false;
        }

        std::lock_guard<std::mutex> l{ animal_mutex };
        if (auto it = find_friend(o); it) {
            l_friends.erase(it.value());
        }

        if (auto it = o.find_friend(*this); it) {
            o.l_friends.erase(it.value());
        }
    }

    bool is_friend(const Animal& o) const {
        for (const auto& a : l_friends) {
            if (a == o) {
                return true;
            }
        }
        return false;
    }

    std::optional<friend_t::iterator> find_friend(const Animal& o) noexcept {
        for (auto it = l_friends.begin(); it != l_friends.end(); ++it) {
            if (*it == o) return it;
        }

        return {};
    }

    void pfriends() const noexcept {
        std::lock_guard<std::mutex> l{ animal_mutex };
        auto n_animals = l_friends.size();
        print("{} friends: ", s_name);
        if (!n_animals) {
            print("none");
        }
        else {
            for (auto n : l_friends) {
                print(n.s_name);
                if (--n_animals) {
                    print(", ");
                }
            }
        }
        print("\n");
    }
};


int main() {

    //make_unique: Creates and returns a unique_ptr to an object of the specified type, which is constructed by using the specified arguments.
    auto cat1 = std::make_unique<Animal>("Felix");
    auto tiger1 = std::make_unique<Animal>("Hobbes");
    auto dog1 = std::make_unique<Animal>("Astro");
    auto rabbit1 = std::make_unique<Animal>("Bugs");

    print("add friends\n");
    // here we use async to add friends.
    auto a1 = std::async([&] {cat1->add_friend(*tiger1); });
    auto a2 = std::async([&] {cat1->add_friend(*rabbit1); });
    auto a3 = std::async([&] {rabbit1->add_friend(*dog1); });
    auto a4 = std::async([&] {rabbit1->add_friend(*tiger1); });

    // we call wait() method for each future object to mkae sure that they are done before we start to rpitnign them.
    a1.wait();
    a2.wait();
    a3.wait();
    a4.wait();

    // we printing amimal using async. async creates a thread and returns a future object when the thread is done.
    print("\nprint animals\n");
    auto p1 = std::async([&] {cat1->pfriends(); });
    auto p2 = std::async([&] {tiger1->pfriends(); });
    auto p3 = std::async([&] {dog1->pfriends(); });
    auto p4 = std::async([&] {rabbit1->pfriends(); });

    // we call wait() method for each future object to mkae sure that they are done before we start the delete relationship.
    p1.wait();
    p2.wait();
    p3.wait();
    p4.wait();


    // we deleting relationship  using async. async creates a thread and returns a future object when the thread is done.
    print("\ndelete Felix/Bugs friendship\n");
    auto a5 = std::async([&] {cat1->delete_friend(*rabbit1); });
    
    // we call wait() method for each future object to mkae sure that they are done before we start to rpitnign them.
    a5.wait();
  
    // we printing amimal using async. async creates a thread and returns a future object when the thread is done.
    print("\nprint animals\n");
    p1 = std::async([&] {cat1->pfriends(); });
    p2 = std::async([&] {tiger1->pfriends(); });
    p3 = std::async([&] {dog1->pfriends(); });
    p4 = std::async([&] {rabbit1->pfriends(); });

    // we call wait() method for each future object to mkae sure that they are done.
    p1.wait();
    p2.wait();
    p3.wait();
    p4.wait();

    print("\nend of main()\n");

    return 0;
}
