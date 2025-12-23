#include <iostream>
using namespace std;

// Structure to store plant information
struct Plant {
    char name[30];
    int age;       // Age of plant in days
    float height;  // Height in cm
    Plant *next;
    Plant *prev;
};

// Function prototypes
void displayPlants(Plant *head);
Plant* insertAtFront(Plant *head);
Plant* insertAtEnd(Plant *head);
Plant* deleteAtFront(Plant *head);
Plant* deleteAtEnd(Plant *head);
Plant* insertInBetween(Plant *head);
Plant* deleteInBetween(Plant *head);
int countPlants(Plant *head);

int main() {
    Plant *head = nullptr;
    int choice;

    while (true) {
        cout << "\nPlant Nursery Menu:\n";
        cout << "1. Display all plants\n";
        cout << "2. Insert plant at front\n";
        cout << "3. Exit\n";
        cout << "4. Insert plant at end\n";
        cout << "5. Delete plant at front\n";
        cout << "6. Delete plant at end\n";
        cout << "7. Count plants\n";
        cout << "8. Delete plant in between\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayPlants(head); break;
            case 2: head = insertAtFront(head); break;
            case 3: exit(0);
            case 4: head = insertAtEnd(head); break;
            case 5: head = deleteAtFront(head); break;
            case 6: head = deleteAtEnd(head); break;
            case 7: countPlants(head); break;
            case 8: head = deleteInBetween(head); break;
            default: cout << "Invalid choice\n"; break;
        }
    }

    return 0;
}

// Display all plants
void displayPlants(Plant *head) {
    if (!head) {
        cout << "Nursery is empty\n";
        return;
    }
    Plant *temp = head;
    while (temp) {
        cout << "Plant Name: " << temp->name
             << " Age: " << temp->age << " days"
             << " Height: " << temp->height << " cm" << endl;
        temp = temp->next;
    }
}

// Insert at front
Plant* insertAtFront(Plant *head) {
    Plant *ptr = new Plant();
    cout << "Enter plant name, age (days), and height (cm): ";
    cin >> ptr->name >> ptr->age >> ptr->height;

    if (!head) {
        ptr->next = nullptr;
        ptr->prev = nullptr;
        return ptr;
    }

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = nullptr;
    return ptr;
}

// Insert at end
Plant* insertAtEnd(Plant *head) {
    Plant *ptr = new Plant();
    cout << "Enter plant name, age (days), and height (cm): ";
    cin >> ptr->name >> ptr->age >> ptr->height;

    if (!head) {
        ptr->next = nullptr;
        ptr->prev = nullptr;
        return ptr;
    }

    Plant *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = nullptr;
    return head;
}

// Delete at front
Plant* deleteAtFront(Plant *head) {
    if (!head) {
        cout << "Nursery is empty\n";
        return nullptr;
    }

    Plant *temp = head;
    head = head->next;
    if (head) head->prev = nullptr;

    cout << "Deleted plant: " << temp->name << endl;
    delete temp;
    return head;
}

// Delete at end
Plant* deleteAtEnd(Plant *head) {
    if (!head) {
        cout << "Nursery is empty\n";
        return nullptr;
    }

    if (!head->next) {
        cout << "Deleted plant: " << head->name << endl;
        delete head;
        return nullptr;
    }

    Plant *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->prev->next = nullptr;
    cout << "Deleted plant: " << temp->name << endl;
    delete temp;
    return head;
}

// Count plants
int countPlants(Plant *head) {
    int count = 0;
    Plant *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    cout << "Total plants in nursery: " << count << endl;
    return count;
}

// Insert in between
Plant* insertInBetween(Plant *head) {
    int pos;
    cout << "Enter position to insert plant: ";
    cin >> pos;

    if (pos < 1 || pos > countPlants(head) + 1) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return insertAtFront(head);
    if (pos == countPlants(head) + 1) return insertAtEnd(head);

    Plant *ptr = new Plant();
    cout << "Enter plant name, age (days), and height (cm): ";
    cin >> ptr->name >> ptr->age >> ptr->height;

    Plant *temp = head;
    for (int i = 1; i < pos - 1; ++i)
        temp = temp->next;

    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;

    return head;
}

// Delete in between
Plant* deleteInBetween(Plant *head) {
    int pos;
    cout << "Enter position to delete plant: ";
    cin >> pos;

    if (pos < 1 || pos > countPlants(head)) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return deleteAtFront(head);
    if (pos == countPlants(head)) return deleteAtEnd(head);

    Plant *temp = head;
    for (int i = 1; i < pos; ++i)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    cout << "Deleted plant: " << temp->name << endl;
    delete temp;

    return head;
}
