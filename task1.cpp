#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    // Initialize random seed
    srand(time(0));
    // Generate a random number between 1 and 100
    int number = rand() % 100 + 1;
    int guess = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;

    // Loop until the user guesses the correct number
    while (guess != number) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > number) {
            cout << "Too high! Try again." << endl;
        } else if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
        }
    }

    return 0;
}
