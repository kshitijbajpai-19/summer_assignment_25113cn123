// WAP to find string length without using strlen()

#include<iostream>
using namespace std;

int main()
{
    char str[100];
    int len = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 100);
    
    // Count number of character using loops
    while(str[len] != '\0')
    {
        len++;
    }

    // Display string length
    cout << "Length of string is: " << len;

    return 0;
}

