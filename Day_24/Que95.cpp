// WAP to find the longest word

#include <iostream>
using namespace std;

int main()
{
    char str[200];
    int count = 0, maxcount = 0, currentword = 0, wordstart = 0;

    // Input string
    cout << "Enter string: ";
    cin.getline(str, 200);

    // Check empty string
    if (str[0] == '\0')
    {
        cout << "String is empty";
        return 0;
    }

    // Count length of each word and store starting index of the longest word found
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            count++;
        }
        else
        {
            if (maxcount < count)
            {
                maxcount = count;
                wordstart = currentword;
            }

            count = 0;
            currentword = i + 1;
        }
    }

    if (maxcount < count) // To check last word
    {
        maxcount = count;
        wordstart = currentword;
    }

    // Display longest word
    cout << "Longest word: ";
    for (int i = wordstart; i < wordstart + maxcount; i++)
    {
        cout << str[i];
    }

    return 0;
}