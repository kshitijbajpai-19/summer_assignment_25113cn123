// WAP to multiply matrices

#include<iostream>
using namespace std;

int main()
{
    int m1[100][100], m2[100][100], m3[100][100], r1, r2, c1, c2;

    // Input dimensions of matrices

    cout << "Enter number of rows of first matrix: ";
    cin >> r1;
    cout << "Enter number of columns of first matrix: ";
    cin >> c1;
    cout << "Enter number of rows of second matrix: ";
    cin >> r2;
    cout << "Enter number of columns of second matrix: ";
    cin >> c2;

    // Checking if multiplication is possible
    if(c1 != r2)
    {
        cout << "Matrix multiplication is not possible";
        return 0;
    }

    // Input elements of matrices
    cout << "Enter elements of first matrix: ";
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            cin >> m1[i][j];
        }
    }
    cout << "Enter elements of second matrix: ";
    for(int i=0; i<r2; i++)
    {
        for(int j=0; j<c2; j++)
        {
            cin >> m2[i][j];
        }
    }

    // Initialize product matrix (m3) to zero to avoid garbage values
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            m3[i][j] = 0;
        }
    } 
    // Multiplying matrices

    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            for(int k=0; k<c1; k++)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    cout << "Product matrix: \n";
    // Display product matrix
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            cout << m3[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}