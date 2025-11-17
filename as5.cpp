#include <iostream>
#include <cstring>
using namespace std;

class Browser {
    int page_id;
    char page_desc[20];
    char time_stamp[20];
    Browser* next;
    Browser* prev;

public:
    static Browser* head;

    Browser(int id, const char* desc, const char* ts) {
        page_id = id;
        strcpy(page_desc, desc);
        strcpy(time_stamp, ts);
        next = prev = NULL;
    }

    // Add a new page at end
    static void add_pages(int id, const char* desc, const char* ts) {
        Browser* newNode = new Browser(id, desc, ts);

        if (!head) {
            head = newNode;
            cout << "Page added as first page.\n";
            return;
        }

        Browser* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        cout << "Page added at end.\n";
    }

    // Visit (search) a page
    static void visit_page(int id) {
        if (!head) {
            cout << "History is empty.\n";
            return;
        }
        Browser* temp = head;
        while (temp) {
            if (temp->page_id == id) {
                cout << "Visited Page ID: " << temp->page_id
                     << " (" << temp->page_desc
                     << ", " << temp->time_stamp << ")\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Page not found in history.\n";
    }

    // Navigate forward & backward
    static void navigate_pages() {
        if (!head) {
            cout << "History is empty.\n";
            return;
        }
        cout << "Forward Traversal: ";
        Browser* temp = head;
        while (temp) {
            cout << temp->page_id << " ";
            if (temp->next == NULL) break;
            temp = temp->next;
        }
        cout << endl;

        cout << "Backward Traversal: ";
        while (temp) {
            cout << temp->page_id << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Delete page by id
    static void delete_page(int id) {
        if (!head) {
            cout << "History is empty.\n";
            return;
        }
        Browser* temp = head;
        while (temp && temp->page_id != id)
            temp = temp->next;

        if (!temp) {
            cout << "Page not found.\n";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Page deleted successfully.\n";
    }
};

Browser* Browser::head = NULL;

int main() {
    int choice, id;
    char desc[20], ts[20];

    cout << "Browser History using Doubly Linked List\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Page\n";
        cout << "2. Visit Page\n";
        cout << "3. Navigate Pages\n";
        cout << "4. Delete Page\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Page ID: ";
                cin >> id;
                cout << "Enter Page Description: ";
                cin >> desc;
                cout << "Enter Time Stamp: ";
                cin >> ts;
                Browser::add_pages(id, desc, ts);
                break;

            case 2:
                cout << "Enter Page ID to visit: ";
                cin >> id;
                Browser::visit_page(id);
                break;

            case 3:
                Browser::navigate_pages();
                break;

            case 4:
                cout << "Enter Page ID to delete: ";
                cin >> id;
                Browser::delete_page(id);
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
