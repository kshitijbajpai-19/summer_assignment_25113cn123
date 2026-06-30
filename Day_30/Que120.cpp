// HOTEL MANAGEMENT SYSTEM

#include <iostream>
#include <cstring>
#include <limits>
#include <cctype>

using namespace std;

const int MAX_ROOMS = 100;

struct ROOM
{
    int room_no;
    char type[20];
    float rent;

    int status; //  0 = Available | 1 = Reserved |  2 = Occupied

    char guest_name[50];
    char phone[15];
    char id_proof[30];

    int days;

    float food_bill;
    float laundry_bill;
    float room_service_bill;
};

ROOM room[MAX_ROOMS];

int count = 0;

float total_revenue = 0;

// Function Prototypes
void menu();
void pause();

int search_room_by_number(int);
void add_room();
void display_rooms();
void update_room();
void delete_room();
void reserve_room();
void cancel_reservation();
void check_in();
void check_out();
void add_food_charges();
void add_laundry_charges();
void add_room_service_charges();
void generate_bill();
void search_menu();
void search_guest_by_name();
void search_phone();
void search_room_type();
void show_available_rooms();
void show_reserved_rooms();
void show_occupied_rooms();
void hotel_statistics();

void save_data()
{
    FILE *fp;

    fp = fopen("hotel.dat", "wb");

    if (fp == NULL)
    {
        cout << "File cannot be created.\n";
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(&total_revenue, sizeof(float), 1, fp);
    fwrite(room, sizeof(ROOM), count, fp);

    fclose(fp);
}

void load_data()
{
    FILE *fp;

    fp = fopen("hotel.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(&total_revenue, sizeof(float), 1, fp);
    fread(room, sizeof(ROOM), count, fp);

    fclose(fp);
}

void to_lower(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower((unsigned char)str[i]);
}

bool equals_ignore_case(const char str1[], const char str2[])
{
    char temp1[100];
    char temp2[100];

    strcpy(temp1, str1);
    strcpy(temp2, str2);

    to_lower(temp1);
    to_lower(temp2);

    return strcmp(temp1, temp2) == 0;
}

void menu()
{
    cout << "HOTEL MANAGEMENT SYSTEM\n";

    cout << "1. Add Room\n";
    cout << "2. Display Rooms\n";
    cout << "3. Update Room\n";
    cout << "4. Delete Room\n";
    cout << "5. Reserve Room\n";
    cout << "6. Cancel Reservation\n";
    cout << "7. Check-In Guest\n";
    cout << "8. Check-Out Guest\n";
    cout << "9. Billing\n";
    cout << "10. Search\n";
    cout << "11. Statistics\n";
    cout << "12. Exit\n";

    cout << "\nEnter Choice : ";
}

//----------------------------------------------------------

void pause()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

//----------------------------------------------------------

int search_room_by_number(int room_no)
{
    for (int i = 0; i < count; i++)
    {
        if (room[i].room_no == room_no)
            return i;
    }

    return -1;
}

//----------------------------------------------------------

void add_room()
{
    if (count == MAX_ROOMS)
    {
        cout << "\nHotel is Full.";
        return;
    }

    cout << "\nEnter Room Number : ";
    cin >> room[count].room_no;

    if (search_room_by_number(room[count].room_no) != -1)
    {
        cout << "\nRoom Number Already Exists.";
        return;
    }

    cin.ignore();

    cout << "Enter Room Type : ";
    cin.getline(room[count].type, 20);

    cout << "Enter Rent Per Day : ";
    cin >> room[count].rent;

    room[count].status = 0;

    strcpy(room[count].guest_name, "");
    strcpy(room[count].phone, "");
    strcpy(room[count].id_proof, "");

    room[count].days = 0;

    room[count].food_bill = 0;
    room[count].laundry_bill = 0;
    room[count].room_service_bill = 0;

    count++;

    cout << "\nRoom Added Successfully.";
}

//----------------------------------------------------------

void display_rooms()
{
    if (count == 0)
    {
        cout << "\nNo Rooms Available.";
        return;
    }

    cout << "\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\nRoom Number : " << room[i].room_no;

        cout << "\nRoom Type   : " << room[i].type;

        cout << "\nRent/Day    : " << room[i].rent;

        cout << "\nStatus      : ";

        if (room[i].status == 0)
            cout << "Available";

        else if (room[i].status == 1)
            cout << "Reserved";

        else
            cout << "Occupied";

        if (room[i].status != 0)
        {
            cout << "\nGuest Name  : " << room[i].guest_name;
            cout << "\nPhone       : " << room[i].phone;
            cout << "\nDays        : " << room[i].days;
        }

        cout << "\n";
    }
}

//----------------------------------------------------------

void update_room()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    cin.ignore();

    cout << "\nCurrent Room Type : " << room[index].type;
    cout << "\nEnter New Room Type : ";
    cin.getline(room[index].type, 20);

    cout << "Current Rent : " << room[index].rent;
    cout << "\nEnter New Rent : ";
    cin >> room[index].rent;

    cout << "\nRoom Updated Successfully.";
}

