// WAP to count words in a sentense

#include <iostream>
using namespace std;

int main()
{
    char str[200];
    int count = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Count number of words and diplay count
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((i == 0 && str[i] != ' ') || (str[i] != ' ' && str[i - 1] == ' '))
        {
            count++;
        }
    }

    cout << "Number of words: " << count;

    return 0;
}