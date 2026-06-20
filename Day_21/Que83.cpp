// WAP to count vowels and consonants

#include<iostream>
using namespace std;

int main()
{
    char str[100];
    int vowels = 0, consonants = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 100);

    // Count vowels and consonants
    for(int i = 0; str[i] != '\0'; i++)
    {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) // Reject spaces, digits and other special characters
        {
            if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
               str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    // Display result
    cout << "Number of vowels: " << vowels << "\n";
    cout << "Number of consonants: " << consonants;

    return 0;
}