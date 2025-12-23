#include <iostream>
using namespace std;
#define MAX 1000

// Queue class to manage booking requests
class BookingQueue {
    int front, rear, size;
    int bookings[MAX];  // Stores booking request IDs

public:
    BookingQueue() {
        front = size = 0;
        rear = MAX - 1;
    }

    bool isFull() {
        return (size == MAX);
    }

    bool isEmpty() {
        return (size == 0);
    }

    // Add a booking request to the queue
    void enqueue(int requestID) {
        if (isFull()) {
            cout << "Booking queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        bookings[rear] = requestID;
        size++;
        cout << "Booking request " << requestID << " added to the queue." << endl;
    }

    // Process a booking request from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Booking queue is empty!" << endl;
            return -1;
        }
        int requestID = bookings[front];
        front = (front + 1) % MAX;
        size--;
        return requestID;
    }

    // Display current booking requests in the queue
    void printQueue() {
        if (isEmpty()) {
            cout << "No pending booking requests!" << endl;
            return;
        }
        cout << "Current booking queue: ";
        for (int i = front, count = 0; count < size; count++) {
            cout << bookings[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    BookingQueue bookingQueue;
    int choice, requestID;

    while (true) {
        cout << "\n--- Smart Co-Working Centre Booking Menu ---\n";
        cout << "1. Add Booking Request\n";
        cout << "2. Process Booking Request\n";
        cout << "3. Show Pending Bookings\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Booking Request ID: ";
                cin >> requestID;
                bookingQueue.enqueue(requestID);
                break;
            case 2:
                requestID = bookingQueue.dequeue();
                if (requestID != -1) {
                    cout << "Processed Booking Request ID: " << requestID << endl;
                }
                break;
            case 3:
                bookingQueue.printQueue();
                break;
            case 4:
                cout << "Exiting booking system...\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
