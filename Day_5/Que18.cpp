// WAP to check strong number.

#include <iostream>
using namespace std;


int factorial(int n)
{
    int fact = 1;
    if (n == 0 || n == 1)
        return fact;
    
       for(int i = 1; i<=n; i++)
       fact = fact * i;
    
    return fact;
        
}

int main()
{
    int num, sum = 0, temp, originalnum;
    cout << "Enter a number: ";
    cin >> num;

    originalnum = num;

    if(num <= 0)
    {
        cout << "Please enter a positive integer.";
        return 0;
    }

    while(num > 0)
    {
        temp = num % 10;
        sum += factorial(temp);
        num /= 10;
    }
    if(sum == originalnum)
        cout << originalnum << " is a strong number.";
    else
        cout << originalnum << " is not a strong number.";

    return 0;    
    }