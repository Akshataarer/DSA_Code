#include <iostream>
using namespace std;

// Define a structure to store plant information
struct Plant {
    string plantName;
    int age;            // Age of plant in days
    float height;       // Height of plant in cm
};

int main() {
    int n;

    // Ask the user for the number of plants
    cout << "Enter the number of plants in the nursery: ";
    cin >> n;

    // Declare an array of structures
    Plant plants[n];

    // Input plant details
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Plant " << i + 1 << endl;
        cout << "Plant Name: ";
        cin >> plants[i].plantName;
        cout << "Plant Age (in days): ";
        cin >> plants[i].age;
        cout << "Plant Height (in cm): ";
        cin >> plants[i].height;
    }

    // Output plant details
    cout << "\nPlant Nursery Information:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nPlant " << i + 1 << ":" << endl;
        cout << "Name: " << plants[i].plantName << endl;
        cout << "Age: " << plants[i].age << " days" << endl;
        cout << "Height: " << plants[i].height << " cm" << endl;
    }

    return 0;
}
