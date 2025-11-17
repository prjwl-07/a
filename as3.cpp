#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {


    unordered_map<string,string> phoneBook;
    int n;
    cout<<"fill the data:"<<endl;
    cout<<"enter the no. of entries:";
    cin>>n;

    for (int i=0;i<n;i++){
        string name;
        string no;
        cout<<"enter the person name:"<<endl;
        cin>>name;
        cout<<"enter the number of that person:"<<endl;
        cin>>no;
        phoneBook[name]=no;
    }

    // // Inserting entries
    // phoneBook["Alice"] = "9876543210";
    // phoneBook["Bob"] = "8765432109";
    // phoneBook["Charlie"] = "7654321098";

    string name;
    cout << "Enter client name to search: ";
    cin >> name;

    // Searching with O(1) average time
    if (phoneBook.find(name) != phoneBook.end()) {
        cout << "Phone number of " << name << ": " << phoneBook[name] << endl;
    } else {
        cout << "Client not found in phone book." << endl;
    }




    return 0;
}
