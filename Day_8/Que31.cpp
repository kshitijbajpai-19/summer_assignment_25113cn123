// WAP to print character triangle pattern.

#include<iostream>
using namespace std;

int main()
{
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    if(rows > 26)
    {
        cout << "Number of rows exceed the total number of characters in the English alphabet";
        return 0;
    }

    for(int i = 1; i <= rows; i++)
    {
        char ch = 'A';

        for(int j = 1; j <=i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << "\n";
    }
    return 0;
}