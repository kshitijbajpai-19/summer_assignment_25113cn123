// WAP to create a Quiz Application

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    // Store questions
    string questions[10] =
        {
            "1. What is the capital of India?",
            "2. Which planet is known as the Red Planet?",
            "3. How many days are there in a leap year?",
            "4. Which loop is guaranteed to execute at least once?",
            "5. Which is the largest ocean in the world?",
            "6. What is the national animal of India?",
            "7. Which gas do plants absorb from the atmosphere?",
            "8. Who invented the telephone?",
            "9. Which is the largest continent?",
            "10. What is the square root of 81?"};

    // Store options for each question
    string options[10][4] =
        {
            {"A. Mumbai", "B. Delhi", "C. Chennai", "D. Kolkata"},
            {"A. Earth", "B. Venus", "C. Mars", "D. Jupiter"},
            {"A. 364", "B. 365", "C. 366", "D. 367"},
            {"A. for", "B. while", "C. do-while", "D. if-else"},
            {"A. Atlantic", "B. Indian", "C. Pacific", "D. Arctic"},
            {"A. Lion", "B. Tiger", "C. Elephant", "D. Leopard"},
            {"A. Oxygen", "B. Nitrogen", "C. Carbon Dioxide", "D. Hydrogen"},
            {"A. Thomas Edison", "B. Alexander Graham Bell", "C. Newton", "D. Einstein"},
            {"A. Africa", "B. Asia", "C. Europe", "D. Australia"},
            {"A. 7", "B. 8", "C. 9", "D. 10"}};

    // Store correct answers
    char answers[10] =
        {
            'B',
            'C',
            'C',
            'C',
            'C',
            'B',
            'C',
            'B',
            'B',
            'C'};

    char userAnswer;
    int score = 0;

    cout << "\nGENERAL QUIZ APPLICATION\n";

    // Display each question
    for (int i = 0; i < 10; i++)
    {
        cout << questions[i] << "\n";

        // Display options
        for (int j = 0; j < 4; j++)
        {
            cout << options[i][j] << "\n";
        }

        // Take user's answer
        do
        {
            cout << "Enter your answer (A/B/C/D): ";
            cin >> userAnswer;
            userAnswer = toupper(userAnswer);

            if (userAnswer < 'A' || userAnswer > 'D')
                cout << "Invalid choice! Please enter A, B, C or D.\n";

        } while (userAnswer < 'A' || userAnswer > 'D');


        // Check answer
        if (userAnswer == answers[i])
        {
            cout << "Correct Answer!\n\n";
            score++;
        }
        else
        {
            cout << "Wrong Answer!\n";
            cout << "Correct Answer: " << answers[i] << "\n\n";
        }
    }

    // Display final result
    cout << "\nRESULT:\n";
    cout << "Correct Answers : " << score << "\n";
    cout << "Wrong Answers   : " << 10 - score << "\n";
    cout << "Score           : " << score << "/10 \n";
    cout << "Percentage      : " << score * 10 << "% \n";

    // Display performance
    if (score == 10)
        cout << "Performance : Excellent!\n";
    else if (score >= 8)
        cout << "Performance : Very Good!\n";
    else if (score >= 5)
        cout << "Performance : Good!\n";
    else
        cout << "Performance : Needs Improvement.\n";

    return 0;
}