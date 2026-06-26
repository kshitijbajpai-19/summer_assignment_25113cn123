// WAP to compress a string

#include <iostream>
using namespace std;

int main()
{
    char str[200];
    int count = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Check empty string
    if (str[0] == '\0')
    {
        cout << "String is empty";
        return 0;
    }

    // Display compressed string
    cout << "Compressed String: ";
    for (int i = 0; str[i] != '\0'; i += count)
    {
        count = 1;

        while (str[i] == str[i + count])
        {
            count++;
        }

        cout << str[i] << count;
    }

    return 0;
}