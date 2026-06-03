// WAP to find x^n without using pow()

#include<iostream>
using namespace std;

int main()
{
    int num, power, absolutepower;
    double result = 1;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter power: ";
    cin >> power;

    if(num == 0 && power <= 0)
    {
        cout << "Undefined result.";
        return 0;
    }

    absolutepower = power;
    if(power < 0)
        absolutepower = -power;

    for(int i = 0; i<absolutepower; i++)
        result = result * num;

    if(power < 0)
        result = 1 / result;

    cout << num << " raised to the power " << power << " = " << result;
    return 0;
}