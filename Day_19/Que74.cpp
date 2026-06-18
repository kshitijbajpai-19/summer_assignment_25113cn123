// WAP to subtract matrices

#include<iostream>
using namespace std;

int main()
{
    int m1[100][100], m2[100][100], diff[100][100], rows, columns;

    // Enter number of rows and columns
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    if(rows<=0 || columns<=0 || rows>100 || columns>100)
    {
        cout << "Invalid matrix size";
        return 0;
    }

    // Enter elements of first and second matrix
    cout << "Enter elements of first matrix:\n";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cin >> m1[i][j];
        }
    }
    cout << "Enter elements of second matrix:\n";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cin >> m2[i][j];
        }
    }

    // Subtracting the two matrices
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            diff[i][j] = m1[i][j] - m2[i][j];
        }
    }

    // Display resultant matrix after subtraction
    cout << "Resultant Matrix:\n";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cout << diff[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

