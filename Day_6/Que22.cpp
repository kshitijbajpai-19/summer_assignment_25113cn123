// WAP to convert binary to decimal.

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
    string binary;
    int decimal = 0, power, start = 0;

    cout << "Enter a binary number: ";
    cin >> binary;

    if (binary[0] == '-')
        start = 1;

    for(int i = binary.length() - 1;  i>=start; i--)
    {
        if(binary[i] == '1')
        {
            power = binary.length() - 1 - i;
            decimal += pow(2, power);
        }
        else if(binary[i] != '0')
        {
            cout << "Invalid binary number.";
            return 0;
        }
    }
    if(binary[0] == '-')
        decimal = -decimal;
    cout << "Decimal number: " << decimal;
    return 0;
}