// WAP to find maximum of three numbers using function.

#include<iostream>
using namespace std;

int maximum( int a, int b, int c)
{
    if(a>=b && a>=c)
        return a;
    
    else if(b>=a && b>=c)
        return b;
    
    else
        return c;
}

int main()
{
    int num1, num2, num3;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;

    cout << "The maximum number among the three numbers is: " << maximum(num1, num2, num3);

    return 0;
}