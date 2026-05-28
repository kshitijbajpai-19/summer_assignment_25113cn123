// WAP to count digits in a number.

#include<iostream>
using namespace std;

int main()
{
    int a, count=0;
    cout << "Enter the number: ";
    cin >> a;

    while(a!=0)
    {
        a = a/10;
        count++;
    }
    cout << "The number of digits in the given number is " << count;
    return 0;

}