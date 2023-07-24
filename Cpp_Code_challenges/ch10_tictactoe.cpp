// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

//#define TWO_PLAYERS
void make_move(char game[][3], char mark){ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    // Write your code here and comment out the definition of TWO_PLAYERS above

    int i, j;
    char opponent = mark == 'X' ? 'O' : 'X';

    // checking if a horixonatl and diagonal victory is possible and puts the mark at correct place to win the game.
    for (i = 0; i < 3; i++) {
        if (game[i][0] == ' ' && game[i][1] == mark && game[i][2] == mark) {
            game[i][0] = mark;
            return;
        }

        if (game[i][0] == mark && game[i][1] == ' ' && game[i][2] == mark) {
            game[i][1] = mark;
            return;
        }

        if (game[i][0] == mark && game[i][1] == mark && game[i][2] == ' ') {
            game[i][2] = mark;
            return;
        }

        if (game[0][i] == ' ' && game[1][i] == mark && game[2][i] == mark) {
            game[0][i] = mark;
            return;
        }

        if (game[0][i] == mark && game[1][i] == ' ' && game[2][i] == mark) {
            game[1][i] = mark;
            return;
        }

        if (game[0][i] == mark && game[1][i] == mark && game[2][i] == ' ') {
            game[2][i] = mark;
            return;
        }
    }

    // checking if a diagonal victory is possible and puts the mark at correct place to win the game.
    if (game[0][0] == ' ' && game[1][1] == mark && game[2][2] == mark) {
        game[0][0] = mark;
        return;
    }

    if (game[0][0] == mark && game[1][1] == ' ' && game[2][2] == mark) {
        game[1][1] = mark;
        return;
    }

    if (game[0][0] == mark && game[1][1] == mark && game[2][2] == ' ') {
        game[2][2] = mark;
        return;
    }

    if (game[2][0] == ' ' && game[1][1] == mark && game[0][2] == mark) {
        game[2][0] = mark;
        return;
    }

    if (game[2][0] == mark && game[1][1] == ' ' && game[0][2] == mark) {
        game[1][1] = mark;
        return;
    }

    if (game[2][0] == mark && game[1][1] == mark && game[0][2] == ' ') {
        game[0][2] = mark;
        return;
    }

    // a victory is not possible. So, check if there is any possiblity that oppenents can win and try to block it
    // block oppponent's horizontal or vertical win.
    for (i = 0; i < 3; i++) {
        if (game[i][0] == ' ' && game[i][1] == opponent && game[i][2] == opponent) {
            game[i][0] = mark;
            return;
        }

        if (game[i][0] == opponent && game[i][1] == ' ' && game[i][2] == opponent) {
            game[i][1] = mark;
            return;
        }

        if (game[i][0] == opponent && game[i][1] == opponent && game[i][2] == ' ') {
            game[i][2] = mark;
            return;
        }

        if (game[0][i] == ' ' && game[1][i] == opponent && game[2][i] == opponent) {
            game[0][i] = mark;
            return;
        }

        if (game[0][i] == opponent && game[1][i] == ' ' && game[2][i] == opponent) {
            game[1][i] = mark;
            return;
        }

        if (game[0][i] == opponent && game[1][i] == opponent && game[2][i] == ' ') {
            game[2][i] = mark;
            return;
        }
    }

    // block oppponent's diagonal win.
    if (game[0][0] == ' ' && game[1][1] == opponent && game[2][2] == opponent) {
        game[0][0] = mark;
        return;
    }

    if (game[0][0] == opponent && game[1][1] == ' ' && game[2][2] == opponent) {
        game[1][1] = mark;
        return;
    }

    if (game[0][0] == opponent && game[1][1] == opponent && game[2][2] == ' ') {
        game[2][2] = mark;
        return;
    }

    if (game[2][0] == ' ' && game[1][1] == opponent && game[0][2] == opponent) {
        game[2][0] = mark;
        return;
    }

    if (game[2][0] == opponent && game[1][1] == ' ' && game[0][2] == opponent) {
        game[1][1] = mark;
        return;
    }

    if (game[2][0] == opponent && game[1][1] == opponent && game[0][2] == ' ') {
        game[0][2] = mark;
        return;
    }

    // No possiblity for a win and also no thread that opponent can win. So, put the mark in the center/middle square if that square is empty/vacant. Because it is most strategic(means it leads to 4 bossible wins)
    if (game[1][1] == ' ') {
        game[1][1] = mark;
        return;
    }


    // middle quare is not epty. Then, take one of the corner square because they are more strategic(measne they leads to 3 possible wins)
    if (game[0][0] == ' ') {
        game[0][0] = mark;
        return;
    }

    if (game[0][2]== ' ') {
        game[0][2] = mark;
        return;
    }

    if (game[2][0] == ' ') {
        game[2][0] = mark;
        return;
    }

    if (game[2][2] == ' ') {
        game[2][2] = mark;
        return;
    }


    // middle square or any of the corner squares are not available. So, take the first empty/vanca square.
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (game[i][j] == ' ') {
                game[i][j] = mark;
                return;
            }
        }
    }


    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3]) {

    // solution-1
    /*
    char possibleWinningCombinations[][3] = { 
        {game[0][0], game[0][1], game[0][2]},
        {game[1][0], game[1][1], game[1][2]},
        {game[2][0], game[2][1], game[2][2]},
        {game[0][0], game[1][0], game[2][0]},
        {game[0][1], game[1][1], game[2][1]},
        {game[0][2], game[1][2], game[2][2]},
        {game[0][0], game[1][1], game[2][2]},
        {game[0][2], game[1][1], game[2][0]}
    };

    for (size_t i = 0; i < 8; i++) {
        if (possibleWinningCombinations[i][0] == possibleWinningCombinations[i][1] && possibleWinningCombinations[i][1] == possibleWinningCombinations[i][2] && possibleWinningCombinations[i][0] != ' ') {
            return  possibleWinningCombinations[i][0];
       }
    }

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (game[i][j] == ' ') {
                return 'a';
            }

        }
    }

    return 't';
    */

    // solution-2

    int i, j;

    // this checks if there is  horizontal or vertical victory. Means XXX or OOO in a row or column
    for (i = 0; i < 3; i++) {
        if (game[i][0] != ' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2]) {
            return game[i][0];
        }

        if (game[0][i] != ' ' && game[0][i] == game[1][i] && game[1][i] == game[2][i]) {
            return game[0][i];
        }
    }
    // this checks if there is diagonal victory. Means XXX or OOO diagonally.
    if (game[1][1] != ' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
        return game[1][1];
    }

    if (game[1][1] != ' ' && game[0][2] == game[1][1] && game[1][1] == game[2][0]) {
        return game[1][1];
    }

    // this checks tie-case(no victory). Game ended and nobody won.
    int count = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (game[i][j] != ' ') {
                count++;
            }
        }
    }

    if (count == 9) {
        return 't';
    }

    // none-of-the above. So, game is still active.
    return 'a';
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
