#include <iostream>
using namespace std;

// Structure to store cow information
struct Cow {
    int cowID;
    int age;
    float milkProduced;   // liters per day
    float feedIntake;     // kg per day 
} ;

int main() {
    int n;

    // Number of cows in the dairy farm
    cout << "Enter the number of cows: ";
    cin >> n;

    // Array of cow records
    Cow cows[n];

    // Input cow details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Cow " << i + 1 << endl;
        cout << "Cow ID: ";
        cin >> cows[i].cowID;
        cout << "Age (years): ";
        cin >> cows[i].age;
        cout << "Milk Produced (liters): ";
        cin >> cows[i].milkProduced;
        cout << "Feed Intake (kg): ";
        cin >> cows[i].feedIntake;
    }

    // Display cow records
    cout << "\nCattle Records in Smart Dairy Farm:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nCow " << i + 1 << " Details:" << endl;
        cout << "Cow ID: " << cows[i].cowID << endl;
        cout << "Age: " << cows[i].age << " years" << endl;
        cout << "Milk Produced: " << cows[i].milkProduced << " liters" << endl;
        cout << "Feed Intake: " << cows[i].feedIntake << " kg" << endl;
    }

    return 0;
}
