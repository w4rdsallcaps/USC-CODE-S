#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class GuessingGame {
    private:
        int number, lowest, highest;

    public:
        GuessingGame(int lower, int upper) : lowest(lower), highest(upper) {
            srand(static_cast<unsigned int>(time(0)));
            number = rand() % (upper - lower + 1) + lower;
        }

        void play() {
            int guess = 0, attempts = 0;
            cout << "Welcome to the Guessing Game!\nTry to guess the number between " << lowest << " and " << highest << ".\n";

            while (guess != number) {
                cout << "Enter your guess: ";
                cin >> guess;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please enter a valid number.\n";
                    continue;
                }

                attempts++;

                if (guess < number) {
                    cout << "Too low! Try again.\n";
                } else if (guess > number) {
                    cout << "Too high! Try again.\n";
                } else {
                    cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
                }
            }
        }
};

int main() {
    int lowest = 1, highest = 100;

    GuessingGame game(lowest, highest);
    game.play();

    return 0;
}
