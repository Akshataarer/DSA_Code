#include <iostream>
using namespace std;

// Structure to store gym member information
struct Member {
    char name[30];
    int age;
    int membershipDuration; // in months
    Member *next;
    Member *prev;
};

// Function prototypes
void displayMembers(Member *head);
Member* insertAtFront(Member *head);
Member* insertAtEnd(Member *head);
Member* deleteAtFront(Member *head);
Member* deleteAtEnd(Member *head);
Member* insertInBetween(Member *head);
Member* deleteInBetween(Member *head);
int countMembers(Member *head);

int main() {
    Member *head = nullptr;
    int choice;

    while (true) {
        cout << "\nSmart Gym Member Menu:\n";
        cout << "1. Display all members\n";
        cout << "2. Add member at front\n";
        cout << "3. Exit\n";
        cout << "4. Add member at end\n";
        cout << "5. Remove member at front\n";
        cout << "6. Remove member at end\n";
        cout << "7. Count members\n";
        cout << "8. Remove member in between\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayMembers(head); break;
            case 2: head = insertAtFront(head); break;
            case 3: exit(0);
            case 4: head = insertAtEnd(head); break;
            case 5: head = deleteAtFront(head); break;
            case 6: head = deleteAtEnd(head); break;
            case 7: countMembers(head); break;
            case 8: head = deleteInBetween(head); break;
            default: cout << "Invalid choice\n"; break;
        }
    }
    return 0;
}

// Display all gym members
void displayMembers(Member *head) {
    if (!head) {
        cout << "No members registered in the gym\n";
        return;
    }
    Member *temp = head;
    while (temp) {
        cout << "Name: " << temp->name
             << " | Age: " << temp->age
             << " | Membership Duration: "
             << temp->membershipDuration << " months\n";
        temp = temp->next;
    }
}

// Insert member at front
Member* insertAtFront(Member *head) {
    Member *ptr = new Member();
    cout << "Enter member name, age, membership duration (months): ";
    cin >> ptr->name >> ptr->age >> ptr->membershipDuration;

    ptr->prev = nullptr;
    ptr->next = head;

    if (head)
        head->prev = ptr;

    return ptr;
}

// Insert member at end
Member* insertAtEnd(Member *head) {
    Member *ptr = new Member();
    cout << "Enter member name, age, membership duration (months): ";
    cin >> ptr->name >> ptr->age >> ptr->membershipDuration;

    ptr->next = nullptr;

    if (!head) {
        ptr->prev = nullptr;
        return ptr;
    }

    Member *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = ptr;
    ptr->prev = temp;
    return head;
}

// Delete member at front
Member* deleteAtFront(Member *head) {
    if (!head) {
        cout << "Gym member list is empty\n";
        return nullptr;
    }

    Member *temp = head;
    head = head->next;

    if (head)
        head->prev = nullptr;

    cout << "Removed member: " << temp->name << endl;
    delete temp;
    return head;
}

// Delete member at end
Member* deleteAtEnd(Member *head) {
    if (!head) {
        cout << "Gym member list is empty\n";
        return nullptr;
    }

    if (!head->next) {
        cout << "Removed member: " << head->name << endl;
        delete head;
        return nullptr;
    }

    Member *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->prev->next = nullptr;
    cout << "Removed member: " << temp->name << endl;
    delete temp;
    return head;
}

// Count members
int countMembers(Member *head) {
    int count = 0;
    Member *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    cout << "Total gym members: " << count << endl;
    return count;
}

// Insert member in between
Member* insertInBetween(Member *head) {
    int pos;
    cout << "Enter position to insert member: ";
    cin >> pos;

    if (pos < 1 || pos > countMembers(head) + 1) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return insertAtFront(head);
    if (pos == countMembers(head) + 1) return insertAtEnd(head);

    Member *ptr = new Member();
    cout << "Enter member name, age, membership duration (months): ";
    cin >> ptr->name >> ptr->age >> ptr->membershipDuration;

    Member *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;

    return head;
}

// Delete member in between
Member* deleteInBetween(Member *head) {
    int pos;
    cout << "Enter position to delete member: ";
    cin >> pos;

    if (pos < 1 || pos > countMembers(head)) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) return deleteAtFront(head);
    if (pos == countMembers(head)) return deleteAtEnd(head);

    Member *temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    cout << "Removed member: " << temp->name << endl;
    delete temp;
    return head;
}
