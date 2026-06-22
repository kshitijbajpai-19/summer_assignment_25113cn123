// WAP to diplay character frequency

#include<iostream>
using namespace std;

int main()
{
    char str[200], key;
    int count = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Input the character to be checked
    cout << "Enter character to count frequency: ";
    cin >> key;
    
    
    // Count frequency of the given character
    for(int i = 0; str[i]!='\0'; i++)
    {
        if(key==str[i] || key == str[i] + 32 || key == str[i] - 32)
        {
            count++;
        }
    }
    cout << "Frequency: " << count;

    return 0;
}

