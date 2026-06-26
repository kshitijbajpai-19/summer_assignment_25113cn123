// WAP to check anagram strings

#include<iostream>
using namespace std;

int main()
{
    char str1[200], str2[200];
    int len1 = 0, len2=0;

    // Input string
    cout << "Enter first string: ";
    cin.getline(str1, 200);

    cout << "Enter second string: ";
    cin.getline(str2, 200);
    
    // Count number of character using loops
    while(str1[len1] != '\0')
    {
        len1++;
    }
    while(str2[len2] != '\0')
    {
        len2++;
    }
    if(len1!=len2)
    {
        cout << "The strings are not anagrams";
        return 0;
    }

    // Compare frequencies
    for(int i = 0; str1[i] != '\0'; i++)
    {
        int count1 = 0, count2 = 0;

        for(int j = 0; str1[j] != '\0'; j++)
        {
            if(str1[i] == str1[j] ||
               str1[i] == str1[j] + 32 ||
               str1[i] == str1[j] - 32)
            {
                count1++;
            }
        }

        for(int j = 0; str2[j] != '\0'; j++)
        {
            if(str1[i] == str2[j] ||
               str1[i] == str2[j] + 32 ||
               str1[i] == str2[j] - 32)
            {
                count2++;
            }
        }
        if(count1 != count2)
        {
            cout << "The strings are not anagrams";
            return 0;
        }
    }

    cout << "The strings are anagrams";

    return 0;
}