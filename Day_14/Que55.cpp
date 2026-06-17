// WAP to find second largest element in an array.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, largest, secondlargest;

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

    largest = arr[0];
    secondlargest = -999999999;
    for(int i=1; i<n; i++)
    {
        if(largest < arr[i])
            largest = arr[i];
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]>secondlargest && arr[i]<largest)
            secondlargest = arr[i];
    }

    if(secondlargest == -999999999)
        cout << "No second largest element found in the array";
    else
        cout << "The second largest element in the array is: " << secondlargest;

    return 0;
}