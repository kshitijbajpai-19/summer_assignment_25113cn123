// WAP to fund product of digits.

#include<iostream>
using namespace std;

int main()
{
    int n,rem,prod=1;
    cout << "Enter a number: ";
    cin >> n;

    while (n>0)
    {
        rem = n%10;
        prod = prod*rem;
        n = n/10;
    }
    cout << "Product of the digits is: " << prod;
    return 0;
}