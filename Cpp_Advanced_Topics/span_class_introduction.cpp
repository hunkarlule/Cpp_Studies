
#include <format>
#include <span>

// span calss is a new feature  from C+=20
// it provides a simple wrapper that creates a view over
// contiguous sequence of objects. span does not own any of its own data
// it refers to the data in the underlying styructure.
// it is like string_view.
// the underlying structure could be a C array, a vector or an STL array.
// what does span do ? ==> it adds  STL container-like capabilities to the
// uynderlying structure.



// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

template <typename T>
void pspan(const std::span<T> s) {
    print("number of elements: {}\n", s.size());
    print("size of span: {}\n", s.size_bytes());
    for (auto e : s) {
        print("{} ", e);
    }
    print("\n");
}



int main() {

    // span adds  STL container - like capabilities to the C array below.
    // we pass C-array to pspan function. C-array is used to construc the span
    // and span is used in the function for operations. like we can get its size, number of bytes etc.
    // for example: we can not do this for the ca1 array: ca1.size(0); 
    //it isa compiler error, but in pspan function 
    // we can use size() becuase in pspan function we using span object that
    // created out of ca1 array.
    // span does not own the data. span is only a view to underlying data
    // but using this span version we can use useful member function and iterators.
    
    int ca1[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

 
    pspan<int>(ca1);
    //pspan<int>(std::span<int>(ca1)); // same as above.

    // we can not do these with C-array ca1 becuase it has not these capabilities.
    // however if we convert it span like we did in pspan function
    // then we can use them. this is adavantage of span.
        //print("number of elements: {}\n", ca1.size());// compiler error
        //print("size of span: {}\n", ca1.size_bytes()); // compiler error

    return 0;
}
