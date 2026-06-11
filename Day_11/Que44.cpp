    // WAP to find factorial using a function.

    #include<iostream>
    using namespace std;

    long long factorial(int a)
    {
        long long fact=1;
        for(int i=1; i<=a; i++)
            fact*=i;
        
        return fact;
    }

    int main()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        if(num<0)
        {
            cout << "Please enter a positive integer.";
            return 0;
        }

        cout << "The factorial of " << num << " is " << factorial(num);

        return 0;
    }