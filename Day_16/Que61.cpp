// WAP to find missing number in array.
// Assuming the array contains n distinct numbers from 1 to n+1 with exactly one number missing.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, actual_sum=0, array_sum=0;
    
    cout << "Enter number of array elements: ";
    cin >> n;

    if(n<=0)
    {
        cout << "Invalid array size";
        return 0;
    }

    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    actual_sum = (n+1)*(n+2)/2;
    for(int i=0; i<n; i++)
    {
        array_sum += arr[i];
    }

    cout << "Missing number is: " << actual_sum - array_sum;
    return 0;
    
}