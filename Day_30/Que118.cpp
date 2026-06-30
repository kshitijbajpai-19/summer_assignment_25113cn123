// WAP to Create a Mini Library System

#include <iostream>
#include <cstring>
using namespace std;

struct BOOK
{
    int book_id;
    char title[50];
    char author[50];
    bool issued;
    char borrower_name[50];
    char admission_no[20];
    char branch[30];
};

BOOK book[100];
int count = 0;

void menu()
{
    cout << "\nMINI LIBRARY SYSTEM\n";
    cout << "1. Add Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Search Book\n";
    cout << "4. Issue Book\n";
    cout << "5. Return Book\n";
    cout << "6. Display Available Books\n";
    cout << "7. Display Issued Books\n";
    cout << "8. Exit\n";
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

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(book, sizeof(BOOK), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("books.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(book, sizeof(BOOK), count, fp);

    fclose(fp);
}


void add_book()
{
    if (count == 100)
    {
        cout << "Library is full.\n";
        return;
    }

    cout << "\nEnter Book ID: ";
    cin >> book[count].book_id;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        if (book[i].book_id == book[count].book_id)
        {
            cout << "\nBook ID already exists!\n";
            return;
        }
    }

    cout << "Enter Book Title: ";
    cin.getline(book[count].title, 50);

    cout << "Enter Author Name: ";
    cin.getline(book[count].author, 50);

    book[count].issued = false;

    strcpy(book[count].borrower_name, "");
    strcpy(book[count].admission_no, "");
    strcpy(book[count].branch, "");

    count++;

    cout << "\nBook added successfully.\n";
}

void display_book()
{
    if (count == 0)
    {
        cout << "\nNo books found.\n";
        return;
    }

    cout << "\nBOOK LIST\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nBook ID : " << book[i].book_id;
        cout << "\nTitle : " << book[i].title;
        cout << "\nAuthor : " << book[i].author;

        if (book[i].issued)
        {
            cout << "\nStatus : Issued";
            cout << "\nBorrower : " << book[i].borrower_name;
            cout << "\nAdmission No : " << book[i].admission_no;
            cout << "\nBranch : " << book[i].branch;
        }
        else
        {
            cout << "\nStatus : Available\n";
        }
    }
}

void search_book()
{
    int choice;
    bool found = false;

    cout << "\nSEARCH MENU\n";
    cout << "1. Search by Book ID\n";
    cout << "2. Search by Book Title\n";
    cout << "3. Search by Author\n";
    cout << "4. Search by Borrower Name\n";
    cout << "5. Search by Admission Number\n";
    cout << "6. Back\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cin.ignore();

    switch (choice)
    {
    case 1:
    {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (book[i].book_id == id)
            {
                found = true;

                cout << "\nBook ID : " << book[i].book_id;
                cout << "\nTitle : " << book[i].title;
                cout << "\nAuthor : " << book[i].author;
                cout << "\nStatus : " << (book[i].issued ? "Issued" : "Available");

                if (book[i].issued)
                {
                    cout << "\nBorrower : " << book[i].borrower_name;
                    cout << "\nAdmission No : " << book[i].admission_no;
                    cout << "\nBranch : " << book[i].branch;
                }
                break;
            }
            
        }
        break;
    }

    case 2:
    {
        char title[50];

        cout << "Enter Book Title: ";
        cin.getline(title, 50);

        for (int i = 0; i < count; i++)
        {
            if (strcmp(book[i].title, title) == 0)
            {
                found = true;

                cout << "\nBook ID : " << book[i].book_id;
                cout << "\nTitle : " << book[i].title;
                cout << "\nAuthor : " << book[i].author;
                cout << "\nStatus : " << (book[i].issued ? "Issued" : "Available") << "\n";
            }
        }
        break;
    }

    case 3:
    {
        char author[50];

        cout << "Enter Author Name: ";
        cin.getline(author, 50);

        for (int i = 0; i < count; i++)
        {
            if (strcmp(book[i].author, author) == 0)
            {
                found = true;

                cout << "\nBook ID : " << book[i].book_id;
                cout << "\nTitle : " << book[i].title;
                cout << "\nAuthor : " << book[i].author;
                cout << "\nStatus : " << (book[i].issued ? "Issued" : "Available") << "\n";
            }
        }
        break;
    }

    case 4:
    {
        char borrower[50];

        cout << "Enter Borrower Name: ";
        cin.getline(borrower, 50);

        for (int i = 0; i < count; i++)
        {
            if (strcmp(book[i].borrower_name, borrower) == 0)
            {
                found = true;

                cout << "\nBook ID : " << book[i].book_id;
                cout << "\nTitle : " << book[i].title;
                cout << "\nBorrower : " << book[i].borrower_name;
                cout << "\nAdmission No : " << book[i].admission_no;
                cout << "\nBranch : " << book[i].branch << "\n";
            }
        }
        break;
    }

    case 5:
    {
        char admission[20];

        cout << "Enter Admission Number: ";
        cin.getline(admission, 20);

        for (int i = 0; i < count; i++)
        {
            if (strcmp(book[i].admission_no, admission) == 0)
            {
                found = true;

                cout << "\nBook ID : " << book[i].book_id;
                cout << "\nTitle : " << book[i].title;
                cout << "\nBorrower : " << book[i].borrower_name;
                cout << "\nBranch : " << book[i].branch << "\n";
            }
        }
        break;
    }

    case 6:
    {
        return;
    }

    default:
        cout << "\nInvalid Choice.\n";
        return;
    }

    if (!found)
        cout << "\nNo matching record found.\n";
}

