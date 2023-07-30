// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include<thread>

 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;

    // solution-1
    /*
    std::string typedWord;
    std::getline(std::cin, try_again);
    std::srand((unsigned)(time(0)));
    do{

        // Write your code here
        int randomWaiAmount=  4 + (rand() % (10 - 4 + 1));
        std::cout << "Be ready to type!\n" << std::endl << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(randomWaiAmount));

        int randomElementIndex = rand() % 10;
        std::string targetWord = words[randomElementIndex];
        std::cout << targetWord << std::endl;

        auto startTime = std::chrono::steady_clock::now();
        std::cout << "Enter the word " << "'" << targetWord << "': ";
        std::getline(std::cin, typedWord);
        auto endTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> typeingTime = endTime - startTime;
        auto targetTime = std::chrono::seconds(2);

        if (typeingTime > targetTime) {
            std::cout << "Sorry, you wern't fast enough. Try harder next time!\n " << std:: endl<< std::flush;
        }
        else {
            std::transform(typedWord.begin(), typedWord.end(), typedWord.begin(), ::toupper);
            if (typedWord.std::string::compare(targetWord) == 0) {
                std::cout << "Good, you are on target!\n" << std::endl << std::flush;
            }
            else {
                std::cout << "Sorry, you typed the wrong word. Be careful next time!\n" << std::endl << std::flush;
            }
         }
       

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    */
    // end of solution-1

    //solution-2


    std::getline(std::cin, try_again);
    std::srand((unsigned)(time(0)));
    std::rand();

    do {
        // Write your code here
        std::string typedWord;
        int randomWordIndex = rand() % 10;

        std::chrono::seconds delayTime(4 + std::rand() % 7);

        auto start = std::chrono::steady_clock::now();
        auto end = start + delayTime;

        std::cout << "\n\nBe ready to type!\n" << std::endl << std::flush;
        do {
            // we are waiting for random delayTime to catch the player off guard before asking the question the the player.
        } while (end > std::chrono::steady_clock::now());

        std::string targetWord = words[randomWordIndex];
        std::cout << "\nEnter the word " << "'" << targetWord << "': " << std::flush;

        start = std::chrono::steady_clock::now();
        std::getline(std::cin, typedWord);
        end = std::chrono::steady_clock::now();

        std::transform(typedWord.begin(), typedWord.end(), typedWord.begin(), ::toupper);
        double typeingTimeInSeconds = (end - start).count() / 1e9;
        std::cout << "\n" << std::flush;

     

        if (typeingTimeInSeconds > 2.0) {
            if (typedWord.std::string::compare(targetWord) == 0) {
                std::cout << "Good, you are on target! However, you were slow. It took you " << typeingTimeInSeconds << " seconds. Be faster next time\n\n" << std::endl << std::flush;
            }
            else {
                std::cout << "Sorry, you typed the wrong word. Also, you were slow. It took you " << typeingTimeInSeconds << " seconds. Be careful and faster next time!\n" << std::endl << std::flush;
            }
           
        }
        else {
            if (typedWord.std::string::compare(targetWord) == 0) {
                std::cout << "Good, you are on target! It took you " << typeingTimeInSeconds << " seconds.\n" << std::endl << std::flush;
            }
            else {
                std::cout << "You were fast. It took you " << typeingTimeInSeconds << " seconds. However, you typed the wrong word! Be careful next time!\n" << std::endl << std::flush;
            }
        }

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    } while (try_again[0] == 'Y' || try_again[0] == 'y');

    return 0;
}
