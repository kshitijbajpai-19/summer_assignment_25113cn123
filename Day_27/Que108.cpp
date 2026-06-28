// WAP to create a Marksheet Generation System

#include <iostream>
using namespace std;

struct STUDENT
{
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
};

void menu()
{
    cout << "\nMARKSHEET GENERATION SYSTEM\n";
    cout << "1. Enter Student Details\n";
    cout << "2. Display Marksheet\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    STUDENT s[100];
    int count = 0;
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (count == 100)
            {
                cout << "\nMaximum number of marksheets reached.\n";
                break;
            }

            cout << "\nEnter Roll Number: ";
            cin >> s[count].roll;

            bool exists = false;

            for (int i = 0; i < count; i++)
            {
                if (s[i].roll == s[count].roll)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "\nRoll Number already exists.\n";
                break;
            }

            cout << "Enter Name: ";
            cin.ignore();
            cin.getline(s[count].name, 50);

            s[count].total = 0;

            cout << "Enter marks of 5 subjects:\n";
            for (int i = 0; i < 5; i++)
            {
                cout << "Subject " << i + 1 << ": ";
                cin >> s[count].marks[i];
                s[count].total += s[count].marks[i];
            }

            s[count].percentage = s[count].total / 5;

            if (s[count].percentage >= 90)
                s[count].grade = 'A';
            else if (s[count].percentage >= 80)
                s[count].grade = 'B';
            else if (s[count].percentage >= 70)
                s[count].grade = 'C';
            else if (s[count].percentage >= 60)
                s[count].grade = 'D';
            else
                s[count].grade = 'F';

            count++;

            cout << "\nMarksheet generated successfully.\n";
            break;
        }

        case 2:
        {
            if (count == 0)
            {
                cout << "\nNo marksheets available.\n";
                break;
            }

            int roll;
            bool found = false;

            cout << "\nEnter Roll Number: ";
            cin >> roll;

            for (int i = 0; i < count; i++)
            {
                if (s[i].roll == roll)
                {
                    cout << "\nMARKSHEET\n";
                    cout << "Roll Number : " << s[i].roll << "\n";
                    cout << "Name        : " << s[i].name << "\n";

                    for (int j = 0; j < 5; j++)
                    {
                        cout << "Subject " << j + 1 << " : " << s[i].marks[j] << "\n";
                    }

                    cout << "\n";
                    cout << "Total       : " << s[i].total << "\n";
                    cout << "Percentage  : " << s[i].percentage << "%" << "\n";
                    cout << "Grade       : " << s[i].grade << "\n";

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nMarksheet not found.\n";
            }

            break;
        }

        case 3:
            cout << "\nExiting Program\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}