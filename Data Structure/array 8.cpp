#include <iostream>
using namespace std;

// Structure to store player information
struct Player {
    string name;
    int age;
    string sport;
    float performanceScore;
};

int main() {
    int n;

    // Number of players in the academy
    cout << "Enter the number of players: ";
    cin >> n;

    // Array of player records (Array/List concept)
    Player players[n];

    // Input player details
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for player " << i + 1 << endl;

        cout << "Name: ";
        cin >> players[i].name;

        cout << "Age: ";
        cin >> players[i].age;

        cout << "Sport: ";
        cin >> players[i].sport;

        cout << "Performance Score: ";
        cin >> players[i].performanceScore;
    }

    // Display player details
    cout << "\nPlayer Information in Sports Training Academy:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nPlayer " << i + 1 << ":" << endl;
        cout << "Name: " << players[i].name << endl;
        cout << "Age: " << players[i].age << endl;
        cout << "Sport: " << players[i].sport << endl;
        cout << "Performance Score: " << players[i].performanceScore << endl;
    }

    return 0;
}
