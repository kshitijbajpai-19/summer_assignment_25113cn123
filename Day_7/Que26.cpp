// WAP to print a fibonacci series using recursive function.

#include<iostream>
using namespace std;


int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int num;
    cout << "Enter the number of terms: ";
    cin >> num;

    if(num < 1)
    {
        cout << "Number of terms must be at least 1." << endl;
        return 1;
    }

    cout << "Fibonacci series: ";
    for(int i=0; i<num; i++)
        cout << fibonacci(i) << " ";
    
    return 0;
}