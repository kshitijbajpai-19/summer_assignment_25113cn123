// WAP to print largest prime factor of a number.

#include<iostream>
using namespace std;

int checkprime(int n)
{
    int flag = 1;
    if(n <= 1)
        flag = 0;
    
    for(int i=2; i<=n/2; i++)
    {
        if(n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int num, largestprime=0;
    cout << "Enter a number: ";
    cin >> num;

    if(num <= 1)
    {
        cout << "Please enter a positive integer greater than 1.";
        return 0;
    }

    if(checkprime(num) == 1)
        largestprime = num;
    else
    {
        for(int i=2; i<=num/2; i++)
        {
            if(num %i == 0 && checkprime(i)==1)
                largestprime = i;
        }
    }

    cout << "Largest prime factor of " << num << " is: " << largestprime;

    return 0;

}