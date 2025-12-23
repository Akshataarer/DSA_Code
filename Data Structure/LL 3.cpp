#include <iostream>
using namespace std;

// Structure to store mushroom chamber data
struct MushroomChamber {
    int chamberID;
    float temperature;
    float humidity;
    float moisture;
    MushroomChamber *next;
    MushroomChamber *prev;
};

// Function prototypes
void displayDLL(MushroomChamber *head);
MushroomChamber* insertAtFront(MushroomChamber *head);
MushroomChamber* insertAtEnd(MushroomChamber *head);
MushroomChamber* deleteAtFront(MushroomChamber *head);
MushroomChamber* deleteAtEnd(MushroomChamber *head);
MushroomChamber* insertInBetween(MushroomChamber *head);
MushroomChamber* deleteInBetween(MushroomChamber *head);
int count(MushroomChamber *head);

int main() {
    MushroomChamber *head = nullptr;
    int ch;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display Chambers\n";
        cout << "2. Insert at front\n";
        cout << "3. Exit\n";
        cout << "4. Insert at end\n";
        cout << "5. Delete at front\n";
        cout << "6. Delete at end\n";
        cout << "7. Count Chambers\n";
        cout << "8. Delete in between\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: displayDLL(head); break;
            case 2: head = insertAtFront(head); break;
            case 3: exit(0);
            case 4: head = insertAtEnd(head); break;
            case 5: head = deleteAtFront(head); break;
            case 6: head = deleteAtEnd(head); break;
            case 7: count(head); break;
            case 8: head = deleteInBetween(head); break;
            default: cout << "Invalid choice\n"; break;
        }
    }

    return 0;
}

// Display all mushroom chambers
void displayDLL(MushroomChamber *head) {
    if (!head) {
        cout << "No chambers present.\n";
        return;
    }
    MushroomChamber *temp = head;
    while (temp) {
        cout << "Chamber ID: " << temp->chamberID
             << " | Temp: " << temp->temperature << "°C"
             << " | Humidity: " << temp->humidity << "%"
             << " | Moisture: " << temp->moisture << "%\n";
        temp = temp->next;
    }
}

// Insert new chamber at front
MushroomChamber* insertAtFront(MushroomChamber *head) {
    MushroomChamber *ptr = new MushroomChamber();
    cout << "Enter Chamber ID, Temperature, Humidity, Moisture: ";
    cin >> ptr->chamberID >> ptr->temperature >> ptr->humidity >> ptr->moisture;

    ptr->next = head;
    ptr->prev = nullptr;
    if (head) head->prev = ptr;
    return ptr;
}

// Insert new chamber at end
MushroomChamber* insertAtEnd(MushroomChamber *head) {
    MushroomChamber *ptr = new MushroomChamber();
    cout << "Enter Chamber ID, Temperature, Humidity, Moisture: ";
    cin >> ptr->chamberID >> ptr->temperature >> ptr->humidity >> ptr->moisture;
    ptr->next = nullptr;

    if (!head) {
        ptr->prev = nullptr;
        return ptr;
    }

    MushroomChamber *temp = head;
    while (temp->next) temp = temp->next;

    temp->next = ptr;
    ptr->prev = temp;
    return head;
}

// Delete chamber at front
MushroomChamber* deleteAtFront(MushroomChamber *head) {
    if (!head) {
        cout << "No chambers present.\n";
        return nullptr;
    }
    MushroomChamber *temp = head;
    head = head->next;
    if (head) head->prev = nullptr;

    cout << "Deleted Chamber ID: " << temp->chamberID << endl;
    delete temp;
    return head;
}

// Delete chamber at end
MushroomChamber* deleteAtEnd(MushroomChamber *head) {
    if (!head) {
        cout << "No chambers present.\n";
        return nullptr;
    }

    if (!head->next) {
        cout << "Deleted Chamber ID: " << head->chamberID << endl;
        delete head;
        return nullptr;
    }

    MushroomChamber *temp = head;
    while (temp->next) temp = temp->next;

    temp->prev->next = nullptr;
    cout << "Deleted Chamber ID: " << temp->chamberID << endl;
    delete temp;
    return head;
}

// Count chambers
int count(MushroomChamber *head) {
    int cnt = 0;
    MushroomChamber *temp = head;
    while (temp) {
        cnt++;
        temp = temp->next;
    }
    cout << "Total Chambers: " << cnt << endl;
    return cnt;
}

// Insert chamber at a specific position
MushroomChamber* insertInBetween(MushroomChamber *head) {
    int pos;
    cout << "Enter the position to insert: ";
    cin >> pos;

    if (pos < 1 || pos > count(head) + 1) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return insertAtFront(head);
    if (pos == count(head) + 1) return insertAtEnd(head);

    MushroomChamber *ptr = new MushroomChamber();
    cout << "Enter Chamber ID, Temperature, Humidity, Moisture: ";
    cin >> ptr->chamberID >> ptr->temperature >> ptr->humidity >> ptr->moisture;

    MushroomChamber *temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;

    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;

    return head;
}

// Delete chamber at a specific position
MushroomChamber* deleteInBetween(MushroomChamber *head) {
    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;

    if (pos < 1 || pos > count(head)) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return deleteAtFront(head);
    if (pos == count(head)) return deleteAtEnd(head);

    MushroomChamber *temp = head;
    for (int i = 1; i < pos; i++) temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    cout << "Deleted Chamber ID: " << temp->chamberID << endl;
    delete temp;

    return head;
}
