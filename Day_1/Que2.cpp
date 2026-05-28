//WAP to print multiplication table of a given number.

#include<iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number: ";
    cin >> n;

    cout << "Multiplication table of " << n << " is " << endl;

    for(int i=1; i<=10; i++)
    {
        cout << n << " x " << i << " = " << n*i << endl;
    }
    return 0;
}