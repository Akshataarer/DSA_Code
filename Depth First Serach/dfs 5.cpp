#include <iostream>
using namespace std;

int totalSpaces = 5;

// Adjacency matrix representing connectivity between floors/workspaces
// 1 indicates direct access for inspection or monitoring
int layout[10][10] = {
    {0,1,1,0,0},   // Floor 0 connected to Workspaces 1 and 2
    {1,0,0,1,1},   // Workspace 1 connected to 0, 3, 4
    {1,0,0,0,1},   // Workspace 2 connected to 0 and 4
    {0,1,0,0,0},   // Room 3 connected to Workspace 1
    {0,1,1,0,0}    // Room 4 connected to Workspaces 1 and 2
};

int visited[10];

// DFS used for detailed inspection of connected workspaces
void dfs(int layout[10][10], int totalSpaces, int startSpace) {
    visited[startSpace] = 1;

    for (int i = 0; i < totalSpaces; i++) {
        if (layout[startSpace][i] == 1 && visited[i] == 0) {
            cout << i << "\t";
            dfs(layout, totalSpaces, i);
        }
    }
}

int main() {
    int startSpace;

    // Initialize all spaces as unvisited
    for (int i = 0; i < totalSpaces; i++)
        visited[i] = 0;

    cout << "Enter the starting floor/workspace ID: ";
    cin >> startSpace;

    cout << "DFS Traversal (Detailed Workspace Inspection Order):\n";
    cout << startSpace << "\t";
    dfs(layout, totalSpaces, startSpace);

    return 0;
}
