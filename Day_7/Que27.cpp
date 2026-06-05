    // WAP to find sum of digits of a number using recursive function.

    #include<iostream>
    using namespace std;

    int digitsum(int n)
    {
        if(n==0)
            return 0;
        
        return (n%10) + digitsum(n/10);
    }

    int main()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        if(num < 0)
            num = -num;

        cout << "Sum of digits of " << num << " is " << digitsum(num);
        
        return 0;

    }