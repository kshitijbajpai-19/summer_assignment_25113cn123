// WAP to create ATM simulation

#include <iostream>
using namespace std;

int main()
{
    long long balance = 100000, money, withdrawmoney;
    int choice, pin;

    cout << "ATM Simulation\n";
    cout << "Note: The default PIN for this simulation is 1234\n\n";

    for (int i = 3; i > 0; i--)
    {
        cout << "Enter PIN: ";
        cin >> pin;

        if (pin == 1234)
        {
            do
            {
                cout << "\n MENU \n";
                cout << "1. Check Balance \n 2. Withdrawal \n 3. Deposit \n 4. Exit \n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << " Current Balance: Rs. " << balance << "\n";
                    break;

                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawmoney;
                    if (withdrawmoney > balance)
                    {
                        cout << "Insufficient balance! \n";
                        break;
                    }
                    else if (withdrawmoney <= 0)
                    {
                        cout << "Invalid withdrawal amount! \n";
                        break;
                    }
                    else
                    {
                        balance -= withdrawmoney;
                        cout << "\n Rs. " << withdrawmoney << " withdrawn successfully! \n";
                        cout << "Current Balance: Rs. " << balance << "\n";
                        break;
                    }

                case 3:
                    cout << " Enter amount to be deposited: ";
                    cin >> money;
                    if (money <= 0)
                    {
                        cout << "Invalid deposit amount! \n";
                        break;
                    }
                    else
                    {
                        balance += money;
                        cout << "\n Rs. " << money << " deposited successfully! \n Current Balance: Rs. " << balance << "\n";
                        break;
                    }
                case 4:
                    cout << "Thank you for using our ATM! \n";
                    break;
                default:
                    cout << "Invalid choice!\n";
                    break;
                }
            } while (choice != 4);
            return 0;
        }
        else
        {
            cout << "Wrong PIN! \n";
            cout << "You have " << i - 1 << " attempts left \n";
        }
    }
    cout << "All PIN attempts exhausted! Account locked.\n";
    return 0;
}