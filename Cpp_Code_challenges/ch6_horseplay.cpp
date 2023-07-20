// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
/*
    // solution-1
    int rank = knight.at(1) - '0';
    char file = knight.at(0);
    std::string newLocation = "";
    int newRank = rank + 2;
    char newFile;
    if (newRank <= 8 && newRank >= 1) {
        newFile = file + 1;
        if (newFile >= 'a' && newFile <= 'h') {
            std::string newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }

         newFile = file - 1;
        if (newFile >= 'a' && newFile <= 'h') {
            newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }
    }

    newRank = rank + 1;
    if (newRank <= 8 && newRank >= 1) {
       newFile = file + 2;
        if (newFile >= 'a' && newFile <= 'h') {
            newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }

        newFile = file - 2;
        if (newFile >= 'a' && newFile <= 'h') {
            newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }
    }

    newRank = rank - 2;
    if (newRank <= 8 && newRank >= 1) {
        newFile = file + 1;
        if (newFile >= 'a' && newFile <= 'h') {
            newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }

        newFile = file - 1;
        if (newFile >= 'a' && newFile <= 'h') {
            newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }
    }

    newRank = rank - 1;
    if (newRank <= 8 && newRank >= 1) {
        char newFile = file + 2;
        if (newFile >= 'a' && newFile <= 'h') {
            newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }

        newFile = file - 2;
        if (newFile >= 'a' && newFile <= 'h') {
            newLocation = "";
            newLocation += newFile;
            newLocation += std::to_string(newRank);
            moves.push_back(newLocation);
        }
    }
    return moves;
    // end-of-solution-1
    */
    //solution-2
    int x, y;
    x = knight[0] - 'a' + 1; // x contains column number of chess board where knight stands
    y = knight[1] - '0'; // y contains row number of chess board where knight stands

    // will be used to calculate all possible moves of a knight
    const int delta1[2] = { -1, 1 };
    const int delta2[2] = { -2, 2 };

    int newX;
    int newY;
    std::string newLoc = "  ";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            newX = x + delta1[i];
            newY = y + delta2[j];

            if (newX > 0 && newX < 9 && newY > 0 && newY < 9) {
                newLoc[0] = newX + 'a' - 1;
                newLoc[1] = newY + '0';
                moves.push_back(newLoc);
             }

            newX = x + delta2[i];
            newY = y + delta1[j];

            if (newX > 0 && newX < 9 && newY > 0 && newY < 9) {
                newLoc[0] = newX + 'a' - 1;
                newLoc[1] = newY + '0';
                moves.push_back(newLoc);
            }
        }
    }

    return moves;
    // end-of-solution-2
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}