void issue_book()
{
    int id;
    bool found = false;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        if (book[i].book_id == id)
        {
            found = true;

            if (book[i].issued)
            {
                cout << "\nBook is already issued.\n";
                return;
            }

            cout << "Enter Borrower Name: ";
            cin.getline(book[i].borrower_name, 50);

            cout << "Enter Admission Number: ";
            cin.getline(book[i].admission_no, 20);

            cout << "Enter Branch: ";
            cin.getline(book[i].branch, 30);

            book[i].issued = true;

            cout << "\nBook issued successfully.\n";
            return;
        }
    }

    if (!found)
        cout << "\nBook not found.\n";
}

void return_book()
{
    int id;
    bool found = false;

    cout << "\nEnter Book ID: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (book[i].book_id == id)
        {
            found = true;

            if (!book[i].issued)
            {
                cout << "\nBook is already available.\n";
                return;
            }

            book[i].issued = false;

            strcpy(book[i].borrower_name, "");
            strcpy(book[i].admission_no, "");
            strcpy(book[i].branch, "");

            cout << "\nBook returned successfully.\n";
            return;
        }
    }

    if (!found)
        cout << "\nBook not found.\n";
}

void display_available_books()
{
    bool found = false;

    cout << "\nAVAILABLE BOOKS\n";

    for (int i = 0; i < count; i++)
    {
        if (!book[i].issued)
        {
            found = true;

            cout << "\nBook ID : " << book[i].book_id;
            cout << "\nTitle : " << book[i].title;
            cout << "\nAuthor : " << book[i].author;
            cout << "\n";
        }
    }

    if (!found)
        cout << "\nNo available books.\n";
}

void display_issued_books()
{
    bool found = false;

    cout << "\nISSUED BOOKS\n";

    for (int i = 0; i < count; i++)
    {
        if (book[i].issued)
        {
            found = true;

            cout << "\nBook ID : " << book[i].book_id;
            cout << "\nTitle : " << book[i].title;
            cout << "\nAuthor : " << book[i].author;
            cout << "\nBorrower : " << book[i].borrower_name;
            cout << "\nAdmission No : " << book[i].admission_no;
            cout << "\nBranch : " << book[i].branch;
            cout << "\n";
        }
    }

    if (!found)
        cout << "\nNo books are currently issued.\n";
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
            add_book();
            save_data();
            break;

        case 2:
            display_book();
            break;

        case 3:
            search_book();
            break;

        case 4:
            issue_book();
            save_data();
            break;

        case 5:
            return_book();
            save_data();
            break;

        case 6:
            display_available_books();
            break;

        case 7:
            display_issued_books();
            break;

        case 8:
            save_data();
            cout << "\nThank you for using Mini Library System.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 8);

    return 0;
}