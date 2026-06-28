// WAP to create a Salary Management System

#include <iostream>
using namespace std;

struct Employee
{
    int emp_id;
    char name[50];
    char department[50];
    char designation[50];

    float basicSalary;
    float hraPercent;
    float daPercent;
    float pfPercent;
    float taxPercent;
    float bonus;
};

Employee emp[100];
int count = 0;

void menu()
{
    cout << "\nSALARY MANAGEMENT SYSTEM\n";
    cout << "1. Add Employee\n";
    cout << "2. Display Employees\n";
    cout << "3. Search Employee\n";
    cout << "4. Update Employee\n";
    cout << "5. Delete Employee\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void calculateSalary(Employee e)
{
    float hra = e.basicSalary * e.hraPercent / 100;
    float da = e.basicSalary * e.daPercent / 100;
    float pf = e.basicSalary * e.pfPercent / 100;

    float grossSalary = e.basicSalary + hra + da + e.bonus;
    float tax = grossSalary * e.taxPercent / 100;

    float netSalary = grossSalary - pf - tax;

    cout << "\nBasic Salary : " << e.basicSalary;
    cout << "\nHRA          : " << hra;
    cout << "\nDA           : " << da;
    cout << "\nBonus        : " << e.bonus;
    cout << "\nGross Salary : " << grossSalary;
    cout << "\nPF           : " << pf;
    cout << "\nTax          : " << tax;
    cout << "\nNet Salary   : " << netSalary << "\n";
}

void addEmployee()
{
    if (count >= 100)
    {
        cout << "Storage Full!\n";
        return;
    }

    cout << "\nEnter Employee ID: ";
    cin >> emp[count].emp_id;

    for (int i = 0; i < count; i++)
    {
        if (emp[i].emp_id == emp[count].emp_id)
        {
            cout << "Employee ID already exists.";
            return;
        }
    }
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(emp[count].name, 50);

    cout << "Enter Department: ";
    cin.getline(emp[count].department, 50);

    cout << "Enter Designation: ";
    cin.getline(emp[count].designation, 50);

    cout << "Enter Basic Salary: ";
    cin >> emp[count].basicSalary;

    cout << "Enter HRA (%): ";
    cin >> emp[count].hraPercent;

    cout << "Enter DA (%): ";
    cin >> emp[count].daPercent;

    cout << "Enter PF (%): ";
    cin >> emp[count].pfPercent;

    cout << "Enter Tax (%): ";
    cin >> emp[count].taxPercent;

    cout << "Enter Bonus: ";
    cin >> emp[count].bonus;

    count++;

    cout << "\nEmployee Added Successfully.\n";
}

void displayEmployees()
{
    if (count == 0)
    {
        cout << "\nNo Records Found.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "\n\n";
        cout << "Employee ID : " << emp[i].emp_id << "\n";
        cout << "Name        : " << emp[i].name << "\n";
        cout << "Department  : " << emp[i].department << "\n";
        cout << "Designation : " << emp[i].designation << "\n";

        calculateSalary(emp[i]);
    }
}

void searchEmployee()
{
    int id;
    cout << "\nEnter Employee ID to Search: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (emp[i].emp_id == id)
        {
            cout << "\nEmployee Found\n";
            cout << "Employee ID : " << emp[i].emp_id << "\n";
            cout << "Name        : " << emp[i].name << "\n";
            cout << "Department  : " << emp[i].department << "\n";
            cout << "Designation : " << emp[i].designation << "\n";

            calculateSalary(emp[i]);
            return;
        }
    }

    cout << "Employee Not Found.\n";
}

void updateEmployee()
{
    int id;

    cout << "\nEnter Employee ID to Update: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (emp[i].emp_id == id)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            cin.getline(emp[i].name, 50);

            cout << "Enter Department: ";
            cin.getline(emp[i].department, 50);

            cout << "Enter Designation: ";
            cin.getline(emp[i].designation, 50);

            cout << "Enter Basic Salary: ";
            cin >> emp[i].basicSalary;

            cout << "Enter HRA (%): ";
            cin >> emp[i].hraPercent;

            cout << "Enter DA (%): ";
            cin >> emp[i].daPercent;

            cout << "Enter PF (%): ";
            cin >> emp[i].pfPercent;

            cout << "Enter Tax (%): ";
            cin >> emp[i].taxPercent;

            cout << "Enter Bonus: ";
            cin >> emp[i].bonus;

            cout << "\nRecord Updated Successfully.\n";
            return;
        }
    }

    cout << "Employee Not Found.\n";
}

void deleteEmployee()
{
    int id;

    cout << "\nEnter Employee ID to Delete: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (emp[i].emp_id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                emp[j] = emp[j + 1];
            }

            count--;

            cout << "Record Deleted Successfully.\n";
            return;
        }
    }

    cout << "Employee Not Found.\n";
}

int main()
{
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;

        case 2:
            displayEmployees();
            break;

        case 3:
            searchEmployee();
            break;

        case 4:
            updateEmployee();
            break;

        case 5:
            deleteEmployee();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}