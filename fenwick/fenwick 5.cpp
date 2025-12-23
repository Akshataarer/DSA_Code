#include <iostream>
using namespace std;

const int MAX = 20;

// n = number of days / time slots
int n, usageData[MAX], BIT[MAX];

// Fenwick Tree class for usage tracking
class UsageFenwickTree
{
public:
    UsageFenwickTree(int n);
    void buildUsageData();
    void updateUsage(int day, int usage);
    int queryUsage(int day);
    int totalUsage();
};

// Constructor: initialize BIT
UsageFenwickTree::UsageFenwickTree(int n)
{
    for (int i = 0; i <= n; i++)
        BIT[i] = 0;
}

// Build attendance / usage data
void UsageFenwickTree::buildUsageData()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> usageData[i];      // usage on day i
        updateUsage(i, usageData[i]);
    }
}

// Update usage when new attendance is recorded
void UsageFenwickTree::updateUsage(int day, int usage)
{
    for (; day <= n; day += day & -day)
        BIT[day] += usage;
}

// Query cumulative usage till a given day
int UsageFenwickTree::queryUsage(int day)
{
    int sum = 0;
    while (day > 0)
    {
        sum += BIT[day];
        day -= day & -day;
    }
    return sum;
}

// Total usage across all days
int UsageFenwickTree::totalUsage()
{
    return queryUsage(n);
}

int main()
{
    cout << "Enter number of days for usage tracking: ";
    cin >> n;

    UsageFenwickTree usageTracker(n);

    cout << "Enter daily attendance / workspace usage:\n";
    usageTracker.buildUsageData();

    cout << "Total workspace usage is: "
         << usageTracker.totalUsage() << endl;

    return 0;
}
