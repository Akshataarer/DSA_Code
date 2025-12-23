#include <iostream>
using namespace std;

// Structure to store Beehive information
struct Beehive {
    int hiveID;           // Unique Hive ID
    float healthLevel;    // Health percentage of the hive
    float honeyYield;     // Honey produced in kg
    Beehive *next;
    Beehive *prev;
};

// Function prototypes
void displayDLL(Beehive *head);
Beehive* insertAtFront(Beehive *head);
Beehive* insertAtEnd(Beehive *head);
Beehive* deleteAtFront(Beehive *head);
Beehive* deleteAtEnd(Beehive *head);
Beehive* insertInBetween(Beehive *head);
Beehive* deleteInBetween(Beehive *head);
int count(Beehive *head);

int main() {
    Beehive *head = nullptr;
    int choice;

    while (true) {
        cout << "\n--- Smart Beekeeping DLL Menu ---\n";
        cout << "1. Display All Hives\n2. Insert Hive at Front\n3. Exit\n";
        cout << "4. Insert Hive at End\n5. Delete Hive at Front\n6. Delete Hive at End\n";
        cout << "7. Count Hives\n8. Delete Hive in Between\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
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

void displayDLL(Beehive *head) {
    if (!head) {
        cout << "No hives available.\n";
        return;
    }
    Beehive *temp = head;
    while (temp) {
        cout << "Hive ID: " << temp->hiveID
             << " | Health Level: " << temp->healthLevel << "%"
             << " | Honey Yield: " << temp->honeyYield << " kg\n";
        temp = temp->next;
    }
}

Beehive* insertAtFront(Beehive *head) {
    Beehive *ptr = new Beehive();
    cout << "Enter Hive ID, Health Level (%), Honey Yield (kg): ";
    cin >> ptr->hiveID >> ptr->healthLevel >> ptr->honeyYield;

    if (!head) {
        ptr->next = ptr->prev = nullptr;
        return ptr;
    }

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = nullptr;
    return ptr;
}

Beehive* insertAtEnd(Beehive *head) {
    Beehive *ptr = new Beehive();
    cout << "Enter Hive ID, Health Level (%), Honey Yield (kg): ";
    cin >> ptr->hiveID >> ptr->healthLevel >> ptr->honeyYield;

    if (!head) {
        ptr->next = ptr->prev = nullptr;
        return ptr;
    }

    Beehive *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = nullptr;
    return head;
}

Beehive* deleteAtFront(Beehive *head) {
    if (!head) {
        cout << "No hives to delete.\n";
        return nullptr;
    }

    Beehive *temp = head;
    head = head->next;
    if (head) head->prev = nullptr;

    cout << "Deleted Hive ID: " << temp->hiveID << endl;
    delete temp;
    return head;
}

Beehive* deleteAtEnd(Beehive *head) {
    if (!head) {
        cout << "No hives to delete.\n";
        return nullptr;
    }

    if (!head->next) {
        cout << "Deleted Hive ID: " << head->hiveID << endl;
        delete head;
        return nullptr;
    }

    Beehive *temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    cout << "Deleted Hive ID: " << temp->hiveID << endl;
    delete temp;
    return head;
}

int count(Beehive *head) {
    int c = 0;
    Beehive *temp = head;
    while (temp) {
        c++;
        temp = temp->next;
    }
    cout << "Total Hives: " << c << endl;
    return c;
}

Beehive* insertInBetween(Beehive *head) {
    int pos;
    cout << "Enter the position to insert: ";
    cin >> pos;

    if (pos < 1 || pos > count(head) + 1) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return insertAtFront(head);
    if (pos == count(head) + 1) return insertAtEnd(head);

    Beehive *ptr = new Beehive();
    cout << "Enter Hive ID, Health Level (%), Honey Yield (kg): ";
    cin >> ptr->hiveID >> ptr->healthLevel >> ptr->honeyYield;

    Beehive *temp = head;
    for (int i = 1; i < pos - 1; ++i) temp = temp->next;

    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;

    return head;
}

Beehive* deleteInBetween(Beehive *head) {
    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;

    if (pos < 1 || pos > count(head)) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return deleteAtFront(head);
    if (pos == count(head)) return deleteAtEnd(head);

    Beehive *temp = head;
    for (int i = 1; i < pos; ++i) temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    cout << "Deleted Hive ID: " << temp->hiveID << endl;
    delete temp;

    return head;
}
