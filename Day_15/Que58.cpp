// WAP to rotate array left.

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

    temp = arr[0];
    for(int i=0; i<n-1; i++)
        arr[i] = arr[i+1];
    arr[n-1] = temp;

    cout << "Left rotated array: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}