// WAP to find sum and average of array.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, sum=0;
    float avg;
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

    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    avg = (float) sum/n;
    cout << "Sum of array elements: " << sum << "\n";
    cout << "Average of array elements: " << avg;

    return 0;
}