#include <iostream>
using namespace std;

#define MAXN 100
#define INF 999

int main() {
    int totalNodes; // total sports categories / players
    cout << "Enter the number of sports categories / players: ";
    cin >> totalNodes;

    int trainingCost[MAXN][MAXN];

    cout << "Enter the training cost matrix (use 999 for no direct connection):\n";
    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            cin >> trainingCost[i][j];
        }
    }

    int startNode;
    cout << "Enter the starting sport/player node for greedy scheduling: ";
    cin >> startNode;

    int dist[MAXN], parent[MAXN], visited[MAXN];

    for (int i = 0; i < totalNodes; i++) {
        dist[i] = trainingCost[startNode][i];
        parent[i] = startNode;
        visited[i] = 0;
    }

    dist[startNode] = 0;
    parent[startNode] = -1;  // root of MST
    visited[startNode] = 1;

    int totalPriority = 0;

    // Prim's algorithm to select minimum-cost training connections
    for (int iter = 0; iter < totalNodes - 1; iter++) {
        int u = -1;
        int minDist = INF + 1;

        // Select unvisited node with minimum training cost
        for (int i = 0; i < totalNodes; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;
        totalPriority += dist[u];

        // Update distances for neighboring nodes
        for (int v = 0; v < totalNodes; v++) {
            if (!visited[v] && trainingCost[u][v] != INF && trainingCost[u][v] < dist[v]) {
                dist[v] = trainingCost[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nSelected Training Connections (Greedy Scheduling):\n";
    cout << "Sport/Player u  -  v   :  Training Cost\n";
    for (int v = 0; v < totalNodes; v++) {
        if (parent[v] != -1) {
            cout << "      " << parent[v] << "  -  " << v
                 << "   :   " << dist[v] << "\n";
        }
    }

    cout << "Total Training Priority Cost = " << totalPriority << "\n";

    return 0;
}
