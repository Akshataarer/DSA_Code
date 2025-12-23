#include <iostream>
using namespace std;

// Structure to store resident information
struct Resident {
    int flatNumber;
    string ownerName;
    long long contactNumber;
};

int main() {
    int n;

    // Number of residents
    cout << "Enter the number of residents: ";
    cin >> n;

    // Array of structures (Array/List concept)
    Resident residents[n];

    // Input resident details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Resident " << i + 1 << endl;
        cout << "Flat Number: ";
        cin >> residents[i].flatNumber;
        cout << "Owner Name: ";
        cin >> residents[i].ownerName;
        cout << "Contact Number: ";
        cin >> residents[i].contactNumber;
    }

    // Display resident information
    cout << "\nResident Information:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nResident " << i + 1 << endl;
        cout << "Flat Number: " << residents[i].flatNumber << endl;
        cout << "Owner Name: " << residents[i].ownerName << endl;
        cout << "Contact Number: " << residents[i].contactNumber << endl;
    }

    return 0;
}
