// WAP to convert decimal to binary.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int decimal, remainder, flag = 1;
    string binary = "";

    cout << "Enter a decimal number: ";
    cin >> decimal;

    if(decimal == 0)
    {
        binary = "0";
        cout << "Binary number: " << binary;
        return 0;
    }

    if(decimal < 0)
    {
        flag = -1;
        decimal = -decimal;
    }

    while (decimal > 0)
    {
        remainder = decimal % 2;
        binary = char(remainder + '0') + binary;
        decimal /= 2;
    }

    if(flag == -1)
        binary = "-" + binary;
    cout << "Binary number: " << binary;

    return 0;
}