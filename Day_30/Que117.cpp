// WAP to create a student record system using arrays and strings.

#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 200;

int count = 0;
int adm_no[MAX];
char name[MAX][50];
int age[MAX];
float marks[MAX];

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

void save_data()
{
    FILE *fp;

    fp = fopen("students.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(adm_no, sizeof(int), count, fp);
    fwrite(name, sizeof(name[0]), count, fp);
    fwrite(age, sizeof(int), count, fp);
    fwrite(marks, sizeof(float), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        return;
    }

    fread(&count, sizeof(int), 1, fp);
    fread(adm_no, sizeof(int), count, fp);
    fread(name, sizeof(name[0]), count, fp);
    fread(age, sizeof(int), count, fp);
    fread(marks, sizeof(float), count, fp);

    fclose(fp);
}

int find_student(int adm)
{
    for (int i = 0; i < count; i++)
    {
        if (adm_no[i] == adm)
        {
            return i;
        }
    }
    return -1;
}

void add_student()
{
    if (count == MAX)
    {
        cout << "Database is full\n";
        return;
    }

    cout << "Enter Student details\n";

    cout << "Admission Number: ";
    cin >> adm_no[count];
    cin.ignore();

    if (find_student(adm_no[count]) != -1)
    {
        cout << "Admission number already exists!\n";
        return;
    }

    cout << "Name: ";
    cin.getline(name[count], 50);

    cout << "Age: ";
    cin >> age[count];

    cout << "Marks: ";
    cin >> marks[count];

    count++;

    cout << "\nStudent added successfully\n";
}

void display_student()
{
    if (count == 0)
    {
        cout << "\nNo Student records found\n";
        return;
    }

    cout << "\nSTUDENT RECORDS\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nAdmission Number : " << adm_no[i];
        cout << "\nName             : " << name[i];
        cout << "\nAge              : " << age[i];
        cout << "\nMarks            : " << marks[i];
        cout << "\n";
    }
}

void search_student()
{
    int adm;

    cout << "Enter Student Admission number: ";
    cin >> adm;

    int index = find_student(adm);

    if (index == -1)
    {
        cout << "\nStudent not found\n";
        return;
    }

    cout << "\nStudent Found\n";
    cout << "Admission Number : " << adm_no[index] << "\n";
    cout << "Name             : " << name[index] << "\n";
    cout << "Age              : " << age[index] << "\n";
    cout << "Marks            : " << marks[index] << "\n";
}

void update_student()
{
    int adm;

    cout << "\nEnter Admission Number to Update: ";
    cin >> adm;

    int index = find_student(adm);

    if (index == -1)
    {
        cout << "\nStudent Not Found.\n";
        return;
    }

    cin.ignore();

    cout << "\nEnter New Details\n";

    cout << "Name: ";
    cin.getline(name[index], 50);

    cout << "Age: ";
    cin >> age[index];

    cout << "Marks: ";
    cin >> marks[index];

    cout << "\nRecord Updated Successfully.\n";
}

void delete_student()
{
    int adm;

    cout << "\nEnter Admission number to Delete: ";
    cin >> adm;

    int index = find_student(adm);

    if (index == -1)
    {
        cout << "\nStudent Not Found.\n";
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        adm_no[i] = adm_no[i + 1];
        strcpy(name[i], name[i + 1]);
        age[i] = age[i + 1];
        marks[i] = marks[i + 1];
    }

    count--;

    cout << "\nStudent Deleted Successfully.\n";
}

int main()
{   
    load_data();

    int choice;

    cout << "STUDENT MANAGEMENT SYSTEM\n";

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_student();
            save_data();
            break;

        case 2:
            display_student();
            break;

        case 3:
            search_student();
            break;

        case 4:
            update_student();
            save_data();
            break;

        case 5:
            delete_student();
            save_data();
            break;

        case 6:
            save_data();
            cout << "\nThank you for using our system\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}