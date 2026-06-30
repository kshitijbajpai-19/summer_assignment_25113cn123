// WAP to Create a Menu-Driven String Operations System

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char str[200];

void menu()
{
    cout << "\nSTRING OPERATIONS SYSTEM\n";
    cout << "1. Enter String\n";
    cout << "2. Display String\n";
    cout << "3. Find Length\n";
    cout << "4. Concatenate String\n";
    cout << "5. Compare String\n";
    cout << "6. Reverse String\n";
    cout << "7. Count Vowels and Consonants\n";
    cout << "8. Convert to Uppercase\n";
    cout << "9. Convert to Lowercase\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

void enter_string()
{
    cout << "Enter a string: ";
    cin.getline(str, 200);

    cout << "String stored successfully.\n";
}

void display_string()
{
    cout << "String: " << str << "\n";
}

void string_length()
{
    cout << "Length: " << strlen(str) << "\n";
}

void count_vowels_consonants()
{
    int vowels = 0, consonants = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);

        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Number of Vowels = " << vowels << "\n";
    cout << "Number of Consonants = " << consonants << "\n";
}

void concatenate_string()
{
    char str2[100];

    cout << "Enter another string: ";
    cin.getline(str2, 100);

    strcat(str, str2);
    
    cout << "String concatenated successfully!\n";
    cout << "Concatenated String: " << str << "\n";
}

void compare_string()
{
    char str2[100];

    cout << "Enter another string: ";
    cin.getline(str2, 100);

    int result = strcmp(str, str2);

    if (result == 0)
        cout << "Both strings are equal.\n";
    else if (result < 0)
        cout << "First string is smaller.\n";
    else
        cout << "First string is greater.\n";
}

void reverse_string()
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    cout << "String reversed successfully.\n";

    cout << "Reversed String: " << str << "\n";
}

void uppercase_string()
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
    cout << "String converted to uppercase.\n";
    cout << "Uppercase String: " << str << "\n";
}

void lowercase_string()
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);

    cout << "Lowercase String = " << str << "\n";
}

int main()
{
    int choice;

    do
    {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            enter_string();
            break;

        case 2:
            display_string();
            break;

        case 3:
            string_length();
            break;

        case 4:
            concatenate_string();
            break;

        case 5:
            compare_string();
            break;

        case 6:
            reverse_string();
            break;

        case 7:
            count_vowels_consonants();
            break;

        case 8:
            uppercase_string();
            break;

        case 9:
            lowercase_string();
            break;

        case 10:
            cout << "Exiting Program\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 10);

    return 0;
}