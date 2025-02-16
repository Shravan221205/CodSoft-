#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;
    cout << "Welcome to 'Guess the Number'!" << endl;
    cout << "I've selected a number between 1 and 100. Can you guess it?" << endl;
    while (userGuess != numberToGuess)
    {
        cout << "Enter your guess: ";
        cin >> userGuess;
        if (userGuess < numberToGuess)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (userGuess > numberToGuess)
        {
            cout << "Too high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the correct number: " << numberToGuess << endl;
        }
    }
    return 0;
}
