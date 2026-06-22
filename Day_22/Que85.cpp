// WAP to check palindrome string

#include<iostream>
using namespace std;

int main()
{
    char str[100];
    int len = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 100);
    
    // Find length of string
    while(str[len] != '\0')
    {
        len++;
    }
    
    
    // Compare characters to check palindrome
    for(int i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len- 1 - i])
        {
            cout << "The string is not palindrome";
            return 0;
        }
    }
    cout << "The string is palindrome";

    return 0;
}

