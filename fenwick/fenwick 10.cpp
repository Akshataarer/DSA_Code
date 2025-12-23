#include <iostream>
using namespace std;

const int MAX = 20;

int days, workout[MAX], BIT[MAX];

// Fenwick Tree class for fitness progress tracking
class FenwickTree {
public:
    FenwickTree(int days);
    void build();
    void update(int day, int calories);
    int query(int day);
    int totalCalories();
};

FenwickTree::FenwickTree(int days) {
    for (int i = 0; i <= days; i++)
        BIT[i] = 0;
}

// Build Fenwick Tree using daily workout calories
void FenwickTree::build() {
    for (int i = 1; i <= days; i++) {
        cout << "Enter calories burned on day " << i << ": ";
        cin >> workout[i];
        update(i, workout[i]);
    }
}

// Update calories burned on a particular day
void FenwickTree::update(int day, int calories) {
    for (; day <= days; day += day & -day)
        BIT[day] += calories;
}

// Get total calories burned up to a specific day
int FenwickTree::query(int day) {
    int sum = 0;
    while (day > 0) {
        sum += BIT[day];
        day -= day & -day;
    }
    return sum;
}

// Get total calories burned over all days
int FenwickTree::totalCalories() {
    return query(days);
}

int main() {
    cout << "Enter number of days to track workout progress: ";
    cin >> days;

    FenwickTree fenwickTree(days);

    cout << "\nEnter daily workout calorie data:\n";
    fenwickTree.build();

    cout << "\nTotal calories burned over " << days
         << " days: " << fenwickTree.totalCalories() << endl;

    return 0;
}

