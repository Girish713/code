#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Reservation structure
struct Reservation {
    int id;
    string name;
    int tickets;

    Reservation(int id, const string& name, int tickets)
        : id(id), name(name), tickets(tickets) {}
};

// Ticket Reservation System class
class TicketReservationSystem {
private:
    queue<Reservation> reservations;
    int nextId;

public:
    TicketReservationSystem() : nextId(1) {}

    void makeReservation() {
        string name;
        int tickets;

        cout << "Enter your name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);

        cout << "Enter the number of tickets: ";
        cin >> tickets;

        if (tickets <= 0) {
            cout << "Invalid number of tickets.\n";
            return;
        }

        reservations.emplace(nextId, name, tickets);
        cout << "Reservation successful! Your reservation ID is " << nextId << ".\n";
        nextId++;
    }

    void cancelReservation() {
        if (reservations.empty()) {
            cout << "No reservations to cancel.\n";
            return;
        }

        int id;
        cout << "Enter the reservation ID to cancel: ";
        cin >> id;

        queue<Reservation> tempQueue;
        bool found = false;

        while (!reservations.empty()) {
            Reservation res = reservations.front();
            reservations.pop();
            if (res.id == id) {
                cout << "Reservation for " << res.name << " (ID: " << res.id << ") has been canceled.\n";
                found = true;
            } else {
                tempQueue.push(res);
            }
        }
        reservations.swap(tempQueue);

        if (!found) {
            cout << "Reservation ID " << id << " not found.\n";
        }
    }

    void modifyReservation() {
        if (reservations.empty()) {
            cout << "No reservations to modify.\n";
            return;
        }

        int id;
        cout << "Enter the reservation ID to modify: ";
        cin >> id;

        queue<Reservation> tempQueue;
        bool found = false;

        while (!reservations.empty()) {
            Reservation res = reservations.front();
            reservations.pop();
            if (res.id == id) {
                string newName;
                int newTickets;

                cout << "Enter new name (current: " << res.name << "): ";
                cin.ignore();
                getline(cin, newName);
                cout << "Enter new number of tickets (current: " << res.tickets << "): ";
                cin >> newTickets;

                if (newTickets <= 0) {
                    cout << "Invalid number of tickets. Modification aborted.\n";
                    tempQueue.push(res); // Push back the original reservation
                } else {
                    res.name = newName;
                    res.tickets = newTickets;
                    cout << "Reservation modified successfully.\n";
                }
                found = true;
            }
            tempQueue.push(res);
        }
        reservations.swap(tempQueue);

        if (!found) {
            cout << "Reservation ID " << id << " not found.\n";
        }
    }

    void displayReservations() {
        if (reservations.empty()) {
            cout << "No reservations found.\n";
            return;
        }

        cout << "Current Reservations:\n";
        queue<Reservation> tempQueue = reservations;
        while (!tempQueue.empty()) {
            Reservation res = tempQueue.front();
            tempQueue.pop();
            cout << "ID: " << res.id << ", Name: " << res.name << ", Tickets: " << res.tickets << endl;
        }
    }
};

int main() {
    TicketReservationSystem system;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Make a Reservation\n";
        cout << "2. Cancel a Reservation\n";
        cout << "3. Modify a Reservation\n";
        cout << "4. Display Reservations\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.makeReservation();
                break;
            case 2:
                system.cancelReservation();
                break;
            case 3:
                system.modifyReservation();
                break;
            case 4:
                system.displayReservations();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

