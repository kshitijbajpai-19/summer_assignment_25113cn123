// WAP to input and display array.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n;
    cout << "Enter number of array elements: ";
    cin >> n;

    if(n<=0)
    {
        cout << "Invalid array size";
        return 0;
    }

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array elements: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}