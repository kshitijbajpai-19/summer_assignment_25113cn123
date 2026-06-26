// WAP to sort names alphabetically

#include <iostream>
using namespace std;

int main()
{
    char names[100][100], temp[100];
    int n;

    // Input number of names
    cout << "Enter number of names: ";
    cin >> n;
    cin.ignore();

    // Check valid input
    if (n <= 0 || n > 100)
    {
        cout << "Invalid number of names";
        return 0;
    }

    // Input names
    cout << "Enter names:\n";
    for (int i = 0; i < n; i++)
    {
        cin.getline(names[i], 100);
    }

    // Sort names alphabetically
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int k = 0;

            while (names[j][k] == names[j + 1][k] &&
                   names[j][k] != '\0' &&
                   names[j + 1][k] != '\0')
            {
                k++;
            }

            if (names[j][k] > names[j + 1][k])
            {
                // Swap names
                int m = 0;
                while (names[j][m] != '\0')
                {
                    temp[m] = names[j][m];
                    m++;
                }
                temp[m] = '\0';

                m = 0;
                while (names[j + 1][m] != '\0')
                {
                    names[j][m] = names[j + 1][m];
                    m++;
                }
                names[j][m] = '\0';

                m = 0;
                while (temp[m] != '\0')
                {
                    names[j + 1][m] = temp[m];
                    m++;
                }
                names[j + 1][m] = '\0';
            }
        }
    }

    // Display sorted names
    cout << "\nNames in alphabetical order:\n";
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}