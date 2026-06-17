// WAP to rotate array right.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, temp;
    
    cout << "Enter number of array elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    temp = arr[n-1];
    for(int i=n-1; i>0; i--)
        arr[i] = arr[i-1];
    arr[0] = temp;

    cout << "Right rotated array: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}