//----------------------------------------------------------

void delete_room()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 0)
    {
        cout << "\nCannot Delete Reserved or Occupied Room.";
        return;
    }

    for (int i = index; i < count - 1; i++)
        room[i] = room[i + 1];

    count--;

    cout << "\nRoom Deleted Successfully.";
}

//----------------------------------------------------------

void reserve_room()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 0)
    {
        cout << "\nRoom Not Available.";
        return;
    }

    cin.ignore();

    cout << "\nGuest Name : ";
    cin.getline(room[index].guest_name, 50);

    cout << "Phone : ";
    cin.getline(room[index].phone, 15);

    cout << "ID Proof : ";
    cin.getline(room[index].id_proof, 30);

    cout << "Number of Days : ";
    cin >> room[index].days;

    room[index].status = 1;

    cout << "\nRoom Reserved Successfully.";
}

//----------------------------------------------------------

void cancel_reservation()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 1)
    {
        cout << "\nThis Room Is Not Reserved.";
        return;
    }

    room[index].status = 0;

    strcpy(room[index].guest_name, "");
    strcpy(room[index].phone, "");
    strcpy(room[index].id_proof, "");

    room[index].days = 0;

    room[index].food_bill = 0;

    room[index].laundry_bill = 0;

    room[index].room_service_bill = 0;

    cout << "\nReservation Cancelled Successfully.";
}

//----------------------------------------------------------

void check_in()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status == 2)
    {
        cout << "\nRoom Already Occupied.";
        return;
    }

    cin.ignore();

    if (room[index].status == 0)
    {
        cout << "\nGuest Name : ";
        cin.getline(room[index].guest_name, 50);

        cout << "Phone : ";
        cin.getline(room[index].phone, 15);
    }

    cout << "ID Proof : ";
    cin.getline(room[index].id_proof, 30);

    cout << "Number Of Days : ";
    cin >> room[index].days;

    room[index].status = 2;

    cout << "\nGuest Checked-In Successfully.";
}

//----------------------------------------------------------

void check_out()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 2)
    {
        cout << "\nRoom Is Not Occupied.";
        return;
    }

    float room_rent;

    room_rent = room[index].rent * room[index].days;

    float total;

    total = room_rent +
            room[index].food_bill +
            room[index].laundry_bill +
            room[index].room_service_bill;

    total_revenue += total;

    strcpy(room[index].guest_name, "");
    strcpy(room[index].phone, "");
    strcpy(room[index].id_proof, "");

    room[index].days = 0;

    room[index].food_bill = 0;

    room[index].laundry_bill = 0;

    room[index].room_service_bill = 0;

    room[index].status = 0;

    cout << "\nGuest Checked-Out Successfully.";
}

//----------------------------------------------------------

void add_food_charges()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 2)
    {
        cout << "\nRoom Is Not Occupied.";
        return;
    }

    float amount;

    cout << "Enter Food Charges : ";
    cin >> amount;

    room[index].food_bill += amount;

    cout << "\nFood Charges Added Successfully.";
}

//----------------------------------------------------------

void add_laundry_charges()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 2)
    {
        cout << "\nRoom Is Not Occupied.";
        return;
    }

    float amount;

    cout << "Enter Laundry Charges : ";
    cin >> amount;

    room[index].laundry_bill += amount;

    cout << "\nLaundry Charges Added Successfully.";
}

//----------------------------------------------------------

