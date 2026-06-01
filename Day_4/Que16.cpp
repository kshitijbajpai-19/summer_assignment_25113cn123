//WAP to print armstrong numbers in a range.

#include<iostream>
using namespace std;

int main()
{
    int lower, upper;
    cout << "Enter start of the range: ";
    cin >> lower;
    cout << "Enter end of the range: ";
    cin >> upper;

    cout << "Armstrong numbers between " << lower << " and " << upper << " are: ";

    for(int i = lower; i <= upper; i++)
    {
        int num,originalnum, remainder, result = 0,temp,count = 0,power = 1;
        num = i;
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
            for(int j=1; j<=count; j++)
                power = power * remainder;
            result += power;
            power = 1;
            num /= 10;
        }

        if(result == originalnum)
            cout << originalnum << " ";
    }
    return 0;
}