#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class MaintenanceQueue {
    int front, rear, size;
    string requests[MAX];

public:
    MaintenanceQueue() {
        front = size = 0;
        rear = MAX - 1;
    }

    bool isFull() {
        return (size == MAX);
    }

    bool isEmpty() {
        return (size == 0);
    }

    // Add new maintenance request
    void addRequest(string request) {
        if (isFull()) {
            cout << "Maintenance queue is full! Please wait.\n";
            return;
        }
        rear = (rear + 1) % MAX;
        requests[rear] = request;
        size++;
        cout << "Maintenance request added: \"" << request << "\"\n";
    }

    // Process maintenance request
    string processRequest() {
        if (isEmpty()) {
            cout << "No maintenance requests to process!\n";
            return "";
        }
        string request = requests[front];
        front = (front + 1) % MAX;
        size--;
        return request;
    }

    // Display pending requests
    void showRequests() {
        if (isEmpty()) {
            cout << "No pending maintenance requests.\n";
            return;
        }
        cout << "Pending Maintenance Requests:\n";
        for (int i = front, count = 0; count < size; count++) {
            cout << "- " << requests[i] << endl;
            i = (i + 1) % MAX;
        }
    }
};

int main() {
    MaintenanceQueue mq;
    int choice;
    string request;

    while (true) {
        cout << "\n=== Smart Apartment Maintenance Menu ===\n";
        cout << "1. Add maintenance request\n";
        cout << "2. Process maintenance request\n";
        cout << "3. View pending requests\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter maintenance issue (e.g., Plumbing, Electrical): ";
                getline(cin, request);
                mq.addRequest(request);
                break;

            case 2:
                request = mq.processRequest();
                if (!request.empty()) {
                    cout << "Processing maintenance request: \"" 
                         << request << "\"\n";
                }
                break;

            case 3:
                mq.showRequests();
                break;

            case 4:
                cout << "Exiting Apartment Maintenance System...\n";
                exit(0);

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
