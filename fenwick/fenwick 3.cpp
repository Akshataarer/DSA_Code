#include <iostream>
using namespace std;

const int MAX = 20;

// n = number of days / chambers
int n;

// Stores daily mushroom temperature / yield data
int data[MAX];

// Fenwick Tree array
int BIT[MAX];

class FenwickTree
{
public:
    FenwickTree(int n);
    void build();
    void update(int day, int value);
    int query(int day);
    int total();
};

// Constructor
FenwickTree::FenwickTree(int n)
{
    for (int i = 0; i <= n; i++)
        BIT[i] = 0;
}

// Build Fenwick Tree with daily data
void FenwickTree::build()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter data for day " << i << ": ";
        cin >> data[i];
        update(i, data[i]);
    }
}

// Update data for a specific day
void FenwickTree::update(int day, int value)
{
    for (; day <= n; day += day & -day)
        BIT[day] += value;
}

// Query sum from day 1 to given day
int FenwickTree::query(int day)
{
    int sum = 0;
    while (day > 0)
    {
        sum += BIT[day];
        day -= day & -day;
    }
    return sum;
}

// Total data across all days
int FenwickTree::total()
{
    return query(n);
}

int main()
{
    cout << "Enter number of days in mushroom cultivation: ";
    cin >> n;

    FenwickTree ft(n);

    cout << "\nEnter daily mushroom temperature/yield data:\n";
    ft.build();

    cout << "\nTotal value over all days: " << ft.total() << endl;

    return 0;
}
