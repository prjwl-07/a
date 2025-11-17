#include <iostream>
using namespace std;

struct Seat {
    int seat_no;
    bool booked;
    Seat *next, *prev;
};

class Theatre {
    static const int rows = 3;
    static const int seats = 5;
    Seat* head[rows];

public:
    Theatre() {
        for (int i = 0; i < rows; i++) {
            Seat* first = nullptr;
            Seat* last = nullptr;
            for (int j = 1; j <= seats; j++) {
                Seat* newSeat = new Seat{j, false, nullptr, nullptr};
                if (!first) {
                    first = newSeat;
                    last = newSeat;
                } else {
                    last->next = newSeat;
                    newSeat->prev = last;
                    last = newSeat;
                }
            }
            // make circular
            last->next = first;
            first->prev = last;
            head[i] = first;
        }
    }

    void displayAvailable() {
        cout << "\nAvailable Seats:\n";
        for (int i = 0; i < rows; i++) {
            cout << "Row " << i + 1 << ": ";
            Seat* temp = head[i];
            do {
                if (!temp->booked) cout << temp->seat_no << " ";
                temp = temp->next;
            } while (temp != head[i]);
            cout << endl;
        }
    }

    void bookSeat(int r, int s) {
        if (r < 1 || r > rows) {
            cout << "Invalid row!\n"; return;
        }
        Seat* temp = head[r - 1];
        do {
            if (temp->seat_no == s) {
                if (temp->booked) cout << "Seat already booked!\n";
                else {
                    temp->booked = true;
                    cout << "Seat booked!\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head[r - 1]);
        cout << "Invalid seat number!\n";
    }

    void cancelSeat(int r, int s) {
        if (r < 1 || r > rows) {
            cout << "Invalid row!\n"; return;
        }
        Seat* temp = head[r - 1];
        do {
            if (temp->seat_no == s) {
                if (!temp->booked) cout << "Seat is not booked!\n";
                else {
                    temp->booked = false;
                    cout << "Booking cancelled!\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head[r - 1]);
        cout << "Invalid seat number!\n";
    }
};

int main() {
    Theatre t;
    int choice, r, s;
    do {
        cout << "\n1. Display Seats\n2. Book Seat\n3. Cancel Booking\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: t.displayAvailable(); break;
            case 2: cout << "Enter Row and Seat: "; cin >> r >> s; t.bookSeat(r,s); break;
            case 3: cout << "Enter Row and Seat: "; cin >> r >> s; t.cancelSeat(r,s); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 4);
}
