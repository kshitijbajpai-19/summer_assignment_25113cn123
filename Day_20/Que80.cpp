#include<iostream>
using namespace std;

int main()
{
    int matrix[100][100];
    int rows, columns, sum;

    // Input matrix size
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    // Check valid matrix size
    if(rows <= 0 || columns <= 0 || rows > 100 || columns > 100)
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

    // Find column-wise sum
    for(int j=0; j<columns; j++)
    {
        sum = 0;

        for(int i=0; i<rows; i++)
        {
            sum += matrix[i][j];
        }

        cout << "Sum of column " << j+1 << " = " << sum << endl;
    }

    return 0;
}