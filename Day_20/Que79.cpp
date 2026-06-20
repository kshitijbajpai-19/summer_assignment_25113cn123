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

    // Check Valid matrix size
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

    // Finding row wise sum and diplaying sum for each row
    for(int i=0; i<rows; i++)
    {
        sum = 0;

        for(int j=0; j<columns; j++)
        {
            sum += matrix[i][j];
        }

        cout << "Sum of row " << i + 1 << " = " << sum << endl;
    }

    return 0;
}