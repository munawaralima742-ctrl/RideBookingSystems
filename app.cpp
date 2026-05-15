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

Driver drivers[100];
int totalDrivers = 0;

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
// REGISTER DRIVER
// ============================
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

    cout << "Enter Price Per KM: ";
    cin >> d.pricePerKM;

    d.available = true;

    drivers[totalDrivers++] = d;

    cout << "\nDriver Registered Successfully!\n";
}

// ============================
// VIEW DRIVERS
// ============================
void viewDrivers()
{
    if(totalDrivers == 0)
    {
        cout << "\nNo drivers registered!\n";
        return;
    }

    cout << "\n===== DRIVERS =====\n";

    for(int i = 0; i < totalDrivers; i++)
    {
        cout << "ID: " << drivers[i].id << endl;
        cout << "Name: " << drivers[i].name << endl;
        cout << "Vehicle: " << drivers[i].vehicle << endl;
        cout << "Price/KM: Rs." << drivers[i].pricePerKM << endl;
        cout << "Status: "
             << (drivers[i].available ? "Available" : "Busy")
             << endl;

        cout << "----------------------\n";
    }
}

// ============================
// REGISTER USER
// ============================
void registerUser()
{
    User u;

    cout << "\nEnter User ID: ";
    cin >> u.id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, u.name);

    cout << "Enter Phone: ";
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
        cout << "\nNo users registered!\n";
        return;
    }

    cout << "\n===== USERS =====\n";

    for(int i = 0; i < totalUsers; i++)
    {
        cout << "ID: " << users[i].id << endl;
        cout << "Name: " << users[i].name << endl;
        cout << "Phone: " << users[i].phone << endl;

        cout << "----------------------\n";
    }
}

// ============================
// BOOK RIDE
// ============================
void requestRide()
{
    if(totalUsers == 0)
    {
        cout << "\nPlease register a user first!\n";
        return;
    }

    if(totalDrivers == 0)
    {
        cout << "\nPlease register drivers first!\n";
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

    cout << "\n===== AVAILABLE DRIVERS =====\n";

    for(int i = 0; i < totalDrivers; i++)
    {
        if(drivers[i].available)
        {
            cout << "ID: " << drivers[i].id
                 << " | Name: " << drivers[i].name
                 << " | Vehicle: " << drivers[i].vehicle
                 << " | Rs." << drivers[i].pricePerKM
                 << "/KM\n";
        }
    }

    int id;
    cout << "\nSelect Driver ID: ";
    cin >> id;

    int index = -1;

    for(int i = 0; i < totalDrivers; i++)
    {
        if(drivers[i].id == id &&
           drivers[i].available)
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

    float fare =
        100 + (distance * d.pricePerKM);

    Ride r;

    r.source = source;
    r.destination = destination;
    r.driverName = d.name;
    r.vehicle = d.vehicle;
    r.fare = fare;

    rideHistory[totalRides++] = r;

    cout << "\n===== RIDE BOOKED =====\n";
    cout << "Driver: " << d.name << endl;
    cout << "Vehicle: " << d.vehicle << endl;
    cout << "Total Fare: Rs." << fare << endl;
}

// ============================
// VIEW HISTORY
// ============================
void viewRideHistory()
{
    if(totalRides == 0)
    {
        cout << "\nNo Ride History!\n";
        return;
    }

    cout << "\n===== RIDE HISTORY =====\n";

    for(int i = 0; i < totalRides; i++)
    {
        cout << "Pickup: "
             << rideHistory[i].source << endl;

        cout << "Destination: "
             << rideHistory[i].destination << endl;

        cout << "Driver: "
             << rideHistory[i].driverName << endl;

        cout << "Vehicle: "
             << rideHistory[i].vehicle << endl;

        cout << "Fare: Rs."
             << rideHistory[i].fare << endl;

        cout << "----------------------\n";
    }
}

// ============================
// MAIN FUNCTION
// ============================
int main()
{
    int choice;

    do
    {
        cout << "\n============================\n";
        cout << "     RIDE BOOKING SYSTEM\n";
        cout << "============================\n";

        cout << "1. Register Driver\n";
        cout << "2. View Drivers\n";
        cout << "3. Register User\n";
        cout << "4. View Users\n";
        cout << "5. Book Ride\n";
        cout << "6. Ride History\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerDriver();
                break;

            case 2:
                viewDrivers();
                break;

            case 3:
                registerUser();
                break;

            case 4:
                viewUsers();
                break;

            case 5:
                requestRide();
                break;

            case 6:
                viewRideHistory();
                break;

            case 7:
                cout << "\nGoodbye!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
