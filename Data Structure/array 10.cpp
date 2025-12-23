#include <iostream>
using namespace std;

// Structure to store gym member information
struct Member {
    string name;
    int age;
    string fitnessGoal;
};

int main() {
    int n;

    // Number of gym members
    cout << "Enter the number of gym members: ";
    cin >> n;

    // Array of structures to store member details
    Member members[n];

    // Input member details
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for member " << i + 1 << endl;
        cout << "Name: ";
        cin >> members[i].name;
        cout << "Age: ";
        cin >> members[i].age;
        cout << "Fitness Goal (WeightLoss/MuscleGain/Fitness): ";
        cin >> members[i].fitnessGoal;
    }

    // Display member information
    cout << "\nGym Member Records:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nMember " << i + 1 << " Details:" << endl;
        cout << "Name: " << members[i].name << endl;
        cout << "Age: " << members[i].age << endl;
        cout << "Fitness Goal: " << members[i].fitnessGoal << endl;
    }

    return 0;
}
