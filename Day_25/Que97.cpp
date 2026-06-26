// WAP to merge two sorted arrays

#include <iostream>
using namespace std;

int main()
{
    int arr1[100], arr2[100], mergedarr[200], n1, n2;

    // Input elements of both sorted arrays
    cout << "Enter number of elements of first sorted array: ";
    cin >> n1;
    // Check valid array size of first sorted array
    if (n1 < 0 || n1 > 100)
    {
        cout << "Invalid array size";
        return 0;
    }
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter number of elements of second sorted array: ";
    cin >> n2;
    // Check valid array size of second sorted array
    if (n2 < 0 || n2 > 100)
    {
        cout << "Invalid array size";
        return 0;
    }
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    // Compare elements of both arrays and store the smaller element in merged array
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            mergedarr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedarr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of first array
    while (i < n1)
    {
        mergedarr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of second array
    while (j < n2)
    {
        mergedarr[k] = arr2[j];
        j++;
        k++;
    }

    // Display merged array
    cout << "Merged sorted array: ";
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << mergedarr[i] << " ";
    }

    return 0;
}