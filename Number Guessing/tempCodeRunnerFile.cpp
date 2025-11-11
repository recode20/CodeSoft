// ==========================================================
// Project: Number Guessing Game
// Language: C++
// Task: Internship Task 1
// Description:
//   This program generates a random number between 1 and 100
//   and asks the user to guess it. It provides feedback such as
//   "Too high" or "Too low" until the correct number is guessed.
// ==========================================================

#include <iostream>  // For input/output
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

int main() {
    // Seed the random number generator with current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;        // To store user's guess
    int attempts = 0; // To count number of attempts

    // Game introduction
    cout << "============================================\n";
    cout << "🎮 Welcome to the Number Guessing Game 🎯\n";
    cout << "============================================\n\n";
    cout << "I'm thinking of a number between 1 and 100.\n";
    cout << "Can you guess it?\n\n";

    // Uncomment the line below if you want to see the secret number for testing
    // cout << "(DEBUG) Secret Number is: " << secretNumber << endl;

    // Game loop: continue until the correct number is guessed
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        // Validate user input
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "❌ Invalid input! Please enter a number.\n\n";
            continue;
        }

        // Compare guess with the secret number
        if (guess < secretNumber) {
            cout << "Too low! 📉 Try again.\n\n";
        } 
        else if (guess > secretNumber) {
            cout << "Too high! 📈 Try again.\n\n";
        } 
        else {
            cout << "\n🎉 Congratulations! You guessed the number "
                 << secretNumber << " correctly!\n";
            cout << "🏆 It took you " << attempts << " attempts to win.\n";
        }

    } while (guess != secretNumber);

    // Exit message
    cout << "\nThanks for playing! 👋\n";

    return 0;
}
