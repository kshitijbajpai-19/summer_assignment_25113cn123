//WAP to find sum of digits of a number.

#include<iostream>
using namespace std;

int main()
{
    int n,a,sum=0;
    cout << "Enter a number: ";
    cin >> n;

    while(n>0)
    {
        a = n%10;
        sum = sum +a;
        n = n/10;

    }
    cout << "Sum of digits of the given number is: " << sum;
    return 0;
}