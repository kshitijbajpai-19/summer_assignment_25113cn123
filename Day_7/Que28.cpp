// WAP to find reverse of a number using recursive function.

#include <iostream>
using namespace std;

int reverse(int n, int rev=0)
{
    if(n==0)
        return rev;
    
    return  reverse(n/10, rev*10 + n%10);
    
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(n < 0)
        cout << "Reverse of the number: -" << reverse(-n);
    else
        cout << "Reverse of the number: " << reverse(n);
    return 0;
}