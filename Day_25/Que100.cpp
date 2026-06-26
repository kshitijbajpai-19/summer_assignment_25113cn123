// WAP to sort words by length

#include <iostream>
using namespace std;

int main()
{
    char words[100][100], temp[100];
    int n;

    // Input number of words
    cout << "Enter number of words: ";
    cin >> n;

    // Check valid input
    if (n <= 0 || n > 100)
    {
        cout << "Invalid number of words";
        return 0;
    }

    // Input words
    cout << "Enter words: ";
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    // Sort words according to length
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Find length of first word
            int len1 = 0;
            while (words[j][len1] != '\0')
            {
                len1++;
            }

            // Find length of second word
            int len2 = 0;
            while (words[j + 1][len2] != '\0')
            {
                len2++;
            }

            // Swap if first word is longer
            if (len1 > len2)
            {
                int k = 0;

                while (words[j][k] != '\0')
                {
                    temp[k] = words[j][k];
                    k++;
                }
                temp[k] = '\0';

                k = 0;
                while (words[j + 1][k] != '\0')
                {
                    words[j][k] = words[j + 1][k];
                    k++;
                }
                words[j][k] = '\0';

                k = 0;
                while (temp[k] != '\0')
                {
                    words[j + 1][k] = temp[k];
                    k++;
                }
                words[j + 1][k] = '\0';
            }
        }
    }

    // Display sorted words
    cout << "\nWords sorted by length:\n";
    for (int i = 0; i < n; i++)
    {
        cout << words[i] << "\n";
    }

    return 0;
}