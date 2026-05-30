// WAP to print prime numbers in a range.

#include<iostream>
using namespace std;

int main()
{
    int start, end, i, j, flag;
    cout << "Enter the starting number: ";
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;

    cout << "Prime numbers between " << start << " and " << end << " are: ";

    for(i=start; i<=end; i++)
    {
        if(i<=1)
            continue;
        flag = 0;

        for(j=2; j<=i/2; j++)
        {
            if(i%j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout << i << " ";
    }
    return 0;
}