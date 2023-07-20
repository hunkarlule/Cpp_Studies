// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    
    // Write your code here
    int vectorLength = v.size();
    if (vectorLength <= 2) {
        return true;
    }

    bool isRising = false;
    int i = 0;

    while (i < vectorLength - 1 && v[i] == v[i + 1]) {
        i++;
        if (i == vectorLength - 1) {
            return true;
        }
    }

    // first slope
    if (v[i] < v[i + 1]) {
        while (i < (vectorLength - 1) && v[i] <= v[i + 1]) {
            i++;
        }
    }
    else {
        while (i < (vectorLength - 1) && v[i] >= v[i + 1]) {
            i++;
        }
    }

    if (i == vectorLength - 1) {
        return true; // momotonic sequence
    }

    //second slope
    if (v[i] < v[i + 1]) {
        while (i < (vectorLength - 1) && v[i] <= v[i + 1]) {
            i++;
        }
    }
    else {
        while (i < (vectorLength - 1) && v[i] >= v[i + 1]) {
            i++;
        }
    }

    if (i == vectorLength - 1) {
        return true; // bitonic sequence
    }

    //third slope
    if (v[i] < v[i + 1]) {
        isRising = true;
        while (i < (vectorLength - 1) && v[i] <= v[i + 1]) {
            i++;
        }
    }
    else {
        isRising = false;
        while (i < (vectorLength - 1) && v[i] >= v[i + 1]) {
            i++;
        }
    }

    if (i == vectorLength - 1) {
        return false; // not bitonic sequence becuase there is 4th slope.
    }

    if (isRising && v[i] <= v[0]) {
        return true;
    }

    if (!isRising && v[i] >= v[0]) {
        return true;
    }

    return false;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
     std::vector<int> myvec1 = {1, 2, 5, 4, 3};  // Yes
     std::vector<int> myvec2 = {1, 1, 1, 1, 1};  // Yes
     std::vector<int> myvec3 = {3, 4, 5, 2, 2};  // Yes
     std::vector<int> myvec4 = {3, 4, 5, 2, 4};  // No
     std::vector<int> myvec5 = {1, 2, 3, 4, 5};  // Yes
     std::vector<int> myvec6 = {1, 2, 3, 1, 2};  // No
     std::vector<int> myvec7 = {5, 4, 6, 2, 6};  // No
     std::vector<int> myvec8 = {5, 4, 3, 2, 1};  // Yes
     std::vector<int> myvec9 = {5, 4, 3, 2, 6};  // Yes
     std::vector<int> myvec10 = {5, 4, 6, 5, 4};  // No
     std::vector<int> myvec11 = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec7) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
