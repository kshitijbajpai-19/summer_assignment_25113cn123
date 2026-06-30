// WAP to create a Library Management System

#include <iostream>
using namespace std;

struct BOOK
{
    int book_id;
    char title[50];
    char author[50];
    bool issued;
};

BOOK book[100];
int n = 0;

void menu()
{
    cout << "\nLIBRARY MANAGEMENT SYSTEM\n";
    cout << "1. Add Book\n";
    cout << "2. Display Books\n";
    cout << "3. Search Book\n";
    cout << "4. Issue Book\n";
    cout << "5. Return Book\n";
    cout << "6. Remove Book\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void save_data()
{
    FILE *fp;

    fp = fopen("books.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&n, sizeof(int), 1, fp);
    fwrite(book, sizeof(BOOK), n, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("books.dat", "rb");

    if (fp == NULL)
        return;

    fread(&n, sizeof(int), 1, fp);
    fread(book, sizeof(BOOK), n, fp);

    fclose(fp);
}

void add_book(BOOK book[], int &n)
{
    if (n >= 100)
    {
        cout << "Library is full!\n";
        return;
    }

    int id;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        if (book[i].book_id == id)
        {
            cout << "Book ID already exists.\n";
            return;
        }
    }

    book[n].book_id = id;

    cout << "Enter Book Title: ";
    cin.getline(book[n].title, 50);

    cout << "Enter Author Name: ";
    cin.getline(book[n].author, 50);

    book[n].issued = false;

    n++;

    cout << "Book added successfully.\n";
}

void display_books(BOOK book[], int n)
{
    if (n == 0)
    {
        cout << "No books available.\n";
        return;
    }

    cout << "\nBook List\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nBook " << i + 1 << "\n";
        cout << "Book ID : " << book[i].book_id << "\n";
        cout << "Title   : " << book[i].title << "\n";
        cout << "Author  : " << book[i].author << "\n";

        cout << "Status  : ";

        if (book[i].issued)
            cout << "Issued\n";
        else
            cout << "Available\n";
    }
}

void search_book(BOOK book[], int n)
{
    if (n == 0)
    {
        cout << "No books available.\n";
        return;
    }

    int id;
    bool found = false;

    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (book[i].book_id == id)
        {
            cout << "\nBook Found\n";
            cout << "Book ID : " << book[i].book_id << "\n";
            cout << "Title   : " << book[i].title << "\n";
            cout << "Author  : " << book[i].author << "\n";

            cout << "Status  : ";

            if (book[i].issued)
                cout << "Issued\n";
            else
                cout << "Available\n";

            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

void issue_book(BOOK book[], int n)
{
    if (n == 0)
    {
        cout << "No books available.\n";
        return;
    }

    int id;
    bool found = false;

    cout << "Enter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (book[i].book_id == id)
        {
            found = true;

            if (book[i].issued)
                cout << "Book is already issued.\n";
            else
            {
                book[i].issued = true;
                cout << "Book issued successfully.\n";
            }

            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

void return_book(BOOK book[], int n)
{
    if (n == 0)
    {
        cout << "No books available.\n";
        return;
    }

    int id;
    bool found = false;

    cout << "Enter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (book[i].book_id == id)
        {
            found = true;

            if (!book[i].issued)
                cout << "Book is already available.\n";
            else
            {
                book[i].issued = false;
                cout << "Book returned successfully.\n";
            }

            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

void remove_book(BOOK book[], int &n)
{
    if (n == 0)
    {
        cout << "No books available.\n";
        return;
    }

    int id;
    bool found = false;

    cout << "Enter Book ID to remove: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (book[i].book_id == id)
        {
            found = true;

            if (book[i].issued == true)
            {
                cout << "Cannot remove an issued book.\n";
                break;
            }

            for (int j = i; j < n - 1; j++)
            {
                book[j] = book[j + 1];
            }

            n--;

            cout << "Book removed successfully.\n";
            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";
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
            add_book(book, n);
            save_data();
            break;

        case 2:
            display_books(book, n);
            break;

        case 3:
            search_book(book, n);
            break;

        case 4:
            issue_book(book, n);
            save_data();
            break;

        case 5:
            return_book(book, n);
            save_data();
            break;

        case 6:
            remove_book(book, n);
            save_data();
            break;

        case 7:
            save_data();
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}