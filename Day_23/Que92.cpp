// WAP to find maximum occurring character

#include <iostream>
using namespace std;

int main()
{
    char str[200], ch = 0;
    int maxcount = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Check empty string
    if (str[0] == '\0')
    {
        cout << "String is empty";
        return 0;
    }

    // Count frequency of each character and compare it with previous frequency
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ') // Ignore spaces
        {
            continue;
        }
        int count = 0;
        for (int j = 0; str[j] != '\0'; j++)
        {
            if ((str[i] == str[j]) || (str[i] == str[j] + 32) || (str[i] == str[j] - 32))
            {
                count++;
            }
        }
        // Check if the character is repeating and display the result
        if (count > maxcount)
        {
            maxcount = count;
            ch = str[i];
        }
    }
    if (maxcount == 0)
    {
        cout << "No non-space characters found";
        return 0;
    }
    cout << "The maximum occurring character is: " << ch;
    cout << "\nFrequency: " << maxcount;
    return 0;
}