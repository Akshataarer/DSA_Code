#include <iostream>
using namespace std;

const int MAX = 20;

int flats, usage[MAX], BIT[MAX];

// Fenwick Tree for Resource Monitoring
class FenwickTree {
public:
    FenwickTree(int n);
    void build();
    void update(int index, int units);
    int query(int index);
    int totalUsage();
};

// Constructor to initialize BIT
FenwickTree::FenwickTree(int n) {
    for (int i = 0; i <= n; i++)
        BIT[i] = 0;
}

// Build tree with electricity usage data
void FenwickTree::build() {
    for (int i = 1; i <= flats; i++) {
        cout << "Enter electricity usage for Flat " << i << ": ";
        cin >> usage[i];
        update(i, usage[i]);
    }
}

// Update electricity usage of a flat
void FenwickTree::update(int index, int units) {
    for (; index <= flats; index += index & -index)
        BIT[index] += units;
}

// Query total usage up to a flat
int FenwickTree::query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}

// Get total electricity usage of all flats
int FenwickTree::totalUsage() {
    return query(flats);
}

int main() {
    cout << "Enter number of flats in the apartment: ";
    cin >> flats;

    FenwickTree fenwickTree(flats);

    cout << "\nEnter monthly electricity usage (units):\n";
    fenwickTree.build();

    cout << "\nTotal electricity usage of apartment: "
         << fenwickTree.totalUsage() << " units" << endl;

    return 0;
}
