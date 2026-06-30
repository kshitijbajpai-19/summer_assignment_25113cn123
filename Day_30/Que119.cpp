// WAP to create a mini Employee Management System

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;

struct EMPLOYEE
{
    // Employee details
    int emp_id;
    char name[50];
    char department[30];
    char designation[30];
    char phone[15];
    // Salary details
    float basic_salary;
    float hra;
    float da;
    float deductions;
    float net_salary;
};

EMPLOYEE employee[100];
int count = 0;

void menu()
{
    cout << "\nEMPLOYEE MANAGEMENT SYSTEM\n";
    cout << "1. Add Employee\n";
    cout << "2. Display All Employees\n";
    cout << "3. Search Employee\n";
    cout << "4. Update Employee\n";
    cout << "5. Calculate Salary\n";
    cout << "6. Display Salary Slip\n";
    cout << "7. Delete Employee\n";
    cout << "8. Employee Statistics\n";
    cout << "9. Exit\n";
}

void save_data()
{
    FILE *fp;

    fp = fopen("employees.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(employee, sizeof(EMPLOYEE), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(employee, sizeof(EMPLOYEE), count, fp);

    fclose(fp);
}

void to_lower(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

int search_by_id(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (employee[i].emp_id == id)
            return i;
    }

    return -1;
}

int search_by_name(char name[])
{
    char search_name[50];
    strcpy(search_name, name);
    to_lower(search_name);

    for (int i = 0; i < count; i++)
    {
        char temp[50];
        strcpy(temp, employee[i].name);
        to_lower(temp);

        if (strcmp(search_name, temp) == 0)
            return i;
    }

    return -1;
}

void add_employee()
{
    if (count == 100)
    {
        cout << "\nEmployee database is full.\n";
        return;
    }

    cout << "\nEnter Employee ID : ";
    cin >> employee[count].emp_id;

    if (search_by_id(employee[count].emp_id) != -1)
    {
        cout << "Employee ID already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Employee Name : ";
    cin.getline(employee[count].name, 50);

    cout << "Enter Department : ";
    cin.getline(employee[count].department, 30);

    cout << "Enter Designation : ";
    cin.getline(employee[count].designation, 30);

    cout << "Enter Phone Number : ";
    cin.getline(employee[count].phone, 15);

    employee[count].basic_salary = 0;
    employee[count].hra = 0;
    employee[count].da = 0;
    employee[count].deductions = 0;
    employee[count].net_salary = 0;

    count++;

    cout << "\nEmployee added successfully.\n";
}

void display_employees()
{
    if (count == 0)
    {
        cout << "\nNo employee records found.\n";
        return;
    }

    cout << left
         << setw(8) << "ID"
         << setw(22) << "Name"
         << setw(18) << "Department"
         << setw(18) << "Designation"
         << setw(15) << "Net Salary"
         << endl;

    for (int i = 0; i < count; i++)
    {
        cout << left
             << setw(8) << employee[i].emp_id
             << setw(22) << employee[i].name
             << setw(18) << employee[i].department
             << setw(18) << employee[i].designation
             << setw(15) << employee[i].net_salary
             << endl;
    }

    cout << "\n";
}

void search_employee()
{
    if (count == 0)
    {
        cout << "\nNo employee records found.\n";
        return;
    }

    int choice, index, id;
    char name[50];

    cout << "\nSearch Employee By\n";
    cout << "1. Employee ID\n";
    cout << "2. Employee Name\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cin.ignore();

    switch (choice)
    {
    case 1:
        cout << "Enter Employee ID: ";
        cin >> id;

        index = search_by_id(id);
        break;

    case 2:
        cout << "Enter Employee Name: ";
        cin.getline(name, 50);

        index = search_by_name(name);
        break;

    default:
        cout << "Invalid choice.\n";
        return;
    }

    if (index == -1)
    {
        cout << "\nEmployee not found.\n";
        return;
    }

    cout << "EMPLOYEE DETAILS\n";
    cout << "\n";

    cout << "Employee ID   : " << employee[index].emp_id << endl;
    cout << "Name          : " << employee[index].name << endl;
    cout << "Department    : " << employee[index].department << endl;
    cout << "Designation   : " << employee[index].designation << endl;
    cout << "Phone Number  : " << employee[index].phone << endl;

    cout << "Basic Salary  : " << employee[index].basic_salary << endl;
    cout << "HRA           : " << employee[index].hra << endl;
    cout << "DA            : " << employee[index].da << endl;
    cout << "Deductions    : " << employee[index].deductions << endl;
    cout << "Net Salary    : " << employee[index].net_salary << endl;
    cout << "\n";
}

void update_employee()
{
    if (count == 0)
    {
        cout << "\nNo employee records found.\n";
        return;
    }

    int id;
    int index;
    int choice;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    index = search_by_id(id);

    if (index == -1)
    {
        cout << "Employee not found.\n";
        return;
    }

    do
    {
        cout << "\nUPDATE MENU\n";
        cout << "1. Name\n";
        cout << "2. Department\n";
        cout << "3. Designation\n";
        cout << "4. Phone Number\n";
        cout << "5. Back\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:

            cout << "Enter New Name: ";
            cin.getline(employee[index].name, 50);
            cout << "Name Updated Successfully.\n";
            break;

        case 2:

            cout << "Enter New Department: ";
            cin.getline(employee[index].department, 30);
            cout << "Department Updated Successfully.\n";
            break;

        case 3:

            cout << "Enter New Designation: ";
            cin.getline(employee[index].designation, 30);
            cout << "Designation Updated Successfully.\n";
            break;

        case 4:

            cout << "Enter New Phone Number: ";
            cin.getline(employee[index].phone, 15);
            cout << "Phone Number Updated Successfully.\n";
            break;

        case 5:

            cout << "Returning to Main Menu\n";
            break;

        default:

            cout << "Invalid Choice.\n";
        }

    } while (choice != 5);
}

void calculate_salary()
{
    if (count == 0)
    {
        cout << "\nNo employee records found.\n";
        return;
    }

    int id;
    int index;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    index = search_by_id(id);

    if (index == -1)
    {
        cout << "Employee not found.\n";
        return;
    }

    cout << "\nEnter Basic Salary : ";
    cin >> employee[index].basic_salary;

    cout << "Enter HRA          : ";
    cin >> employee[index].hra;

    cout << "Enter DA           : ";
    cin >> employee[index].da;

    cout << "Enter Deductions   : ";
    cin >> employee[index].deductions;

    employee[index].net_salary = employee[index].basic_salary + employee[index].hra + employee[index].da - employee[index].deductions;

    cout << "\nSalary calculated successfully.\n";
}

void display_salary_slip()
{
    if (count == 0)
    {
        cout << "\nNo employee records found.\n";
        return;
    }

    int id;
    int index;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    index = search_by_id(id);

    if (index == -1)
    {
        cout << "Employee not found.\n";
        return;
    }

    cout << "\nSALARY SLIP\n";

    cout << "Employee ID   : " << employee[index].emp_id << endl;
    cout << "Name          : " << employee[index].name << endl;
    cout << "Department    : " << employee[index].department << endl;
    cout << "Designation   : " << employee[index].designation << endl;

    cout << "\n";

    cout << "Basic Salary  : " << employee[index].basic_salary << endl;
    cout << "HRA           : " << employee[index].hra << endl;
    cout << "DA            : " << employee[index].da << endl;
    cout << "Deductions    : " << employee[index].deductions << endl;

    cout << "\n";

    cout << "Net Salary    : " << employee[index].net_salary << endl;

    cout << "\n";
}

void delete_employee()
{
    if (count == 0)
    {
        cout << "\nNo employee records found.\n";
        return;
    }

    int id;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    int index = search_by_id(id);

    if (index == -1)
    {
        cout << "Employee not found.\n";
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        employee[i] = employee[i + 1];
    }

    count--;

    cout << "\nEmployee deleted successfully.\n";
}

void employee_statistics()
{
    if (count == 0)
    {
        cout << "\nNo employee records found.\n";
        return;
    }

    float total_salary = 0;
    float highest_salary = employee[0].net_salary;
    float lowest_salary = employee[0].net_salary;

    for (int i = 0; i < count; i++)
    {

        total_salary += employee[i].net_salary;

        if (employee[i].net_salary > highest_salary)
            highest_salary = employee[i].net_salary;

        if (employee[i].net_salary < lowest_salary)
            lowest_salary = employee[i].net_salary;
    }

    cout << "\nEMPLOYEE STATISTICS\n";
    cout << "\n";

    cout << "Total Employees    : " << count << endl;
    cout << "Highest Salary     : " << highest_salary << endl;
    cout << "Lowest Salary      : " << lowest_salary << endl;
    cout << "Average Salary     : " << total_salary / count << endl;

    cout << "\n";
}

int main()
{
    load_data();
    int choice;

    do
    {
        menu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_employee();
            save_data();
            break;

        case 2:
            display_employees();
            break;

        case 3:
            search_employee();
            break;

        case 4:
            update_employee();
            save_data();
            break;

        case 5:
            calculate_salary();
            save_data();
            break;

        case 6:
            display_salary_slip();
            break;

        case 7:
            delete_employee();
            save_data();
            break;

        case 8:
            employee_statistics();
            break;

        case 9:
            save_data();
            cout << "\nThank you for using Employee Management System.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 9);

    return 0;
}