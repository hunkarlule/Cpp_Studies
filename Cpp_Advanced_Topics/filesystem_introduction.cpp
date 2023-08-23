
#include <format>
#include <vector>
#include <filesystem>

//we abbreviated  namesapce of standart file system to fs.
namespace fs = std::filesystem;

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

// formatter specialization for the file system path class.
template<>
struct std::formatter<fs::path> : std::formatter<int> {
    template<typename Context>
    auto format(const fs::path& p, Context& ctx) {
        return format_to(ctx.out(), "{}", p.string());
    }
};

auto newline = [] {print("\n"); };

void printdir(const fs::path& p) {
    using de = fs::directory_entry; // an alias
    std::vector<de>dir{}; // a vector of directory entries

    auto dircmp = [](const de& lhs, const de& rhs) -> bool { // dircamp is a lambda comparing two directory paths.
        return lhs.path().string() < rhs.path().string();
    };

    if (!fs::exists(p)) { // checking is path really exists?
        print("{} does not exist\n");
        return;
    }

    if (fs::is_directory(p)) { // checkin if path is a directory path. if so puttinn entries in the directory to the vector adn then print them
        for (const auto& de : fs::directory_iterator(p)) { // fs::directory_iterator(p): Constructs a directory iterator that refers to the first directory entry of a directory identified by p
            dir.emplace_back(de); // inserting entries in directory to vector.
        }

        //std::sort(dir.begin(), dir.end(), dircmp); // sorting the vector. for sorting using the lambda dricmp
        for (const auto& e : dir) {
            print("{}\n", fs::relative(e, p));
            print("{}\n", fs::absolute(e));
        }

        newline();
    }
    else {
        print("not a directory: {}\n", p);
    }
}

constexpr const char* fp{ "testdir/foo.txt" };
constexpr const char* homedir {"C:\\Users\\hlule\\OneDrive - VertiGIS\\Desktop\\personal_training"};

int main() {
    fs::path p{ fp };
    print("p: {}\n", p);
    
    if(!fs::exists(homedir)) {
        print("{} does not exist\n", fs::absolute(homedir));
        return 1;
    }

    try {
        print("current_path: {}\n", fs::current_path());
        print("change current_path to {}\n", homedir);
        fs::current_path(homedir);
        newline();

        print("current_path: {}\n", fs::current_path());
        print("absolute(p): {}\n", fs::absolute(p));
        newline();

        print("concatenate: {}\n", fs::path{ "testdir" } += "foo.txt");
        print("append: {}\n", fs::path{ "testdir" } /= "foo.txt");
        newline();

        print("canonical (.): {}\n", fs::canonical(fs::path(".")));
        newline();

        auto dirpath = fs::path(".") /= "Cpp_Studies";
        print("Directory of {}:\n", dirpath);
        printdir(dirpath);

    } catch (const fs::filesystem_error& e) {
        print("{}\n", e.what());
        print("path1: {}\n", e.path1());
        print("path2: {}\n", e.path2());
    }

    return 0;
}
