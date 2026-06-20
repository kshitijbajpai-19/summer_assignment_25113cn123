// WAP to convert lowercase to uppercase

#include<iostream>
using namespace std;

int main()
{
    char str[100];

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 100);

    // Convert lowercase to uppercase
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    // Display result
    cout << "Uppercase string: " << str;

    return 0;
}