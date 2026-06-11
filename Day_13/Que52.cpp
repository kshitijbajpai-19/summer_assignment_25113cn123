// WAP to count even and odd elements.

#include<iostream>
using namespace std;


int main()
{
    int arr[100], n, counteven=0, countodd=0;
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
        if(arr[i]%2==0)
            counteven++;
        else
            countodd++;
    }

    cout << "Number of even elements: " << counteven << "\n";
    cout << "Number of odd elements: " << countodd;
    return 0;
}