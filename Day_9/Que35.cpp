// WAP to print repeated character pattern.

#include<iostream>
using namespace std;

int main()
{
    int rows;
    char ch = 'A';

    cout << "Enter the number of rows: ";
    cin >> rows;

    if(rows > 26)
    {
        cout << "Number of rows exceed the total number of characters in the English alphabet.";
        return 0;
    }

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= i; j++)
            cout << ch << " ";
        cout << "\n";
        ch++;
    }
    return 0;
}