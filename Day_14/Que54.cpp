// WAP to count frequency of an element in an array.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, key, count=0;

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
    
    cout << "Enter element whose frequency is to be counted: ";
    cin >> key;
    
    for(int i=0; i<n; i++)
    {
        if(key==arr[i])
        {
            count++;
        }
    }
    
    cout << "Frequency of " << key << ": " << count;
    return 0;
}