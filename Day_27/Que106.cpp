// WAP to create a Employee management system

#include <iostream>
using namespace std;

struct EMPLOYEE
{
    int emp_id;
    char name[50];
    int age;
    char department[50];
    char designation[50];
    float salary;
};

void menu()
{
    cout << "\nEMPLOYEE MANAGEMENT SYSTEM\n";
    cout << "1. Add employee\n";
    cout << "2. Display employees\n";
    cout << "3. Search employee\n";
    cout << "4. Update employee\n";
    cout << "5. Delete employee\n";
    cout << "6. Exit\n";
    cout << "Enter Choice: ";
}

int find_employee(EMPLOYEE employees[], int count, int emp_id)
{
    for (int i = 0; i < count; i++)
    {
        if (employees[i].emp_id == emp_id)
        {
            return i;
        }
    }
    return -1;
}

void add_employee(EMPLOYEE employees[], int &count)
{
    if (count == 200)
    {
        cout << "Database is full\n";
        return;
    }

    cout << "\nEnter Employee details\n";

    cout << "Employee ID: ";
    cin >> employees[count].emp_id;
    cin.ignore();

    if (find_employee(employees, count, employees[count].emp_id) != -1)
    {
        cout << "Employee ID already exists.\n";
        return;
    }

    cout << "Name: ";
    cin.getline(employees[count].name, 50);

    cout << "Age: ";
    cin >> employees[count].age;
    cin.ignore();

    cout << "Department: ";
    cin.getline(employees[count].department, 50);

    cout << "Designation: ";
    cin.getline(employees[count].designation, 50);

    cout << "Salary: ";
    cin >> employees[count].salary;

    count++;

    cout << "\nEmployee Added Successfully.\n";
}

void display_employee(EMPLOYEE employees[], int count)
{
    if (count == 0)
    {
        cout << "\nNo employee records found\n";
        return;
    }

    cout << "Employee records:\n";
    cout << "Employee ID \tName\t\tAge\t\tDepartment\t\tDesignation\t\tSalary\t\t\n";
    for (int i = 0; i < count; i++)
    {
        cout << employees[i].emp_id << "\t\t" << employees[i].name << "\t\t" << employees[i].age
             << "\t\t" << employees[i].department << "\t\t\t" << employees[i].designation << "\t\t\t"
             << employees[i].salary << "\n";
    }
}

void search_employee(EMPLOYEE employees[], int count)
{
    int emp_id;

    cout << "Enter Employee ID: ";
    cin >> emp_id;

    int index = find_employee(employees, count, emp_id);

    if (index == -1)
    {
        cout << "\nEmployee not found\n";
        return;
    }

    cout << "\nEmployee found\n";
    cout << "Employee ID : " << employees[index].emp_id << "\n";
    cout << "Name        : " << employees[index].name << "\n";
    cout << "Age         : " << employees[index].age << "\n";
    cout << "Department  : " << employees[index].department << "\n";
    cout << "Designation : " << employees[index].designation << " \n";
    cout << "Salary      : " << employees[index].salary << "\n";
}

void update_employee(EMPLOYEE employees[], int count)
{
    int emp_id;

    cout << "\nEnter Employee ID to Update: ";
    cin >> emp_id;

    int index = find_employee(employees, count, emp_id);

    if (index == -1)
    {
        cout << "\nEmployee not found\n";
        return;
    }

    cin.ignore();

    cout << "\nEnter New Details\n";

    cout << "Name: ";
    cin.getline(employees[index].name, 50);

    cout << "Age: ";
    cin >> employees[index].age;
    cin.ignore();

    cout << "Department: ";
    cin.getline(employees[index].department, 50);

    cout << "Designation: ";
    cin.getline(employees[index].designation, 50);

    cout << "Salary: ";
    cin >> employees[index].salary;

    cout << "\nRecord Updated Successfully.\n";
}

void delete_employee(EMPLOYEE employees[], int &count)
{
    int emp_id;

    cout << "\nEnter Employee ID to Delete: ";
    cin >> emp_id;

    int index = find_employee(employees, count, emp_id);

    if (index == -1)
    {
        cout << "\nEmployee not found\n";
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        employees[i] = employees[i + 1];
    }

    count--;

    cout << "\nEmployee Deleted Successfully.\n";
}

int main()
{
    EMPLOYEE employees[200];
    int count = 0;
    int choice;

    cout << "EMPLOYEE MANAGEMENT SYSTEM\n";

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_employee(employees, count);
            break;

        case 2:
            display_employee(employees, count);
            break;

        case 3:
            search_employee(employees, count);
            break;

        case 4:
            update_employee(employees, count);
            break;

        case 5:
            delete_employee(employees, count);
            break;

        case 6:
            cout << "\nThank you for using our system\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}