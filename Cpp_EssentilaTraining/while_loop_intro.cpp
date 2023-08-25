
#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    int array[] { 1, 2, 3, 4, 5 };
    int i {0};

    while (i < 5) { // this is contitopn called loop control. it controld the execution of the loop. when the condition returns flase them flow will go out-of-loop
        cout << format("element {} is {}\n", i, array[i]);
        ++i;
    }
    cout << "after1\n";
    i = 0;

    while (i < 5) {
        if (i == 3) { // here ending loop prematurely usin  "break" statement.
            break;
        }
        cout << format("element {} is {}\n", i, array[i]);
        ++i;
    }
    cout << "after2\n";

    i = 0;
    while (i < 5) {
        if (i ==2) { // here ewe are skippin rest of the block and going with the nexy iteration(we are jumbing at the beginning of loop for nex iteration)
            ++i;
            continue;
        }
        cout << format("element {} is {}\n", i, array[i]);
        ++i;
    }
    cout << "after3\n";


    // do-wile loop: it is same with wile loop but it test the condition at the end. That means do-while loop will run at least once.
    i = 0;
    do {
        cout << format("element {} is {}\n", i, array[i]);
        ++i;
    } while (i < 5);
    cout << "after4\n";
}
