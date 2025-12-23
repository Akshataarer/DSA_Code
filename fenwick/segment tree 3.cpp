#include <iostream>
using namespace std;

#define MAX 100

// Segment Tree class for Mushroom Yield Management
class MushroomSegTree
{
public:
    int size;
    int tree[MAX * 4];   // Stores total yield
    int lazy[MAX * 4];   // Lazy propagation array

    MushroomSegTree(int n, int yield[]);
    void build(int index, int low, int high, int yield[]);
    void propagate(int index, int low, int high);
    void updateRange(int index, int low, int high, int l, int r, int val);
    void display(int index, int low, int high);
};

// Constructor
MushroomSegTree::MushroomSegTree(int n, int yield[])
{
    size = n;
    for (int i = 0; i < MAX * 4; i++)
    {
        tree[i] = 0;
        lazy[i] = 0;
    }
    build(0, 0, n - 1, yield);
}

// Build segment tree
void MushroomSegTree::build(int index, int low, int high, int yield[])
{
    if (low == high)
        tree[index] = yield[low];
    else
    {
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, yield);
        build(2 * index + 2, mid + 1, high, yield);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
}

// Propagate lazy updates
void MushroomSegTree::propagate(int index, int low, int high)
{
    if (lazy[index] != 0)
    {
        tree[index] += (high - low + 1) * lazy[index];

        if (low != high)
        {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
}

// Update yield in a range (environment improvement)
void MushroomSegTree::updateRange(int index, int low, int high, int l, int r, int val)
{
    propagate(index, low, high);

    if (low > r || high < l) return;

    if (low >= l && high <= r)
    {
        tree[index] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * index + 1] += val;
            lazy[2 * index + 2] += val;
        }
        return;
    }

    int mid = (low + high) / 2;
    updateRange(2 * index + 1, low, mid, l, r, val);
    updateRange(2 * index + 2, mid + 1, high, l, r, val);

    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

// Display yield for each day/chamber
void MushroomSegTree::display(int index, int low, int high)
{
    propagate(index, low, high);

    if (low == high)
    {
        cout << "Day/Chamber " << low + 1
             << " Mushroom Yield: " << tree[index] << " kg\n";
        return;
    }

    int mid = (low + high) / 2;
    display(2 * index + 1, low, mid);
    display(2 * index + 2, mid + 1, high);
}

int main()
{
    // Initial mushroom yield (kg) for 10 days / chambers
    int yield[MAX] = {15, 20, 18, 25, 17, 22, 16, 19, 21, 23};
    int n = 10;

    MushroomSegTree mst(n, yield);

    int q;
    cout << "Enter the number of operations: ";
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int choice;
        cout << "\n1. Improve environment (update range)";
        cout << "\n2. Display mushroom yield\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int l, r, val;
            cout << "Enter range (start end) and yield increase (kg): ";
            cin >> l >> r >> val;
            mst.updateRange(0, 0, n - 1, l - 1, r - 1, val);
            cout << "Environmental improvement applied successfully.\n";
        }
        else if (choice == 2)
        {
            mst.display(0, 0, n - 1);
        }
    }

    return 0;
}
