// WAP to calculate sum of first n natural numbers.

#include <iostream>
using namespace std;

int main()
{
    int n, sum=0;

    cout << "Enter the number upto which you want to calculate the sum of natural numbers: ";
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        sum += i;

    }
    cout << "The sum of first " << n << " natural numbers is " <<sum;
    return 0;
}