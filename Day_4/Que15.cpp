// WAP to check Armstrong number.

#include<iostream>
using namespace std;

int main()
{
    int num, originalnum, remainder, result = 0,temp,count = 0,power = 1;
    cout << "Enter an integer: ";
    cin >> num;
    temp = num;
    while(temp != 0)
    {
        temp /= 10;
        count++;
    }
    originalnum = num;

    while(num != 0)
    {
        remainder = num % 10;
        for(int i=1; i<=count; i++)
            power = power * remainder;
        result += power;
        power = 1;
        num /= 10;
    }

    if(result == originalnum)
        cout << originalnum << " is an Armstrong number.";
    else
        cout << originalnum << " is not an Armstrong number.";
    
    return 0;
}