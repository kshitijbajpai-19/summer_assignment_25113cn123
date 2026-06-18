// WAP to add matrices

#include<iostream>
using namespace std;

int main()
{
    int m1[100][100], m2[100][100], sum[100][100], rows, columns;

    // Enter number of rows and columns
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    if(rows <= 0 || columns <= 0 || rows > 100 || columns > 100)
    {
        cout << "Invalid matrix size";
        return 0;
    }

    // Enter elements of first and second matrix
    cout << "Enter elements of first matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cin >> m1[i][j];
        }
    }
    cout << "Enter elements of second matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cin >> m2[i][j];
        }
    }

    // Adding the two matrices
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    // Display resultant matrix after addition
    cout << "Resultant Matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

