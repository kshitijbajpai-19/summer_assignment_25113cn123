// WAP to find pair with given sum.

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, sum, flag=0;
    
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

    cout << "Enter sum to find pair: ";
    cin >> sum;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                cout << "Pair found: " << arr[i] << " and " << arr[j] <<"\n";
                flag = 1;
            }
        }
    }
    if(flag == 0)
        cout << "No pair found";
    return 0;
}