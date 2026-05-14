#include <iostream>
#include <string>
using namespace std;

// ============================
// DRIVER STRUCTURE
// ============================
struct Driver
{
    int id;
    string name;
    string vehicle;
    int pricePerKM;
    bool available;
};

// ============================
// DEFAULT DRIVERS
// ============================
Driver drivers[10] =
{
    {1, "Ali",      "Honda Civic",     18, true},
    {2, "Ahmed",    "Suzuki Alto",     12, true},
    {3, "Usman",    "Toyota Corolla",  20, true},
    {4, "Hamza",    "WagonR",          10, true},
    {5, "Bilal",    "Honda City",      16, true},
    {6, "Awais",    "Cultus",          11, true},
    {7, "Saqib",    "Kia Sportage",    25, true},
    {8, "Daniyal",  "Mehran",           9, true},
    {9, "Farhan",   "Toyota Yaris",    17, true},
    {10,"Zain",     "Swift",           14, true}
};

int totalDrivers = 10;

// ============================
// USER STRUCTURE
// ============================
struct User
{
    int id;
    string name;
    string phone;
};

User users[100];
int totalUsers = 0;

// ============================
// RIDE STRUCTURE
// ============================
struct Ride
{
    string source;
    string destination;
    string driverName;
    string vehicle;
    float fare;
};

Ride rideHistory[100];
int totalRides = 0;

// ============================
// REGISTER USER
// ============================
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

    users[totalUsers++] = u;

    cout << "\nUser Registered Successfully!\n";
}

// ============================
// VIEW USERS
// ============================
void viewUsers()
{
    if(totalUsers == 0)
    {
        cout << "\nNo Users Registered!\n";
        return;
    }

    cout << "\n============= USERS =============\n";

    for(int i = 0; i < totalUsers; i++)
    {
        cout << "\nUser #" << i + 1 << endl;
        cout << "ID    : " << users[i].id << endl;
        cout << "Name  : " << users[i].name << endl;
        cout << "Phone : " << users[i].phone << endl;
    }
}

// ============================
// VIEW DRIVERS
// ============================
void viewDrivers()
{
    cout << "\n============= DRIVERS =============\n";

    for(int i = 0; i < totalDrivers; i++)
    {
        cout << "\nID       : " << drivers[i].id << endl;
        cout << "Name     : " << drivers[i].name << endl;
        cout << "Vehicle  : " << drivers[i].vehicle << endl;
        cout << "Price/KM : Rs. " << drivers[i].pricePerKM << endl;

        cout << "Status   : " 
             << (drivers[i].available ? "Available" : "Busy") << endl;
    }
}

// ============================
// BOOK RIDE (MANUAL DRIVER SELECT)
// ============================
void requestRide()
{
    if(totalUsers == 0)
    {
        cout << "\nPlease Register User First!\n";
        return;
    }

    string source, destination;
    float distance;

    cin.ignore();

    cout << "\nEnter Pickup Location: ";
    getline(cin, source);

    cout << "Enter Destination: ";
    getline(cin, destination);

    cout << "Enter Distance (KM): ";
    cin >> distance;

    // SHOW DRIVERS
    cout << "\n============= AVAILABLE DRIVERS =============\n";

    for(int i = 0; i < totalDrivers; i++)
    {
        if(drivers[i].available)
        {
            cout << "\nID       : " << drivers[i].id << endl;
            cout << "Name     : " << drivers[i].name << endl;
            cout << "Vehicle  : " << drivers[i].vehicle << endl;
            cout << "Price/KM : Rs. " << drivers[i].pricePerKM << endl;
        }
    }

    int id;
    cout << "\nEnter Driver ID to Book: ";
    cin >> id;

    int index = -1;

    for(int i = 0; i < totalDrivers; i++)
    {
        if(drivers[i].id == id && drivers[i].available)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        cout << "\nInvalid Driver Selection!\n";
        return;
    }

    Driver &d = drivers[index];

    float fare = 100 + (distance * d.pricePerKM);

    Ride r;
    r.source = source;
    r.destination = destination;
    r.driverName = d.name;
    r.vehicle = d.vehicle;
    r.fare = fare;

    rideHistory[totalRides++] = r;

    cout << "\n=========================================\n";
    cout << "        RIDE BOOKED SUCCESSFULLY\n";
    cout << "=========================================\n";

    cout << "Driver   : " << d.name << endl;
    cout << "Vehicle  : " << d.vehicle << endl;
    cout << "Fare     : Rs. " << fare << endl;

    cout << "\nRide Completed!\n";

    d.available = false;
    d.available = true;
}

// ============================
// RIDE HISTORY
// ============================
void viewRideHistory()
{
    if(totalRides == 0)
    {
        cout << "\nNo Ride History Found!\n";
        return;
    }

    cout << "\n============= RIDE HISTORY =============\n";

    for(int i = 0; i < totalRides; i++)
    {
        cout << "\nRide #" << i + 1 << endl;
        cout << "Pickup      : " << rideHistory[i].source << endl;
        cout << "Destination : " << rideHistory[i].destination << endl;
        cout << "Driver      : " << rideHistory[i].driverName << endl;
        cout << "Vehicle     : " << rideHistory[i].vehicle << endl;
        cout << "Fare        : Rs. " << rideHistory[i].fare << endl;
    }
}

// ============================
// SEARCH RIDE
// ============================
void searchRide()
{
    string loc;

    cin.ignore();

    cout << "\nEnter Pickup Location: ";
    getline(cin, loc);

    bool found = false;

    for(int i = 0; i < totalRides; i++)
    {
        if(rideHistory[i].source == loc)
        {
            found = true;
            cout << "\nRide Found!\n";
            cout << "Driver : " << rideHistory[i].driverName << endl;
            cout << "Fare   : Rs. " << rideHistory[i].fare << endl;
        }
    }

    if(!found)
        cout << "\nNo Ride Found!\n";
}

// ============================
// MAIN MENU
// ============================
int main()
{
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "        RIDE BOOKING SYSTEM\n";
        cout << "=========================================\n";

        cout << "1. Register User\n";
        cout << "2. View Users\n";
        cout << "3. View Drivers\n";
        cout << "4. Book Ride\n";
        cout << "5. View Ride History\n";
        cout << "6. Search Ride\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: registerUser(); break;
            case 2: viewUsers(); break;
            case 3: viewDrivers(); break;
            case 4: requestRide(); break;
            case 5: viewRideHistory(); break;
            case 6: searchRide(); break;
            case 7: cout << "\nGoodbye!\n"; break;
            default: cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
