// WAP to remove duplicate elements

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

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k=j; k<n-1; k++)
                    arr[k] = arr[k+1];
                
                n = n-1;
                j = j-1;    
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;

}