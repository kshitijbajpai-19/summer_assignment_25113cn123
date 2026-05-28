// WAP to find factorial of a number (upto 20 only as unsigned long long can store factorial of 20 only).

#include<iostream>
using namespace std;

int main()
{
    int n;
    unsigned long long fact = 1;
    cout << "Enter the number: ";
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        fact = fact*i;
    }
    cout << "The factorial of " << n << " is " << fact;
    return 0;
}