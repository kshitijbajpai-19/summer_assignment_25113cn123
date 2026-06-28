// WAP to create a student record management system

#include <iostream>
using namespace std;

struct STUDENT
{
    int roll;
    char name[50];
    int age;
    float marks;
};

void menu()
{
    cout << "\nSTUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "Enter Choice: ";
}

int find_student(STUDENT students[], int count, int roll)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            return i;
        }
    }
    return -1;
}

void add_student(STUDENT students[], int &count)
{
    if (count == 200)
    {
        cout << "Database is full\n";
        return;
    }

    cout << "\nEnter Student details\n";

    cout << "Roll Number: ";
    cin >> students[count].roll;
    cin.ignore();

    if (find_student(students, count, students[count].roll) != -1)
    {
        cout << "Roll Number already exists.\n";
        return;
    }

    cout << "Name: ";
    cin.getline(students[count].name, 50);

    cout << "Age: ";
    cin >> students[count].age;

    cout << "Marks: ";
    cin >> students[count].marks;

    count++;

    cout << "\nStudent added successfully\n";
}

void display_student(STUDENT students[], int count)
{
    if (count == 0)
    {
        cout << "\nNo Student records found\n";
        return;
    }

    cout << "Student records:\n";
    cout << "Roll no. \tName\t\tAge\t\tMarks\t\t\n";
    for (int i = 0; i < count; i++)
    {
        cout << students[i].roll << "\t\t" << students[i].name << "\t\t" << students[i].age << "\t\t" << students[i].marks << "\n";
    }
}


void search_student(STUDENT students[], int count)
{
    int roll;

    cout << "Enter Student roll number: ";
    cin >> roll;

    int index = find_student(students, count, roll);

    if (index == -1)
    {
        cout << "\nStudent not found\n";
        return;
    }

    cout << "\nStudent Found\n";
    cout << "Roll Number : " << students[index].roll << "\n";
    cout << "Name        : " << students[index].name << "\n";
    cout << "Age         : " << students[index].age << "\n";
    cout << "Marks       : " << students[index].marks << "\n";
}

void update_student(STUDENT students[], int count)
{
    int roll;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    int index = find_student(students, count, roll);

    if (index == -1)
    {
        cout << "\nStudent Not Found.\n";
        return;
    }

    cin.ignore();

    cout << "\nEnter New Details\n";

    cout << "Name: ";
    cin.getline(students[index].name, 50);

    cout << "Age: ";
    cin >> students[index].age;

    cout << "Marks: ";
    cin >> students[index].marks;

    cout << "\nRecord Updated Successfully.\n";
}

void delete_student(STUDENT students[], int &count)
{
    int roll;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    int index = find_student(students, count, roll);

    if (index == -1)
    {
        cout << "\nStudent Not Found.\n";
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    count--;

    cout << "\nStudent Deleted Successfully.\n";
}

int main()
{
    STUDENT students[200];
    int count = 0;
    int choice;

    cout << "STUDENT MANAGEMENT SYSTEM\n";

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_student(students, count);
            break;

        case 2:
            display_student(students, count);
            break;

        case 3:
            search_student(students, count);
            break;

        case 4:
            update_student(students, count);
            break;

        case 5:
            delete_student(students, count);
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