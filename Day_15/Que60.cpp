// WAP to move zeroes to the end.

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
    
    int index=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
            arr[index++] = arr[i];
    }
    for(int i=index; i<n; i++)
        arr[i] = 0;
    
    cout << "Array after moving zeroes to the end: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    
    return 0;
}