#include <iostream>
using namespace std;

const int MAX = 20;

// n = number of days
int n;

// Stores daily visitor count / revenue
int data[MAX];

// Fenwick Tree array
int BIT[MAX];

class FenwickTree {
public:
    FenwickTree(int n);
    void build();
    void update(int day, int value);
    int query(int day);
    int total();
};

// Constructor
FenwickTree::FenwickTree(int n) {
    for (int i = 0; i <= n; i++)
        BIT[i] = 0;
}

// Build Fenwick Tree with daily visitor/revenue data
void FenwickTree::build() {
    for (int i = 1; i <= n; i++) {
        cout << "Enter visitor count for day " << i << ": ";
        cin >> data[i];
        update(i, data[i]);
    }
}

// Update visitor count for a specific day
void FenwickTree::update(int day, int value) {
    for (; day <= n; day += day & -day)
        BIT[day] += value;
}

// Query total visitors from day 1 to given day
int FenwickTree::query(int day) {
    int sum = 0;
    while (day > 0) {
        sum += BIT[day];
        day -= day & -day;
    }
    return sum;
}

// Total visitors over all days
int FenwickTree::total() {
    return query(n);
}

int main() {
    cout << "Enter number of days for Adventure Park operation: ";
    cin >> n;

    FenwickTree ft(n);

    cout << "\nEnter daily visitor count:\n";
    ft.build();

    cout << "\nTotal visitors over all days: " << ft.total() << endl;

    return 0;
}
