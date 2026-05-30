// WAP to find GCD of two nnumber.

#include<iostream>
using namespace std;

int main()
{
    int n1,n2,gcd;
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;

    for (int i=1; i<=n1 && i<=n2; i++)
    {
        if (n1%i==0 && n2%i==0)
            gcd = i;
    }
    cout << "GCD of " << n1 << " and " << n2 << " is " << gcd;
    return 0;
}