void add_room_service_charges()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 2)
    {
        cout << "\nRoom Is Not Occupied.";
        return;
    }

    float amount;

    cout << "Enter Room Service Charges : ";
    cin >> amount;

    room[index].room_service_bill += amount;

    cout << "\nRoom Service Charges Added Successfully.";
}

//----------------------------------------------------------

void generate_bill()
{
    int room_no, index;

    cout << "\nEnter Room Number : ";
    cin >> room_no;

    index = search_room_by_number(room_no);

    if (index == -1)
    {
        cout << "\nRoom Not Found.";
        return;
    }

    if (room[index].status != 2)
    {
        cout << "\nRoom Is Not Occupied.";
        return;
    }

    float room_rent = room[index].rent * room[index].days;
    float subtotal = room_rent +
                     room[index].food_bill +
                     room[index].laundry_bill +
                     room[index].room_service_bill;

    float gst = subtotal * 0.18f;
    float total = subtotal + gst;

    cout << "\nHOTEL BILL\n";
    cout << "\nGuest Name        : " << room[index].guest_name;
    cout << "\nRoom Number       : " << room[index].room_no;
    cout << "\nRoom Type         : " << room[index].type;
    cout << "\nDays Stayed       : " << room[index].days;

    cout << "\n\nRoom Rent         : " << room_rent;
    cout << "\nFood Charges      : " << room[index].food_bill;
    cout << "\nLaundry Charges   : " << room[index].laundry_bill;
    cout << "\nRoom Service      : " << room[index].room_service_bill;
    cout << "\nGST (18%)         : " << gst;

    cout << "\n\nGrand Total       : " << total;
    cout << "\n";
}

//----------------------------------------------------------

void search_menu()
{
    int choice;

    do
    {
        cout << "\n\nSEARCH MENU \n";

        cout << "1. Search By Guest Name\n";
        cout << "2. Search By Phone\n";
        cout << "3. Search By Room Type\n";
        cout << "4. Available Rooms\n";
        cout << "5. Reserved Rooms\n";
        cout << "6. Occupied Rooms\n";
        cout << "7. Back\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            search_guest_by_name();
            break;

        case 2:
            search_phone();
            break;

        case 3:
            search_room_type();
            break;

        case 4:
            show_available_rooms();
            break;

        case 5:
            show_reserved_rooms();
            break;

        case 6:
            show_occupied_rooms();
            break;

        case 7:
            break;

        default:
            cout << "\nInvalid Choice.";
        }

        if (choice != 7)
            pause();

    } while (choice != 7);
}

//----------------------------------------------------------

void search_guest_by_name()
{
    char name[50];
    bool found = false;

    cin.ignore();

    cout << "\nEnter Guest Name : ";
    cin.getline(name, 50);

    for (int i = 0; i < count; i++)
    {
        if (equals_ignore_case(room[i].guest_name, name))
        {
            cout << "\nRoom Number : " << room[i].room_no;
            cout << "\nRoom Type   : " << room[i].type;
            cout << "\nStatus      : ";

            if (room[i].status == 1)
                cout << "Reserved";
            else if (room[i].status == 2)
                cout << "Occupied";
            else
                cout << "Available";

            found = true;
        }
    }

    if (!found)
        cout << "\nGuest Not Found.";
}

//----------------------------------------------------------

void search_phone()
{
    char phone[15];
    bool found = false;

    cin.ignore();

    cout << "\nEnter Phone Number : ";
    cin.getline(phone, 15);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(room[i].phone, phone) == 0)
        {
            cout << "\nRoom Number : " << room[i].room_no;
            cout << "\nGuest Name  : " << room[i].guest_name;
            cout << "\nRoom Type   : " << room[i].type;

            found = true;
        }
    }

    if (!found)
        cout << "\nRecord Not Found.";
}

//----------------------------------------------------------

void search_room_type()
{
    char type[20];
    bool found = false;

    cin.ignore();

    cout << "\nEnter Room Type : ";
    cin.getline(type, 20);

    for (int i = 0; i < count; i++)
    {
        if (equals_ignore_case(room[i].type, type))
        {
            cout << "\nRoom Number : " << room[i].room_no;
            cout << "\nRent        : " << room[i].rent;

            cout << "\nStatus      : ";

            if (room[i].status == 0)
                cout << "Available";
            else if (room[i].status == 1)
                cout << "Reserved";
            else
                cout << "Occupied";

            cout << "\n";

            found = true;
        }
    }

    if (!found)
        cout << "\nNo Rooms Found.";
}

