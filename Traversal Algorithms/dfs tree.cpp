#include <iostream>
using namespace std;

int totalNodes = 5;

// Adjacency matrix representing academy structure
// Nodes represent sports categories and players
int academy[10][10] = {
    {0,1,1,0,0},
    {1,0,0,1,1},
    {1,0,0,0,1},
    {0,1,0,0,0},
    {0,1,1,0,0}
};

int visited[10];

// DFS traversal for detailed analysis of a sport
void dfs(int academy[10][10], int totalNodes, int sourceNode)
{
    visited[sourceNode] = 1;

    for (int i = 0; i < totalNodes; i++)
    {
        if (academy[sourceNode][i] == 1 && visited[i] == 0)
        {
            cout << i << "\t";
            dfs(academy, totalNodes, i);
        }
    }
}

int main()
{
    int sourceNode;

    // Initialize visited array
    for (int i = 0; i < totalNodes; i++)
        visited[i] = 0;

    cout << "Enter the starting sport/category node: ";
    cin >> sourceNode;

    cout << "\nDFS Traversal (Detailed Sport-wise Analysis):\n";
    cout << sourceNode << "\t";
    dfs(academy, totalNodes, sourceNode);

    return 0;
}
