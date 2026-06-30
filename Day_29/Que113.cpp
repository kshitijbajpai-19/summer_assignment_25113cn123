// WAP to create a menu driven calculator

#include <iostream>
using namespace std;

void menu()
{
    cout << "\nMENU-DRIVEN CALCULATOR\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}



int main()
{
    float n1, n2;
    int choice;

    do
    {
        menu();
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter two numbers: ";
            cin >> n1 >> n2;
        }

        switch (choice)
        {
        case 1:
            cout << n1 << " + " << n2 << " = " << n1 + n2 << "\n";
            break;

        case 2:
            cout << n1 << " - " << n2 << " = " << n1 - n2 << "\n";
            break;

        case 3:
            cout << n1 << " x " << n2 << " = " << n1 * n2 << "\n";
            break;

        case 4:
            if (n2 != 0)
                cout << n1 << " / " << n2 << " = " << n1 / n2 << "\n";
            else
                cout << "Division by zero is not allowed.\n";
            break;

        case 5:
            if ((int)n2 != 0)
                cout << (int)n1 << " % " << (int)n2 << " = " << (int)n1 % (int)n2 << "\n";
            else
                cout << "Modulus by zero is not allowed.\n";
            break;

        case 6:
            cout << "Exiting Calculator\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}