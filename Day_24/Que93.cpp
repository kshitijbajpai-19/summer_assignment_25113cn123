// WAP to check string rotation

#include <iostream>
using namespace std;

int main()
{
    char str1[100], str2[100], temp[200];
    int len1 = 0, len2 = 0;

    // Input strings and check whether they are empty
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    if (str1[0] == '\0')
    {
        cout << "String is empty";
        return 0;
    }

    cout << "Enter second string: ";
    cin.getline(str2, 100);
    if (str2[0] == '\0')
    {
        cout << "String is empty";
        return 0;
    }

    // Find lengths
    while (str1[len1] != '\0')
        len1++;

    while (str2[len2] != '\0')
        len2++;

    // Check whether string lengths are equal
    if (len1 != len2)
    {
        cout << "Strings are not rotations of each other";
        return 0;
    }

    // Append str1 with itself
    int k = 0;

    for (int i = 0; i < len1; i++)
        temp[k++] = str1[i];

    for (int i = 0; i < len1; i++)
        temp[k++] = str1[i];

    temp[k] = '\0';

    // Search str2 in temp
    int found = 0, j = 0;

    for (int i = 0; temp[i] != '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (temp[i + j] != str2[j])
                break;
        }

        if (str2[j] == '\0')
        {
            found = 1;
            break;
        }
    }

    // Display if the strings are rotations of each other or not
    if (found)
        cout << "Strings are rotations of each other";
    else
        cout << "Strings are not rotations of each other";

    return 0;
}