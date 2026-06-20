// WAP to reverse string0

#include<iostream>
using namespace std;

int main()
{
    char str[100];
    int len = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 100);
    
    // Count number of character using loops and find index of last character in string
    while(str[len] != '\0')
    {
        len++;
    }
    len--;
    
    
    // Reverse string 
    int i=0;
    while(i<len)
    {
        char temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }

    // Display string length
    cout << "Reversed string: " << str;

    return 0;
}

