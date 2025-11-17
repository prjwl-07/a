#include <iostream>
using namespace std;

int main() {
    string list[] = {"Rice", "Sugar", "Milk", "Oil", "Salt"};
    float price[] = {40.0, 30.0, 25.0, 120.0, 10.0};
    int size = 5;

    string item;
    cout << "Enter the item name to search: ";
    cin >> item;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (list[i] == item) {
            cout << item << " costs Rs." << price[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << item << " not found in the list." << endl;
    }

    return 0;
}
