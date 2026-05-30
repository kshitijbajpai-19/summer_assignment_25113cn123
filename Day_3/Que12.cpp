//Write a program to find LCM of two numbers.

#include<iostream>
using namespace std;

int main()
{
    int n1, n2, lcm;
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;

    lcm = (n1 > n2) ? n1 : n2;

    while(true)
    {
        if(lcm % n1 == 0 && lcm % n2 ==0)
        {
            cout << "LCM of " << n1 << " and " << n2 << " is " << lcm;
            break;
        }
        lcm++;
    
    }
    return 0;
}