// WAP to print number pyramid.

#include<iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=row-i; j++)
        {
            cout << " ";
        }
        for(int k=1; k<=i; k++)
        {
           cout << k;
        }
        for(int l=i-1; l>=1; l--)
        {
            cout << l;
        }

        cout << "\n";
    }
    return 0;
}