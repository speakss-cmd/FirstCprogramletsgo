#include <iostream>
#include <ctime>
#include <cstdlib>


int playGame (int guess, short secretnum, int correct)
{

    if (guess > secretnum) {
        std::cout << "To High!" << "\n";
        return 0;
    }
    else if (guess < secretnum) {
        std:: cout << "To Low!" << "\n";
        return 0;
    }
    else if (guess == secretnum) {
        std:: cout << "Correct!" << "\n";
        int correct = 1;
        return correct;
    }
}


int main ()
{
    //enter too high or too low or correct
    //counts amount of guesses
    //number b/w 1-100
    srand(time(nullptr));
    const int maxValue = 101;
    short secretnum = rand() % maxValue; //equatioin for random #

    int guess;
    int counter = 0;
    int correct = 0;

    int choice = 1;
    bool playagain = true;

    while (playagain) {
        while (choice != 0) {
            std:: cout << "Enter your Guess: " << "\n";
            std:: cin >> guess;
            counter++;
            correct = playGame(guess, secretnum, correct); //to make sure correct actually changes you must assign this function call to actually recieve the correct value change. thus correct = ...
            
            if (correct == 1){ //exit the while loop
                choice = 0;
            }
        }
        std:: cout << "You guessed in: " << counter << "\n";
        std:: cout << "Want to play again? 1/0" << "\n";
        std:: cin >> playagain;
        
    }
    return 0;
}