#include <iostream>
#include<vector>
using namespace std;

class Seat {
public:
    int num;
    Seat *next, *prev;

    Seat(int n) {
        num = n;
        next = prev = NULL;
    }
};

class Theater {
public:
    int M, N;        // rows and seats
    vector<Seat*> rowHead;  // array of head pointers

    Theater(int m, int n) {
        M = m;
        N = n;
        rowHead.resize(M);

        // create doubly circular linked list for each row
        for (int i = 0; i < M; i++) {
            rowHead[i] = createRow(n);
        }
    }

    // create a full row of N available seats
    Seat* createRow(int n) {
        Seat *head = NULL, *last = NULL;

        for (int i = 1; i <= n; i++) {
            Seat* s = new Seat(i);

            if (!head) {
                head = last = s;
            } else {
                last->next = s;
                s->prev = last;
                last = s;
            }
        }

        // make circular
        head->prev = last;
        last->next = head;

        return head;
    }

    // show available seats in a row
    void displayRow(int r) {
        Seat* head = rowHead[r];
        if (!head) {
            cout << "Row " << r+1 << " : No seats available\n";
            return;
        }

        Seat* temp = head;
        cout << "Row " << r+1 << " available seats: ";
        do {
            cout << temp->num << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // book seat → remove from circular list
    void book(int r, int s) {
        Seat *head = rowHead[r];
        if (!head) {
            cout << "Row is fully booked!\n";
            return;
        }

        Seat* temp = head;
        bool found = false; 

        do {
            if (temp->num == s) {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "Seat not available!\n";
            return;
        }

        // only one seat in list
        if (temp->next == temp) {
            rowHead[r] = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == rowHead[r])
                rowHead[r] = temp->next;
        }

        delete temp;
        cout << "Seat booked!\n";
    }

    // cancel → add seat back into list at end
    void cancel(int r, int s) {
        // if row empty, recreate a single seat node
        if (!rowHead[r]) {
            Seat* x = new Seat(s);
            x->next = x->prev = x;
            rowHead[r] = x;
            cout << "Booking cancelled.\n";
            return;
        }

        Seat* head = rowHead[r];
        Seat* last = head->prev;

        Seat* x = new Seat(s);

        // insert at end
        last->next = x;
        x->prev = last;
        x->next = head;
        head->prev = x;

        cout << "Booking cancelled.\n";
    }
};

int main() {
    int M = 3, N = 5; // 3 rows, 5 seats each
    Theater t(M, N);

    int choice, r, s;

    while (true) {
        cout << "\n1. Display\n2. Book seat\n3. Cancel seat\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 4) break;

        cout << "Enter row number (1-" << M << "): ";
        cin >> r; r--;

        switch(choice) {
            case 1:
                t.displayRow(r);
                break;
            case 2:
                cout << "Enter seat number: ";
                cin >> s;
                t.book(r, s);
                break;
            case 3:
                cout << "Enter seat number: ";
                cin >> s;
                t.cancel(r, s);
                break;
        }
    }

    return 0;
}
