// WAP to find nth Fibonacci tern.

    #include<iostream>
    using namespace std;

    int main()
    {
        int n, a=0, b=1, c;
        cout << "Enter the term number: ";
        cin >> n;

        if(n == 0)
            cout << "The " << n << "th term in Fibonacci series is: " << a;
        else if(n == 1)
            cout << "The " << n << "th term in Fibonacci series is: " << b;
        else
        {
            for(int i=2; i<=n; i++)
            {
                c = a+b;
                a = b;
                b = c;
            }
            cout << "The " << n << "th term in Fibonacci series is: " << c;
        }
        return 0;
    }