// WAP to check armstrong number using a function.

#include<iostream>
using namespace std;

int checkarmstrong(int a)
{
    int originalnum, remainder, result = 0,temp,count = 0,power = 1;
    temp = a;
    while(temp != 0)
    {
        temp /= 10;
        count++;
    }
    originalnum = a;

    while(a != 0)
    {
        remainder = a % 10;
        for(int i=1; i<=count; i++)
            power = power * remainder;
        result += power;
        power = 1;
        a /= 10;
    }

    if(result == originalnum)
        return 1;
    else
        return 0;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (checkarmstrong(num))
        cout << num << " is an armstrong number.";
    else
        cout << num << " is not an armstrong number.";
    
    return 0;
}