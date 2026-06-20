// WAP to check symmetric matrix 

#include<iostream>
using namespace std;

int main()
{
    int matrix[100][100];
    int rows, columns;

    // Enter number of rows and columns
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    // Check valid matirx size
    if(rows<=0 || columns<=0 || rows>100 || columns>100)
    {
        cout << "Invalid matrix size";
        return 0;
    }
    // Check if it is a square matrix or not
    if(rows != columns)
    {
    cout << "Matrix is not symmetric";
    return 0;
    }

    // Input matrix elements
    cout << "Enter matrix elements:\n";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Check if matrix is symmetric or not
    for(int i=0; i<rows; i++)
    {
        for(int j=i+1; j<columns; j++) // Checks only the upper triangle
        {
            if(matrix[j][i] != matrix[i][j])
            {
                cout << "Matrix is not symmetric";
                return 0;
            }
        }
    }

    cout << "Matrix is symmetric";

    return 0;
}