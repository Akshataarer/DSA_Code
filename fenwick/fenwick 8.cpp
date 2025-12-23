#include <iostream>
using namespace std;

const int MAX = 20;

int totalPlayers, performance[MAX], BIT[MAX];

// Fenwick Tree class for tracking player performance
class FenwickTree
{
public:
    FenwickTree(int n);
    void build();
    void update(int index, int value);
    int query(int index);
    int totalPerformance();
};

// Constructor to initialize BIT
FenwickTree::FenwickTree(int n)
{
    for (int i = 0; i <= n; i++)
        BIT[i] = 0;
}

// Build Fenwick Tree using player performance scores
void FenwickTree::build()
{
    for (int i = 1; i <= totalPlayers; i++)
    {
        cout << "Enter performance score for player " << i << ": ";
        cin >> performance[i];
        update(i, performance[i]);
    }
}

// Update performance score of a player
void FenwickTree::update(int index, int value)
{
    for (; index <= totalPlayers; index += index & -index)
        BIT[index] += value;
}

// Query cumulative performance up to a given player
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

// Total performance of all players
int FenwickTree::totalPerformance()
{
    return query(totalPlayers);
}

int main()
{
    cout << "Enter number of players: ";
    cin >> totalPlayers;

    FenwickTree academy(totalPlayers);

    cout << "\nPlayer Performance Entry:\n";
    academy.build();

    cout << "\nTotal Performance Score of Academy: "
         << academy.totalPerformance() << endl;

    return 0;
}
