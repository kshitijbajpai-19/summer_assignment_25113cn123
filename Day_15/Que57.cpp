// WAP to reverse an array.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n;
    
    cout << "Enter number of array elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int start=0, end=n-1, temp;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    cout << "Reversed array: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}