// WAP to find duplicates in array.

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
    
    cout << "Duplicate elements: ";

    
    for(int i=0; i<n; i++)
    {
        // To check if the number has already been checked for duplicate values
        int flag = 0;
        for(int j=0; j<i; j++)
        {
            if(arr[i]==arr[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
            continue;

        for(int k=i+1; k<n; k++)
        {
            if(arr[i]==arr[k])
            {
                cout << arr[i] << " ";
                break;
            }
        }
    }
    return 0;
}