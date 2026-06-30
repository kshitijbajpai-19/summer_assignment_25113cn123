// WAP to Create a Contact Management System

#include <iostream>
#include <cstring>
using namespace std;

struct CONTACT
{
    char name[50];
    char phone[15];
    char email[50];
};

CONTACT contact[100];
int count = 0;

void menu()
{
    cout << "\nCONTACT MANAGEMENT SYSTEM\n";
    cout << "1. Add Contact\n";
    cout << "2. Display Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Update Contact\n";
    cout << "5. Delete Contact\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void save_data()
{
    FILE *fp;

    fp = fopen("contact.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(contact, sizeof(CONTACT), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("contact.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(contact, sizeof(CONTACT), count, fp);

    fclose(fp);
}

void add_contact()
{
    if (count >= 100)
    {
        cout << "Contact list is full.\n";
        return;
    }

    cin.ignore();

    cout << "\n";
    cout << "Enter Name: ";
    cin.getline(contact[count].name, 50);

    cout << "Enter Phone Number: ";
    cin.getline(contact[count].phone, 15);

    // Check for duplicate phone number
    for (int i = 0; i < count; i++)
    {
        if (strcmp(contact[i].phone, contact[count].phone) == 0)
        {
            cout << "Phone number already exists.\n";
            return;
        }
    }

    cout << "Enter Email: ";
    cin.getline(contact[count].email, 50);

    count++;

    cout << "Contact added successfully.\n";
}

void display_contact()
{
    if (count == 0)
    {
        cout << "No contacts available.\n";
        return;
    }

    cout << "\nCONTACT LIST\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nContact " << i + 1 << "\n";
        cout << "Name : " << contact[i].name << "\n";
        cout << "Phone: " << contact[i].phone << "\n";
        cout << "Email: " << contact[i].email << "\n";
    }
}

void search_contact()
{
    int choice;
    char name[50];
    char phone[15];
    bool found = false;

    cout << "\nSearch Contact By\n";
    cout << "1. Name\n";
    cout << "2. Phone Number\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        cout << "Enter Name: ";
        cin.getline(name, 50);

        for (int i = 0; i < count; i++)
        {
            if (strcmp(contact[i].name, name) == 0)
            {
                cout << "\nContact Found\n";
                cout << "Name : " << contact[i].name << "\n";
                cout << "Phone: " << contact[i].phone << "\n";
                cout << "Email: " << contact[i].email << "\n";
                found = true;
            }
        }
    }
    else if (choice == 2)
    {
        cout << "Enter Phone Number: ";
        cin.getline(phone, 15);

        for (int i = 0; i < count; i++)
        {
            if (strcmp(contact[i].phone, phone) == 0)
            {
                cout << "\nContact Found\n";
                cout << "Name : " << contact[i].name << "\n";
                cout << "Phone: " << contact[i].phone << "\n";
                cout << "Email: " << contact[i].email << "\n";
                found = true;
            }
        }
    }
    else
    {
        cout << "Invalid choice.\n";
        return;
    }

    if (!found)
    {
        cout << "Contact not found.\n";
    }
}

void update_contact()
{
    char phone[15];

    cin.ignore();

    cout << "\nEnter Phone Number to update: ";
    cin.getline(phone, 15);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(contact[i].phone, phone) == 0)
        {
            cout << "Enter New Name: ";
            cin.getline(contact[i].name, 50);

            cout << "Enter New Email: ";
            cin.getline(contact[i].email, 50);

            cout << "Contact updated successfully.\n";
            return;
        }
    }

    cout << "Contact not found.\n";
}

void delete_contact()
{
    char phone[15];

    cin.ignore();

    cout << "Enter Phone Number to delete: ";
    cin.getline(phone, 15);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(contact[i].phone, phone) == 0)
        {
            for (int j = i; j < count - 1; j++)
            {
                contact[j] = contact[j + 1];
            }

            count--;

            cout << "Contact deleted successfully.\n";
            return;
        }
    }

    cout << "Contact not found.\n";
}

int main()
{
    load_data();
    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                add_contact();
                save_data();
                break;

            case 2:
                display_contact();
                break;

            case 3:
                search_contact();
                break;

            case 4:
                update_contact();
                save_data();
                break;

            case 5:
                delete_contact();
                save_data();
                break;

            case 6:
                save_data();
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}