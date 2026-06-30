// WAP to Create an Inventory Management System

#include <iostream>
using namespace std;

struct ITEM
{
    int item_id;
    char name[50];
    int quantity;
    float price;
};

ITEM item[200];
int count = 0;

void menu()
{
    cout << "\nINVENTORY MANAGEMENT SYSTEM\n";
    cout << "1. Add Item\n";
    cout << "2. Display Inventory\n";
    cout << "3. Search Item\n";
    cout << "4. Update Item\n";
    cout << "5. Delete Item\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void save_data()
{
    FILE *fp;

    fp = fopen("inventory.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(item, sizeof(ITEM), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("inventory.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(item, sizeof(ITEM), count, fp);

    fclose(fp);
}

void add_item()
{
    if(count == 200)
    {
        cout << "Inventory Full!";
        return;
    }
    cout << "\nEnter Item ID: ";
    cin >> item[count].item_id;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        if (item[i].item_id == item[count].item_id)
        {
            cout << "Item ID already exists!";
            return;
        }
    }

    cout << "Enter Item Name: ";
    cin.getline(item[count].name, 50);

    cout << "Enter Quantity: ";
    cin >> item[count].quantity;

    cout << "Enter Price: ";
    cin >> item[count].price;

    count++;

    cout << "\nItem Added Successfully!\n";
}

void display_inventory()
{
    if (count == 0)
    {
        cout << "\nInventory is Empty!\n";
        return;
    }

    cout << "\nINVENTORY DETAILS\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nItem " << i + 1 << endl;
        cout << "ID       : " << item[i].item_id << endl;
        cout << "Name     : " << item[i].name << endl;
        cout << "Quantity : " << item[i].quantity << endl;
        cout << "Price    : " << item[i].price << endl;
    }
}

void search_item()
{
    if (count == 0)
    {
        cout << "\nInventory is Empty!\n";
        return;
    }

    int id;
    cout << "\nEnter Item ID to Search: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (item[i].item_id == id)
        {
            cout << "\nItem Found!\n";
            cout << "ID       : " << item[i].item_id << endl;
            cout << "Name     : " << item[i].name << endl;
            cout << "Quantity : " << item[i].quantity << endl;
            cout << "Price    : " << item[i].price << endl;
            return;
        }
    }

    cout << "\nItem Not Found!\n";
}

void update_item()
{
    if (count == 0)
    {
        cout << "\nInventory is Empty!\n";
        return;
    }

    int id;

    cout << "\nEnter Item ID to Update: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (item[i].item_id == id)
        {
            cin.ignore();

            cout << "Enter New Item Name: ";
            cin.getline(item[i].name, 50);

            cout << "Enter New Quantity: ";
            cin >> item[i].quantity;

            cout << "Enter New Price: ";
            cin >> item[i].price;

            cout << "\nItem Updated Successfully!\n";
            return;
        }
    }

    cout << "\nItem Not Found!\n";
}

void delete_item()
{
    if (count == 0)
    {
        cout << "\nInventory is Empty!\n";
        return;
    }

    int id;

    cout << "\nEnter Item ID to Delete: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (item[i].item_id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                item[j] = item[j + 1];
            }

            count--;

            cout << "\nItem Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nItem Not Found!\n";
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
            add_item();
            save_data();
            break;

        case 2:
            display_inventory();
            break;

        case 3:
            search_item();
            break;

        case 4:
            update_item();
            save_data();
            break;

        case 5:
            delete_item();
            save_data();
            break;

        case 6:
            save_data();
            cout << "\nExiting Program\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}