// WAP to find first repeating character

#include <iostream>
using namespace std;

int main()
{
    char str[200];

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Count frequency of each character

    for (int i = 0; str[i] != '\0'; i++)
    {
        int count = 0;
        for (int j = 0; str[j] != '\0'; j++)
        {
            if ((str[i] == str[j]) || (str[i] == str[j] + 32) || (str[i] == str[j] - 32))
            {
                count++;
            }
        }
        // Check if the character is repeating and display the result
        if (count > 1)
        {
            cout << "First repeating character is: " << str[i];
            return 0;
        }
    }

    cout << "All characters are non-repeating";
    return 0;
}