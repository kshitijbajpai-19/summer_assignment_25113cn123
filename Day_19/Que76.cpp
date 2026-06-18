// WAP to find sum of diagonal elements of a matrix
#include<iostream>
using namespace std;

int main()
{
    int matrix[100][100], n, sum = 0;

    // Enter order of square matrix
    cout << "Enter order of square matrix: ";
    cin >> n;

    if(n<=0 || n>100)
    {
        cout << "Invalid matrix size";
        return 0;
    }

    // Enter matrix elements
    cout << "Enter matrix elements:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Calculate sum of diagonal elements
    for(int i=0; i<n; i++)
    {
        sum+= matrix[i][i];
    }

    // Display diagonal sum
    cout << "Sum of diagonal elements = " << sum;

    return 0;
}