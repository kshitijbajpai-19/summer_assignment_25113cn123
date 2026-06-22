// WAP to remove spaces from string

#include <iostream>
using namespace std;

int main()
{
    char str[200];

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Remove spaces by shifting all characters left whenevr a space is found
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            for (int j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            i--; // to recheck current position
        }
    }
    cout << "String after removing spaces: " << str;

    return 0;
}