
#include <format>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::format;
using std::string;
using std::vector;

const size_t maxstring{ 1024 }; // size of the buffer
const char* filename{ "C:\\Users\\hlule\\OneDrive - VertiGIS\\Desktop\\personal_training\\Cpp_Studies\\Cpp_EssentilaTraining\\items.txt" }; // file location
const char tab_char { '\t' }; 

class Item {
    int _sku{};
    string _name{};
    string _desc{};
public:
    Item() { reset(); }; //default constructor
    Item(int sku, string& name, string& desc) : _sku(sku), _name(name), _desc(desc) {}
    Item(const Item& rhs); // copy constructor.
    Item& operator = (const Item& rhs); // copy assignment operator
    ~Item() { reset(); } // destrcutor
    void reset() { _sku = 0; _name = _desc = "unk"; } // same as: _sku = 0; _name = "unk"; _desc = "unk"
    void sku(int sku) { _sku = sku; } // set sku
    int sku() const { return _sku; }; // get sku
    void name(const string& name) { _name = name; } // set name
    string name() { return _name; } // get name
    void desc(const string& desc) { _desc = desc; } // set desc
    string desc() { return _desc; } // get desc
};

// copy constructor.
Item::Item(const Item& rhs) {
    _sku = rhs._sku;
    _name = rhs._name;
    _desc = rhs._desc;
}

// copy assignment operator
Item& Item::operator = (const Item& rhs) {
    if (this != &rhs) {
        _sku = rhs._sku;
        _name = rhs._name;
        _desc = rhs._desc;
    }
    return *this;
}

// split a string
vector<string> strsplit(const string& s) {
    vector<string> strs_v;    // vector for results
    size_t start_loc {};
    size_t sep_loc {};
    while (true) {
        sep_loc = s.find(tab_char, start_loc);
        strs_v.push_back(s.substr(start_loc, sep_loc - start_loc));
        if (sep_loc == string::npos) break;
        start_loc = sep_loc + 1;
    }
    return strs_v;
}

// split a string;
vector<string> srrsplit(const string& s) {
    vector<string> strs_v; //string vector to hold results.
    size_t start_loc{};
    size_t sep_loc{};
    while (true) {
        //If the sub-string is not found it returns string::npos(string::pos is a static 
        // member with its value as the highest possible for the size_t data type).
        sep_loc = s.find(tab_char, start_loc); // find position of first tab character in the string
        strs_v.push_back(s.substr(start_loc, sep_loc - start_loc)); //find substring between start_loc and sep_loc and push it to the vector.
        if (sep_loc == string::npos) break;
        start_loc = sep_loc + 1;
    }
    return strs_v;
}

int main()
{
    char buf[maxstring]{}; // buffer for reading lines in file


    // open file to read
    std::ifstream infile(filename); // this creat a ifstream with name infile.

    // read the file
    while(infile.good()) { // while stram infile is good
        // get line from the file
        infile.getline(buf, sizeof(buf)); // with getline read one line from the file.
        if (!*buf) break;

        // split the string
        vector<string> split_v{ strsplit(buf) };
        if(split_v.size() < 3) continue;

        // construct the object
        Item current_item{ std::stoi(split_v[0]), split_v[1], split_v[2] };

        // print the current itme:
        cout << format("sku: {}, name: {}, desc: {}\n", current_item.sku(), current_item.name(), current_item.desc());
        
    }
    infile.close(); // cloe the file.
}
