#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct Song {
    string title;
    Song* next;

    Song(const string& title) : title(title), next(nullptr) {}
};

// Playlist class to manage songs
class Playlist {
private:
    Song* head;

public:
    Playlist() : head(nullptr) {}

    ~Playlist() {
        while (head) {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addSong(const string& title) {
        Song* newSong = new Song(title);
        if (!head) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
        cout << "Song \"" << title << "\" added to the playlist.\n";
    }

    void removeSong(const string& title) {
        if (!head) {
            cout << "The playlist is empty. Cannot remove \"" << title << "\".\n";
            return;
        }
        if (head->title == title) {
            Song* temp = head;
            head = head->next;
            delete temp;
            cout << "Song \"" << title << "\" removed from the playlist.\n";
            return;
        }
        Song* current = head;
        while (current->next && current->next->title != title) {
            current = current->next;
        }
        if (current->next) {
            Song* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Song \"" << title << "\" removed from the playlist.\n";
        } else {
            cout << "Song \"" << title << "\" not found in the playlist.\n";
        }
    }

    void reorderSongs(int oldPosition, int newPosition) {
        if (!head || oldPosition == newPosition) {
            cout << "No reordering needed.\n";
            return;
        }

        Song* prevOld = nullptr;
        Song* currentOld = head;
        int pos = 1;

        while (currentOld && pos < oldPosition) {
            prevOld = currentOld;
            currentOld = currentOld->next;
            pos++;
        }

        if (!currentOld) {
            cout << "Invalid old position.\n";
            return;
        }

        if (prevOld) {
            prevOld->next = currentOld->next;
        } else {
            head = currentOld->next;
        }

        if (newPosition == 1) {
            currentOld->next = head;
            head = currentOld;
            cout << "Song moved to position " << newPosition << ".\n";
            return;
        }

        Song* prevNew = nullptr;
        Song* currentNew = head;
        pos = 1;

        while (currentNew && pos < newPosition) {
            prevNew = currentNew;
            currentNew = currentNew->next;
            pos++;
        }

        if (prevNew) {
            prevNew->next = currentOld;
        }
        currentOld->next = currentNew;

        cout << "Song moved to position " << newPosition << ".\n";
    }

    void displayPlaylist() {
        if (!head) {
            cout << "The playlist is empty.\n";
            return;
        }
        Song* temp = head;
        int index = 1;
        cout << "Playlist:\n";
        while (temp) {
            cout << index++ << ". " << temp->title << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist playlist;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Reorder Songs\n";
        cout << "4. Display Playlist\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // To consume the newline character left in the input buffer

        switch (choice) {
            case 1: {
                string title;
                cout << "Enter song title: ";
                getline(cin, title);
                playlist.addSong(title);
                break;
            }
            case 2: {
                string title;
                cout << "Enter song title to remove: ";
                getline(cin, title);
                playlist.removeSong(title);
                break;
            }
            case 3: {
                int oldPos, newPos;
                cout << "Enter the current position of the song: ";
                cin >> oldPos;
                cout << "Enter the new position: ";
                cin >> newPos;
                playlist.reorderSongs(oldPos, newPos);
                break;
            }
            case 4:
                playlist.displayPlaylist();
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

