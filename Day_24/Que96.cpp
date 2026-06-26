// WAP to remove duplicate characters from a string

#include <iostream>
using namespace std;

int main()
{
    char str[200];
    int flag;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Check empty string
    if (str[0] == '\0')
    {
        cout << "String is empty";
        return 0;
    }

    // Display string after removing duplicates
    cout << "String after removing duplicates: ";
    for (int i = 0; str[i] != '\0'; i++)
    {
        flag = 0;

        for (int j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << str[i];
        }
    }

    return 0;
}