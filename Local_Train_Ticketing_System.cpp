#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ticket {
public:
    Ticket(const string& passengerName, int seatNumber)
        : passengerName(passengerName), seatNumber(seatNumber) {}

    string getPassengerName() const {
        return passengerName;
    }

    int getSeatNumber() const {
        return seatNumber;
    }

private:
    string passengerName;
    int seatNumber;
};

class Train {
public:
    Train(int totalSeats) : totalSeats(totalSeats) {
        for (int i = 0; i < totalSeats; ++i) {
            availableSeats.push_back(i + 1);
        }
    }

    bool bookTicket(const string& passengerName) {
        if (availableSeats.empty()) {
            cout << "Sorry, no more available seats." << endl;
            return false;
        }

        int seatNumber = availableSeats.back();
        availableSeats.pop_back();

        Ticket ticket(passengerName, seatNumber);
        tickets.push_back(ticket);

        cout << "Ticket booked for " << passengerName << ". Seat Number: " << seatNumber << endl;
        return true;
    }

    bool cancelTicket(int seatNumber) {
        for (auto it = tickets.begin(); it != tickets.end(); ++it) {
            if (it->getSeatNumber() == seatNumber) {
                availableSeats.push_back(seatNumber);
                cout << "Ticket for Seat Number " << seatNumber << " canceled." << endl;
                tickets.erase(it);
                return true;
            }
        }

        cout << "Ticket for Seat Number " << seatNumber << " not found." << endl;
        return false;
    }

private:
    int totalSeats;
    vector<int> availableSeats;
    vector<Ticket> tickets;
};

int main() {
    Train train(50); // Creating a train with 50 seats

    while (true) {
        cout << "1. Book Ticket\n2. Cancel Ticket\n3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter passenger name: ";
            string passengerName;
            cin >> passengerName;
            train.bookTicket(passengerName);
        } else if (choice == 2) {
            cout << "Enter seat number to cancel: ";
            int seatNumber;
            cin >> seatNumber;
            train.cancelTicket(seatNumber);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}
