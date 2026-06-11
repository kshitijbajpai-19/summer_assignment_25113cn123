// WAP to check prime number using function

#include<iostream>
using namespace std;

int prime(int a)
{
    for(int i=2; i<=a/2; i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(num<=0)
    {
        cout << "Please enter a positive integer.";
        return 0;
    }

    if(num==1)
    {
        cout << "1 is neither prime nor composite.";
        return 0;
    }

    if(prime(num))
        cout << "The given number is a prime number.";
    else  
        cout << "The given number is not a prime number.";
    
    return 0;
}