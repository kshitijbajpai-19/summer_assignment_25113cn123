// WAP to Create a Ticket Booking System

#include <cstdio>
#include <iostream>
using namespace std;

struct TICKET
{
    int ticket_id;
    char name[50];
    char destination[50];
    int seats;
    float fare;
    bool booked;
};

TICKET ticket[100];
int count = 0;

void menu()
{
    cout << "\nTICKET BOOKING SYSTEM\n";
    cout << "1. Book Ticket\n";
    cout << "2. Display Active Tickets\n";
    cout << "3. Display Cancelled Tickets\n";
    cout << "4. Search Ticket\n";
    cout << "5. Cancel Ticket\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void save_data()
{
    FILE *fp;

    fp = fopen("ticket.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(ticket, sizeof(TICKET), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("ticket.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(ticket, sizeof(TICKET), count, fp);

    fclose(fp);
}

void book_ticket()
{
    int id;

    cout << "\nEnter Ticket ID: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        if (ticket[i].ticket_id == id)
        {
            if (ticket[i].booked)
            {
                cout << "Ticket ID already exists.\n";
                return;
            }
            else
            {
                // Overwrite cancelled ticket
                ticket[i].ticket_id = id;

                cout << "Enter Passenger Name: ";
                cin.getline(ticket[i].name, 50);

                cout << "Enter Destination: ";
                cin.getline(ticket[i].destination, 50);

                cout << "Enter Number of Seats: ";
                cin >> ticket[i].seats;

                cout << "Enter Fare per Seat: ";
                cin >> ticket[i].fare;

                ticket[i].fare *= ticket[i].seats;
                ticket[i].booked = true;

                cout << "\nCancelled Ticket Rebooked Successfully!\n";
                return;
            }
        }
    }

    if (count == 100)
    {
        cout << "Booking limit reached.\n";
        return;
    }

    // Create new ticket
    ticket[count].ticket_id = id;

    cout << "Enter Passenger Name: ";
    cin.getline(ticket[count].name, 50);

    cout << "Enter Destination: ";
    cin.getline(ticket[count].destination, 50);

    cout << "Enter Number of Seats: ";
    cin >> ticket[count].seats;

    cout << "Enter Fare per Seat: ";
    cin >> ticket[count].fare;

    ticket[count].fare *= ticket[count].seats;
    ticket[count].booked = true;

    count++;

    cout << "\nTicket Booked Successfully!\n";
}

void display_active_tickets()
{
    if (count == 0)
    {
        cout << "\nNo Tickets Available.\n";
        return;
    }

    bool found = false;

    cout << "\nActive Tickets\n";
    for (int i = 0; i < count; i++)
    {
        if (ticket[i].booked)
        {
            found = true;
            cout << "\nTicket ID    : " << ticket[i].ticket_id;
            cout << "\nPassenger    : " << ticket[i].name;
            cout << "\nDestination  : " << ticket[i].destination;
            cout << "\nSeats        : " << ticket[i].seats;
            cout << "\nTotal Fare   : " << ticket[i].fare;
            cout << "\nStatus       : Booked\n\n";
        }
    }

    if (!found)
        cout << "\nNo Active Tickets.\n";
}

void display_cancelled_tickets()
{
    if (count == 0)
    {
        cout << "\nNo Tickets Available.\n";
        return;
    }

    bool found = false;

    cout << "\nCancelled Tickets\n";

    for (int i = 0; i < count; i++)
    {
        if (!ticket[i].booked)
        {
            found = true;

            cout << "\nTicket ID    : " << ticket[i].ticket_id;
            cout << "\nPassenger    : " << ticket[i].name;
            cout << "\nDestination  : " << ticket[i].destination;
            cout << "\nSeats        : " << ticket[i].seats;
            cout << "\nTotal Fare   : " << ticket[i].fare;
            cout << "\nStatus       : Cancelled\n\n";
        }
    }

    if (!found)
        cout << "\nNo Cancelled Tickets.\n";
    else
        cout << "\nNOTE: Cancelled Tickets can be reassigned.\n";
}

void search_ticket()
{
    if (count == 0)
    {
        cout << "\nNo Tickets Available.\n";
        return;
    }

    int id;
    bool found = false;

    cout << "\nEnter Ticket ID to Search: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (ticket[i].ticket_id == id)
        {
            cout << "\nTicket Found\n";
            cout << "Passenger      : " << ticket[i].name << "\n";
            cout << "Destination    : " << ticket[i].destination << "\n";
            cout << "Seats          : " << ticket[i].seats << "\n";
            cout << "Total Fare     : " << ticket[i].fare << "\n";
            cout << "Status         :";
            if (ticket[i].booked)
                cout << "Booked\n\n";
            else
            {
                cout << "Cancelled\n";
                cout << "This ticket ID can be reassigned\n\n";
            }

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nTicket Not Found.\n";
}

void cancel_ticket()
{
    if (count == 0)
    {
        cout << "\nNo Tickets Available.\n";
        return;
    }

    int id;
    bool found = false;

    cout << "\nEnter Ticket ID to Cancel: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (ticket[i].ticket_id == id && ticket[i].booked)
        {
            ticket[i].booked = false;
            cout << "\nTicket Cancelled Successfully!\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nTicket Not Found.\n";
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
            book_ticket();
            save_data();
            break;

        case 2:
            display_active_tickets();
            break;

        case 3:
            display_cancelled_tickets();
            break;

        case 4:
            search_ticket();
            break;

        case 5:
            cancel_ticket();
            save_data();
            break;

        case 6:
            save_data();
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}