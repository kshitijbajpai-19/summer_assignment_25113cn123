// WAP to create a number guessing game

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    srand(time(0)); // Initialize the random number generator

    int num, guess, choice, difficulty, maxattempts;

    // Display welcome message and instructions
    cout << "Welcome to the Number guessing game! \n";
    cout << "\nInstructions\n";
    cout << "1. The computer will generate a random number between 1 and 100.\n";
    cout << "2. Choose a difficulty level before starting the game.\n";
    cout << "3. Enter your guess when prompted.\n";
    cout << "4. If you see 'Too High!', your guess is greater than the correct number.\n";
    cout << "5. If you see 'Too Low!', your guess is smaller than the correct number.\n";
    cout << "6. Guess the correct number within the allowed attempts to win.\n";
    cout << "7. Enter only numbers between 1 and 100.\n";
    cout << "8. After the game ends, you can choose to play again or exit.\n";
    cout << "\n";
    do
    {
        // Choose difficulty
        cout << "\nChoose Difficulty\n";
        cout << "1. Easy (10 Attempts)\n";
        cout << "2. Medium (7 Attempts)\n";
        cout << "3. Hard (5 Attempts)\n";
        cout << "4. Exit Game\n";
        cout << "Enter your choice: ";
        cin >> difficulty;

        // Set maximum attempts as per difficulty
        if (difficulty == 1)
            maxattempts = 10;
        else if (difficulty == 2)
            maxattempts = 7;
        else if (difficulty == 3)
            maxattempts = 5;
        else if(difficulty == 4)
            return 0;
        else
            cout << "Invalid choice!\n";

    } while (difficulty < 1 || difficulty > 3);

    // Repeat the game until the user chooses to exit
    do
    {

        num = rand() % 100 + 1; // Generate a random number between 1 and 100

        int attempt = maxattempts;
        do
        {   
            // Display remaining attempts
            cout << "\nYou have " << attempt << " attempts left \n";
            cout << "Enter your guess: ";
            cin >> guess;

            // Validate the entered number
            if (guess < 1 || guess > 100)
            {
                cout << "\nGuess a number between 1 and 100.\n";
                continue;
            }

             // Check whether the guess is correct
            if (guess == num)
            {
                cout << "\n Congratulations! " << "You guessed the number correctly! \n";
                cout << "Number of attempts used: " << maxattempts - attempt + 1 << "\n";
                break;
            }

            // Provide hint
            else if (guess < num)
            {
                cout << "Too low! \n";
            }
            else if (guess > num)
            {
                cout << "Too high! \n";
            }

            attempt--; // Decrease number of attempts

            // Display game over message
            if (attempt == 0)
            {
                cout << "You lost! \n";
                cout << "The correct number was " << num << "\n";
            }

        } while (attempt != 0);

        // Ask the user whether to play again
        do
        {
            cout << "\nEnter 1 to play again \n";
            cout << "Enter 2 to exit game \n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice != 1 && choice != 2)
            {
                cout << "Invalid choice!\n";
            }
            else if (choice == 2)
            {
                cout << "\nThank you for playing!\n";
                return 0;
            }
        } while (choice != 1 && choice != 2);

    } while (choice == 1);

    return 0;
}