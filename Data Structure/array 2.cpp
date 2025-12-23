#include <iostream>
using namespace std;

// Structure to store Beehive information
struct Beehive {
    int hiveID;          // Unique ID for each hive
    float healthLevel;   // Health percentage of the hive
    float honeyYield;    // Honey produced (in kg)
};

int main() {
    int n;

    // Ask the user for number of beehives
    cout << "Enter the number of beehives: ";
    cin >> n;

    // Array of structures to store beehive data
    Beehive hives[n];

    // Input beehive details
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Beehive " << i + 1 << endl;

        cout << "Hive ID: ";
        cin >> hives[i].hiveID;

        cout << "Health Level (%): ";
        cin >> hives[i].healthLevel;

        cout << "Honey Yield (kg): ";
        cin >> hives[i].honeyYield;
    }

    // Display beehive information
    cout << "\n--- Beehive Monitoring Report ---\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nBeehive " << i + 1 << endl;
        cout << "Hive ID: " << hives[i].hiveID << endl;
        cout << "Health Level: " << hives[i].healthLevel << "%" << endl;
        cout << "Honey Yield: " << hives[i].honeyYield << " kg" << endl;
    }

    return 0;
}
