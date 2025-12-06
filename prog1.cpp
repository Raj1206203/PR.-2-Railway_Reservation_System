#include <iostream>

using namespace std;

class RailwaySystem
{
private:
    static const int MAX = 20;

    int trainNumbers[MAX];
    string trainNames[MAX];
    string sources[MAX];
    string destinations[MAX];
    string departureTimes[MAX];

    int trainCount;              
    static int totalTrains;      

public:
    RailwaySystem()
    {
        trainCount = 0;
    }

    ~RailwaySystem()
    {
    }

    int getTrainCount() const
    {
        return trainCount;
    }

    static int getTotalTrains()
    {
        return totalTrains;
    }

    void addTrain()
    {
        if (trainCount >= MAX)
        {
            cout << "you cant add more train now.\n";
            return;
        }

        cout << "\n=== Enter Train Details ===\n";

        cout << "Enter Train Number: ";
        cin >> trainNumbers[trainCount];

        cout << "Enter Train Name: ";
        cin >> trainNames[trainCount];

        cout << "Enter Source Station: ";
        cin >> sources[trainCount];

        cout << "Enter Destination Station: ";
        cin >> destinations[trainCount];

        cout << "Enter Departure Time: ";
        cin >> departureTimes[trainCount];

        trainCount++;
        totalTrains++;

        cout << "Train added successfully!\n";
    }

    void displayTrain(int index) const
    {
        cout << "==================================\n";
        cout << "Train Number   : " << trainNumbers[index] << endl;
        cout << "Train Name     : " << trainNames[index] << endl;
        cout << "Source         : " << sources[index] << endl;
        cout << "Destination    : " << destinations[index] << endl;
        cout << "Departure Time : " << departureTimes[index] << endl;
    }

    void displayAllTrains() const
    {
        if (trainCount == 0)
        {
            cout << "No train records available.\n";
            return;
        }

        cout << "\n=== All Train Records ===\n";
        for (int i = 0; i < trainCount; i++)
        {
            displayTrain(i);
        }
    }

    void searchTrainByNumber() const
    {
        if (trainCount == 0)
        {
            cout << "No train records to search.\n";
            return;
        }

        int searchNo;
        cout << "Enter Train Number to search: ";
        cin >> searchNo;

        bool found = false;

        for (int i = 0; i < trainCount; i++)
        {
            if (trainNumbers[i] == searchNo)
            {
                cout << "\nTrain found:\n";
                displayTrain(i);
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Train with number " << searchNo << " not found.\n";
        }
    }
};

int RailwaySystem::totalTrains = 0;

int main()
{
    RailwaySystem system;
    int choice;

    do
    {
        cout << "\n========= Railway Reservation System =========\n";
        cout << "1. Add Train \n";
        cout << "2. Display All Trains \n";
        cout << "3. Search Train by Number \n";
        cout << "4. Show Total Trains \n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAllTrains();
            break;

        case 3:
            system.searchTrainByNumber();
            break;

        case 4:
            cout << "Total trains added: "
                 << RailwaySystem::getTotalTrains() << endl;
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
