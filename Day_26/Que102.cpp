// WAP to create a Voting Eligibility System

#include <iostream>
using namespace std;

int main()
{
    int age, choice;
    char citizenship;

    do
    {
        // Input age
        cout << "\nEnter your age: ";
        cin >> age;

        // Validate age
        if (age < 0 || age > 120)
        {
            cout << "\nInvalid age entered.\n";
        }
        else
        {
            // Input citizenship
            cout << "Are you an Indian citizen? (Y/N): ";
            cin >> citizenship;

            cout << "\n";

            // Check eligibility
            if ((citizenship == 'Y' || citizenship == 'y') && age >= 18)
            {
                cout << "Congratulations! You are eligible to vote.\n";
            }
            else if ((citizenship == 'Y' || citizenship == 'y') && age < 18)
            {
                cout << "Sorry! You are not eligible to vote.\n";
                cout << "You can vote after " << 18 - age << " year(s).\n";
            }
            else if (citizenship == 'N' || citizenship == 'n')
            {
                cout << "Sorry! Only Indian citizens are eligible to vote in India.\n";
            }
            else
            {
                cout << "Invalid citizenship input.\n";
            }
        }

        // Ask user whether to continue
        do
        {
            cout << "\nEnter 1 to check another person.\n";
            cout << "Enter 2 to exit.\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice != 1 && choice != 2)
            {
                cout << "Invalid choice! Please try again.\n";
            }

        } while (choice != 1 && choice != 2);

    } while (choice == 1);

    cout << "\nThank you for using the Voting Eligibility System.\n";

    return 0;
}