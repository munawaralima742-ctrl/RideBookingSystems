#include <iostream>
#include <string>

using namespace std;

// ================= USER =================

struct User
{
    int id;
    string name;
    string phone;
};

// ================= DRIVER =================

struct Driver
{
    int id;
    string name;
    string vehicle;
    bool available;
};

// ================= GLOBAL ARRAYS =================

User users[100];
int totalUsers = 0;

Driver drivers[100];
int totalDrivers = 0;

// ================= REGISTER USER =================

void registerUser()
{
    User u;

    cout << "\nEnter User ID: ";
    cin >> u.id;

    cin.ignore();

    cout << "Enter User Name: ";
    getline(cin, u.name);

    cout << "Enter Phone Number: ";
    getline(cin, u.phone);

    users[totalUsers] = u;
    totalUsers++;

    cout << "\nUser Registered Successfully!\n";
}

// ================= REGISTER DRIVER =================

void registerDriver()
{
    Driver d;

    cout << "\nEnter Driver ID: ";
    cin >> d.id;

    cin.ignore();

    cout << "Enter Driver Name: ";
    getline(cin, d.name);

    cout << "Enter Vehicle Name: ";
    getline(cin, d.vehicle);

    d.available = true;

    drivers[totalDrivers] = d;
    totalDrivers++;

    cout << "\nDriver Registered Successfully!\n";
}

// ================= VIEW USERS =================

void viewUsers()
{
    if(totalUsers == 0)
    {
        cout << "\nNo Users Registered!\n";
        return;
    }

    cout << "\n========== USERS ==========\n";

    for(int i = 0; i < totalUsers; i++)
    {
        cout << "\nUser #" << i + 1 << endl;
        cout << "ID    : " << users[i].id << endl;
        cout << "Name  : " << users[i].name << endl;
        cout << "Phone : " << users[i].phone << endl;
    }
}

// ================= VIEW DRIVERS =================

void viewDrivers()
{
    if(totalDrivers == 0)
    {
        cout << "\nNo Drivers Registered!\n";
        return;
    }

    cout << "\n========== DRIVERS ==========\n";

    for(int i = 0; i < totalDrivers; i++)
    {
        cout << "\nDriver #" << i + 1 << endl;
        cout << "ID       : " << drivers[i].id << endl;
        cout << "Name     : " << drivers[i].name << endl;
        cout << "Vehicle  : " << drivers[i].vehicle << endl;
        cout << "Status   : ";

        if(drivers[i].available)
            cout << "Available\n";
        else
            cout << "Busy\n";
    }
}

// ================= BOOK RIDE =================

void requestRide()
{
    if(totalDrivers == 0)
    {
        cout << "\nNo Drivers Registered!\n";
        return;
    }

    string source, destination;

    cin.ignore();

    cout << "\nEnter Pickup Location: ";
    getline(cin, source);

    cout << "Enter Destination: ";
    getline(cin, destination);

    Driver* assigned = NULL;

    for(int i = 0; i < totalDrivers; i++)
    {
        if(drivers[i].available)
        {
            assigned = &drivers[i];
            break;
        }
    }

    if(assigned == NULL)
    {
        cout << "\nNo Drivers Available!\n";
        return;
    }

    assigned->available = false;

    cout << "\n====================================\n";
    cout << "Driver Assigned : " << assigned->name << endl;
    cout << "Vehicle         : " << assigned->vehicle << endl;
    cout << "Pickup          : " << source << endl;
    cout << "Destination     : " << destination << endl;
    cout << "Ride Started...\n";
    cout << "Ride Completed Successfully!\n";
    cout << "====================================\n";

    assigned->available = true;
}

// ================= FARE =================

void calculateFare()
{
    float distance;

    cout << "\nEnter Distance (KM): ";
    cin >> distance;

    float fare = 100 + (distance * 20);

    cout << "\nEstimated Fare = Rs. " << fare << endl;
}

// ================= MAIN =================

int main()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "=========================================\n";
        cout << "        RIDE BOOKING SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Register User\n";
        cout << "2. Register Driver\n";
        cout << "3. View Users\n";
        cout << "4. View Drivers\n";
        cout << "5. Book Ride\n";
        cout << "6. Calculate Fare\n";
        cout << "7. Exit\n";
        cout << "=========================================\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                registerDriver();
                break;

            case 3:
                viewUsers();
                break;

            case 4:
                viewDrivers();
                break;

            case 5:
                requestRide();
                break;

            case 6:
                calculateFare();
                break;

            case 7:
                cout << "\nThank You For Using Ride Booking System!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
