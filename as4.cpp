#include <iostream>
using namespace std;

class Music
{
public:
    struct song
    {
        int music_id;
        string title;
        float time_duration;
        struct song *next;
    };

    song *head;

public:
    Music()
    {
        head = NULL;
    }

    // FUNCTION TO APPEND SONGS TO PLAYLIST
    void append(int id, float time, string title)
    {
        song *newnode = new song;
        newnode->music_id = id;
        newnode->title = title;
        newnode->time_duration = time;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        song *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    // FUNCTION TO INSERT A NEW SONG
    void insertion(int position, int id, float time, string title)
    {
        song *newnode = new song;
        newnode->music_id = id;
        newnode->title = title;
        newnode->time_duration = time;
        newnode->next = NULL;

        if (position == 1 || head == NULL)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        song *temp = head;
        int i = 1;
        while (temp != NULL && i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            cout << "Invalid position!" << endl;
            delete newnode;
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // FUNCTION TO DELETE A SONG
    void deletion(int id)
    {
        if (head == NULL)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }

        if (head->music_id == id)
        {
            song *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        song *temp = head;
        while (temp->next != NULL && temp->next->music_id != id)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Song with ID " << id << " not found!" << endl;
            return;
        }

        song *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // FUNCTION TO SORT SONGS BY THEIR IDs
    void sort_id()
    {
        if (head == NULL)
            return;

        for (song *temp = head; temp != NULL; temp = temp->next)
        {
            for (song *temp1 = temp->next; temp1 != NULL; temp1 = temp1->next)
            {
                if (temp->music_id > temp1->music_id)
                {
                    swap(temp->music_id, temp1->music_id);
                    swap(temp->title, temp1->title);
                    swap(temp->time_duration, temp1->time_duration);
                }
            }
        }
    }

    // FUNCTION TO DISPLAY PLAYLIST
    void display()
    {
        song *temp = head;
        cout << "\n--- Playlist ---\n";
        while (temp != NULL)
        {
            cout << "Music ID: " << temp->music_id << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Duration: " << temp->time_duration << " mins" << endl;
            cout << "-------------------" << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Music m;
    int n;
    cout << "Enter the number of songs in playlist: ";
    cin >> n;

    int id;
    int position;
    string title;
    float time;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for song " << i + 1 << endl;
        cout << "Enter music ID: ";
        cin >> id;
        cout << "Enter title: ";
        cin.ignore();
        getline(cin,title);
        cout << "Enter duration (in mins): ";
        cin >> time;
        m.append(id, time, title);
    }

    int choice;
    cout << "\nEnter your choice:\n";
    cout << "1. Insert a new song\n";
    cout << "2. Delete a song\n";
    cout << "3. Sort by ID\n";
    cout << "4. Display playlist\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the position to insert: ";
        cin >> position;
        cout << "Enter music ID: ";
        cin >> id;
        cout << "Enter title: ";
        cin.ignore();
        getline(cin,title);
        cout << "Enter duration: ";
        cin >> time;
        m.insertion(position, id, time, title);
        m.display();
        break;

    case 2:
        cout << "Enter the ID of the song to delete: ";
        cin >> id;
        m.deletion(id);
        m.display();
        break;

    case 3:
        m.sort_id();
        cout << "\nPlaylist sorted by ID:\n";
        m.display();
        break;

    case 4:
        m.display();
        break;

    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}