//----------------------------------------------------------

void show_available_rooms()
{
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (room[i].status == 0)
        {
            cout << "\nRoom Number : " << room[i].room_no;
            cout << "\nType        : " << room[i].type;
            cout << "\nRent        : " << room[i].rent;
            cout << "\n";

            found = true;
        }
    }

    if (!found)
        cout << "\nNo Available Rooms.";
}

//----------------------------------------------------------

void show_reserved_rooms()
{
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (room[i].status == 1)
        {
            cout << "\nRoom Number : " << room[i].room_no;
            cout << "\nGuest       : " << room[i].guest_name;
            cout << "\nPhone       : " << room[i].phone;
            cout << "\n";

            found = true;
        }
    }

    if (!found)
        cout << "\nNo Reserved Rooms.";
}

//----------------------------------------------------------

void show_occupied_rooms()
{
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (room[i].status == 2)
        {
            cout << "\nRoom Number : " << room[i].room_no;
            cout << "\nGuest       : " << room[i].guest_name;
            cout << "\nDays        : " << room[i].days;
            cout << "\n";

            found = true;
        }
    }

    if (!found)
        cout << "\nNo Occupied Rooms.";
}

//----------------------------------------------------------

void hotel_statistics()
{
    int available = 0;
    int reserved = 0;
    int occupied = 0;

    float highest = 0;
    float lowest = 0;
    float total_rent = 0;

    if (count > 0)
    {
        highest = room[0].rent;
        lowest = room[0].rent;
    }

    for (int i = 0; i < count; i++)
    {
        if (room[i].status == 0)
            available++;

        else if (room[i].status == 1)
            reserved++;

        else
            occupied++;

        total_rent += room[i].rent;

        if (room[i].rent > highest)
            highest = room[i].rent;

        if (room[i].rent < lowest)
            lowest = room[i].rent;
    }

    cout << "\nHOTEL STATISTICS\n";
    cout << "\nTotal Rooms       : " << count;
    cout << "\nAvailable Rooms   : " << available;
    cout << "\nReserved Rooms    : " << reserved;
    cout << "\nOccupied Rooms    : " << occupied;

    cout << "\nTotal Revenue     : " << total_revenue;

    if (count > 0)
    {
        cout << "\nAverage Rent      : " << total_rent / count;
        cout << "\nHighest Rent      : " << highest;
        cout << "\nLowest Rent       : " << lowest;
    }
}

//----------------------------------------------------------

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
            add_room();
            save_data();
            break;

        case 2:
            display_rooms();
            break;

        case 3:
            update_room();
            save_data();
            break;

        case 4:
            delete_room();
            save_data();
            break;

        case 5:
            reserve_room();
            save_data();
            break;

        case 6:
            cancel_reservation();
            save_data();
            break;

        case 7:
            check_in();
            save_data();
            break;

        case 8:
            check_out();
            save_data();
            break;

        case 9:
        {
            int bill_choice;

            do
            {
                cout << "\nBILLING\n";

                cout << "1. Generate Bill\n";
                cout << "2. Food Charges\n";
                cout << "3. Laundry Charges\n";
                cout << "4. Room Service Charges\n";
                cout << "5. Back\n";

                cout << "\nEnter Choice : ";
                cin >> bill_choice;

                switch (bill_choice)
                {
                case 1:
                    generate_bill();
                    break;

                case 2:
                    add_food_charges();
                    break;

                case 3:
                    add_laundry_charges();
                    break;

                case 4:
                    add_room_service_charges();
                    break;

                case 5:
                    break;

                default:
                    cout << "\nInvalid Choice.";
                }

                if (bill_choice != 5)
                    pause();

                save_data();

            } while (bill_choice != 5);

            break;
        }

        case 10:
            search_menu();
            break;

        case 11:
            hotel_statistics();
            break;

        case 12:
            save_data();
            cout << "\nThank You For Using Hotel Management System.\n";
            break;

        default:
            cout << "\nInvalid Choice.";
        }

        if (choice != 12)
            pause();

    } while (choice != 12);

    return 0;
}