#include <iostream>
using namespace std;

const int MAX = 20;

int n, plantGrowth[MAX], BIT[MAX];

// Fenwick Tree class for plant growth tracking
class FenwickTree
{
public:
    FenwickTree(int n);
    void build();
    void update(int index, int growth);
    int query(int index);
    int totalGrowth();
};

// Constructor initializes BIT
FenwickTree::FenwickTree(int n)
{
    for (int i = 0; i <= n; i++)
        BIT[i] = 0;
}

// Build Fenwick Tree with initial plant growth values
void FenwickTree::build()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter growth (cm) for Plant " << i << ": ";
        cin >> plantGrowth[i];
        update(i, plantGrowth[i]);
    }
}

// Update growth of a specific plant
void FenwickTree::update(int index, int growth)
{
    for (; index <= n; index += index & -index)
        BIT[index] += growth;
}

// Query total growth up to a specific plant
int FenwickTree::query(int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}

// Query total growth of all plants
int FenwickTree::totalGrowth()
{
    return query(n);
}

int main()
{
    cout << "Enter number of plants in the nursery: ";
    cin >> n;

    FenwickTree nurseryGrowth(n);

    cout << "\nEnter initial growth data:\n";
    nurseryGrowth.build();

    cout << "\nTotal growth of all plants: "
         << nurseryGrowth.totalGrowth() << " cm" << endl;

    return 0;
}
