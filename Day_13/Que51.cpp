// WAP to find largest and smallest element.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, largest, smallest;
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
    smallest = arr[0];
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]<smallest)
            smallest = arr[i];
        else if(arr[i]>largest)
            largest = arr[i];
    }  

    cout << "Largest element= " << largest << "\n";
    cout << "Smallest element= " << smallest;

    return 0;
}