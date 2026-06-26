// WAP to find common characters in two strings

#include <iostream>
using namespace std;

int main()
{
    char str1[100], str2[100];

    // Input strings
    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    cout << "Common characters: ";

    // Find common characters
    for (int i = 0; str1[i] != '\0'; i++)
    {
        int flag = 0;
        if (str1[i] == ' ')    // Ignore spaces
            continue;
        // Check if character exists in second string
        for (int j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                flag = 1;
                break;
            }
        }

        // Print common character only once
        if (flag == 1)
        {
            int duplicate = 0;

            for (int k = 0; k < i; k++)
            {
                if (str1[k] == str1[i])
                {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0)
            {
                cout << str1[i] << " ";
            }
        }
    }

    return 0;
}