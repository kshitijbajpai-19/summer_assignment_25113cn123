//Write program to check whether a number is palindrome.

#include<iostream>
using namespace std;

int main()
{
    long long n,rem,rev=0,temp;
    cout << "Enter a number: ";
    cin >> n;

    temp = n;
    while (n>0)
    {
        rem = n%10;
        rev = rev*10 + rem;
        n = n/10;
    }

    if (rev == temp)
        cout << "The number is a palindrome.";
    else
        cout << "The number is not a palindrome.";
    
    return 0;

}
