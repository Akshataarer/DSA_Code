#include <iostream>
using namespace std;

#define MAX 100

class NurserySegmentTree
{
public:
    int size;
    int tree[MAX * 4];   // Stores total growth
    int lazy[MAX * 4];   // Lazy propagation array

    NurserySegmentTree(int n, int arr[]);
    void build(int index, int low, int high, int arr[]);
    void propagate(int index, int low, int high);
    void updateGrowth(int index, int low, int high, int l, int r, int value);
    void displayGrowth(int index, int low, int high);
};

// Constructor
NurserySegmentTree::NurserySegmentTree(int n, int arr[])
{
    size = n;
    for (int i = 0; i < MAX * 4; i++)
    {
        tree[i] = 0;
        lazy[i] = 0;
    }
    build(0, 0, n - 1, arr);
}

// Build Segment Tree
void NurserySegmentTree::build(int index, int low, int high, int arr[])
{
    if (low == high)
        tree[index] = arr[low];
    else
    {
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
}

// Lazy propagation
void NurserySegmentTree::propagate(int index, int low, int high)
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

// Update growth for a range of plants
void NurserySegmentTree::updateGrowth(int index, int low, int high, int l, int r, int value)
{
    propagate(index, low, high);

    if (low > r || high < l)
        return;

    if (low >= l && high <= r)
    {
        tree[index] += (high - low + 1) * value;
        if (low != high)
        {
            lazy[2 * index + 1] += value;
            lazy[2 * index + 2] += value;
        }
        return;
    }

    int mid = (low + high) / 2;
    updateGrowth(2 * index + 1, low, mid, l, r, value);
    updateGrowth(2 * index + 2, mid + 1, high, l, r, value);
    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

// Display growth of all plants
void NurserySegmentTree::displayGrowth(int index, int low, int high)
{
    propagate(index, low, high);

    if (low == high)
    {
        cout << "Plant " << low + 1 << " Growth: "
             << tree[index] << " cm" << endl;
        return;
    }

    int mid = (low + high) / 2;
    displayGrowth(2 * index + 1, low, mid);
    displayGrowth(2 * index + 2, mid + 1, high);
}

int main()
{
    // Initial growth (cm) of plants
    int plantGrowth[MAX] = {15, 20, 18, 25, 17, 22, 16, 19, 21, 23};
    int n = 10;

    NurserySegmentTree nursery(n, plantGrowth);

    int q;
    cout << "Enter the number of operations: ";
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int choice;
        cout << "\n1. Apply water/fertilizer (range update)\n";
        cout << "2. Display plant growth\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int l, r, value;
            cout << "Enter plant range (l r) and growth increase: ";
            cin >> l >> r >> value;
            nursery.updateGrowth(0, 0, n - 1, l - 1, r - 1, value);
            cout << "Growth updated successfully.\n";
        }
        else if (choice == 2)
        {
            nursery.displayGrowth(0, 0, n - 1);
        }
    }

    return 0;
}
