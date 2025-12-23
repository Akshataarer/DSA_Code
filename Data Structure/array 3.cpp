#include <iostream>
using namespace std;

// Structure to store mushroom cultivation data
struct MushroomChamber {
    int chamberID;
    float temperature;
    float humidity;
    float moisture;
};

int main() {
    int n;

    // Number of mushroom growing chambers
    cout << "Enter the number of mushroom chambers: ";
    cin >> n;

    // Array of structures
    MushroomChamber chambers[n];

    // Input environmental data for each chamber
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Chamber " << i + 1 << endl;

        cout << "Chamber ID: ";
        cin >> chambers[i].chamberID;

        cout << "Temperature (°C): ";
        cin >> chambers[i].temperature;

        cout << "Humidity (%): ";
        cin >> chambers[i].humidity;

        cout << "Moisture Level (%): ";
        cin >> chambers[i].moisture;
    }

    // Display stored data
    cout << "\nMushroom Cultivation Environmental Data:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nChamber " << i + 1 << " Details:\n";
        cout << "Chamber ID: " << chambers[i].chamberID << endl;
        cout << "Temperature: " << chambers[i].temperature << " °C" << endl;
        cout << "Humidity: " << chambers[i].humidity << " %" << endl;
        cout << "Moisture Level: " << chambers[i].moisture << " %" << endl;
    }

    return 0;
}
