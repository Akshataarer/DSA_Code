#include <iostream>
#include <string>
using namespace std;
#define MAX 100

class OrderQueue {
    int front, rear, size;
    string orders[MAX];

public:
    OrderQueue() {
        front = size = 0;
        rear = MAX - 1;
    }

    bool isFull() {
        return (size == MAX);
    }

    bool isEmpty() {
        return (size == 0);
    }

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

    string dequeue() {
        if (isEmpty()) {
            cout << "No orders to process!\n";
            return "";
        }
        string order = orders[front];
        front = (front + 1) % MAX;
        size--;
        return order;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Current Orders in Queue: ";
        for (int i = front, count = 0; count < size; count++) {
            cout << "\"" << orders[i] << "\" ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    OrderQueue q;
    int choice;
    string order;

    while (true) {
        cout << "\n=== Café & Mini Mart Order Menu ===\n";
        cout << "1. Add new order\n";
        cout << "2. Process order\n";
        cout << "3. Show pending orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                cout << "Enter order description: ";
                getline(cin, order);
                q.enqueue(order);
                break;
            case 2:
                order = q.dequeue();
                if (!order.empty()) {
                    cout << "Processing order: \"" << order << "\"\n";
                }
                break;
            case 3:
                q.printQueue();
                break;
            case 4:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
