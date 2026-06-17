// WAP to find maximum frequency element.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, maxcount=0, index;
    
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
        int count = 0;
        for(int j=0; j<n; j++)
        {
            if(arr[i]==arr[j])
                count++;
        }
        if(count > maxcount)
            {
                maxcount=count;
                index=i;
            }
    }

    cout << "Maximum frequency element is: " << arr[index];
    return 0;
}