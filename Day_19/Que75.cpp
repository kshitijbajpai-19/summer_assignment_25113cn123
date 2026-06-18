// WAP to find transpose of a matrix

#include<iostream>
using namespace std;

int main()
{
    int matrix[100][100], transpose[100][100];
    int rows, columns;

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

    // Input matrix elements
    cout << "Enter matrix elements:\n";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Find transpose of matrix
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Display transpose matrix
    cout << "Transpose Matrix:\n";
    for(int i=0; i<columns; i++)
    {
        for(int j=0; j<rows; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}