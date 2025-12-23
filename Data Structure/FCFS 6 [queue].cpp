#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// Queue for Food Street orders (FCFS principle)
class FoodOrderQueue {
    int front, rear, size;
    string orders[MAX];

public:
    FoodOrderQueue() {
        front = size = 0;
        rear = MAX - 1;
    }

    bool isFull() {
        return (size == MAX);
    }

    bool isEmpty() {
        return (size == 0);
    }

    // Enqueue new food order (First Come)
    void enqueue(string order) {
        if (isFull()) {
            cout << "Order queue is full! Please wait.\n";
            return;
        }
        rear = (rear + 1) % MAX;
        orders[rear] = order;
        size++;
        cout << "Order \"" << order << "\" added to the queue.\n";
    }

    // Dequeue food order (First Serve)
    string dequeue() {
        if (isEmpty()) {
            cout << "No pending orders!\n";
            return "";
        }
        string order = orders[front];
        front = (front + 1) % MAX;
        size--;
        return order;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No pending food orders.\n";
            return;
        }
        cout << "Pending Food Orders (FCFS): ";
        for (int i = front, count = 0; count < size; count++) {
            cout << "\"" << orders[i] << "\" ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    FoodOrderQueue foodQueue;
    int choice;
    string order;

    while (true) {
        cout << "\n=== Smart Food Street Order Management (FCFS) ===\n";
        cout << "1. Place new food order\n";
        cout << "2. Serve food order\n";
        cout << "3. Show pending orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter food order: ";
            getline(cin, order);
            foodQueue.enqueue(order);
            break;

        case 2:
            order = foodQueue.dequeue();
            if (!order.empty()) {
                cout << "Serving order: \"" << order << "\"\n";
            }
            break;

        case 3:
            foodQueue.displayQueue();
            break;

        case 4:
            cout << "Exiting system...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
