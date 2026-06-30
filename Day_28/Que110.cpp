// WAP to Create a Bank Account Management System

#include <cstdio>
#include <iostream>
using namespace std;

struct ACCOUNT
{
    long long acc_no;
    char name[50];
    char type[20];
    float balance;
};

ACCOUNT accounts[200];
int count = 0;

void menu()
{
    cout << "\nBANK ACCOUNT MANAGEMENT SYSTEM\n";
    cout << "1. Add Account\n";
    cout << "2. Display All Accounts\n";
    cout << "3. Search Account\n";
    cout << "4. Deposit Money\n";
    cout << "5. Withdraw Money\n";
    cout << "6. Delete Account\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void save_data()
{
    FILE *fp;

    fp = fopen("accounts.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(accounts, sizeof(ACCOUNT), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("accounts.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(accounts, sizeof(ACCOUNT), count, fp);

    fclose(fp);
}

void add_account()
{
    if (count == 200)
    {
        cout << "Bank database is full!\n";
        return;
    }

    cout << "\nEnter Account Number: ";
    cin >> accounts[count].acc_no;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].acc_no == accounts[count].acc_no)
        {
            cout << "Account Number already exists.\n";
            return;
        }
    }

    cout << "Enter Account Holder Name: ";
    cin.getline(accounts[count].name, 50);

    cout << "Enter Account Type (Saving/Current): ";
    cin.getline(accounts[count].type, 20);

    cout << "Enter Initial Balance: ";
    cin >> accounts[count].balance;

    count++;

    cout << "Account Created Successfully.\n";
}

void display_accounts()
{
    if (count == 0)
    {
        cout << "No accounts found.\n";
        return;
    }

    cout << "\nACCOUNT DETAILS\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nAccount Number : " << accounts[i].acc_no;
        cout << "\nName           : " << accounts[i].name;
        cout << "\nAccount Type   : " << accounts[i].type;
        cout << "\nBalance        : " << accounts[i].balance;
        cout << "\n";
    }
}

void search_account()
{
    if (count == 0)
    {
        cout << "No accounts available.\n";
        return;
    }

    long long number;
    cout << "Enter Account Number to Search: ";
    cin >> number;

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].acc_no == number)
        {
            cout << "\nAccount Found\n";
            cout << "Name         : " << accounts[i].name << endl;
            cout << "Type         : " << accounts[i].type << endl;
            cout << "Balance      : " << accounts[i].balance << endl;
            return;
        }
    }

    cout << "Account not found.\n";
}

void deposit_money()
{
    long long number;
    float amount;

    cout << "Enter Account Number: ";
    cin >> number;

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].acc_no == number)
        {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Invalid amount.\n";
                return;
            }

            accounts[i].balance += amount;

            cout << "Amount Deposited Successfully.\n";
            cout << "Updated Balance: " << accounts[i].balance << endl;
            return;
        }
    }

    cout << "Account not found.\n";
}

void withdraw_money()
{
    long long number;
    float amount;

    cout << "Enter Account Number: ";
    cin >> number;

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].acc_no == number)
        {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Invalid amount.\n";
                return;
            }

            if (amount > accounts[i].balance)
            {
                cout << "Insufficient Balance.\n";
                return;
            }

            accounts[i].balance -= amount;

            cout << "Withdrawal Successful.\n";
            cout << "Remaining Balance: " << accounts[i].balance << endl;
            return;
        }
    }

    cout << "Account not found.\n";
}

void delete_account()
{
    if (count == 0)
    {
        cout << "No accounts available.\n";
        return;
    }

    long long number;
    cout << "Enter Account Number to Delete: ";
    cin >> number;

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].acc_no == number)
        {
            for (int j = i; j < count - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }

            count--;

            cout << "Account Deleted Successfully.\n";
            return;
        }
    }

    cout << "Account not found.\n";
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
            add_account();
            save_data();
            break;

        case 2:
            display_accounts();
            break;

        case 3:
            search_account();
            break;

        case 4:
            deposit_money();
            save_data();
            break;

        case 5:
            withdraw_money();
            save_data();
            break;

        case 6:
            delete_account();
            save_data();
            break;

        case 7:
            save_data();
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}