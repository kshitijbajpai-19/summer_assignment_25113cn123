// WAP to print fibonacci series using a function.

#include<iostream>
using namespace std;

void fibonacci(int a)
{
    int x=0, y=1, z;
    for(int i=1; i<=a; i++)
    {
        cout << x << " ";
        z = x + y;
        x = y;
        y = z;

    }
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    if(n<=0)
    {
        cout << "Please enter a positive number.";
        return 0;
    }

    cout << "Fibonacci series: ";
    fibonacci(n);

    return 0;
}