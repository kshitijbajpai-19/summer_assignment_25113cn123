// WAP to check palindrome using a function.

#include<iostream>
using namespace std;

int checkpalindrome(long long a)
{
    int temp;
    long long reverse=0, originalnum;

    originalnum = a;
    while(a!=0)
    {
        temp = a%10;
        reverse = reverse*10 + temp;
        a = a/10;
    }

    if(reverse==originalnum)
        return 1;
    else
        return 0;

}

int main()
{
    long long num;

    cout << "Enter a number: ";
    cin >> num;

    if(checkpalindrome(num))
        cout << "The number is palindrome.";
    else
        cout << "The number is not palindrome.";
    
    return 0;
}