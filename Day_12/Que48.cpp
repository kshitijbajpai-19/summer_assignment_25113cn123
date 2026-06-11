// WAP to check perfect number using function

#include<iostream>
using namespace std;

int checkperfect(int a)
{
    int sum = 0;

    for(int i=1; i<=a/2; i++)
    {
        if(a % i == 0)
            sum += i;
    }

    if(sum == a)
        return 1;
    else
       return 0;
}

int main()

{
    int num;
    cout << "Enter a numebr: ";
    cin >> num;

    if(num <= 0)
    {
        cout << "Please enter a positive integer.";
        return 0;
    }

    if(checkperfect(num))
        cout << num << " is a perfect number.";
    else
        cout << num << " is not a perfect number.";

    return 0;
}