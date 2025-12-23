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

    int sourceSport;
    cout << "Enter the starting sport/player node: ";
    cin >> sourceSport;

    int dist[MAXN], path[MAXN], visited[MAXN];

    // Initialize distances, paths, and visited array
    for (int i = 0; i < totalNodes; i++) {
        dist[i] = trainingCost[sourceSport][i];
        path[i] = sourceSport;
        visited[i] = 0;
    }
    visited[sourceSport] = 1;

    // Dijkstra’s algorithm
    for (int iter = 0; iter < totalNodes - 1; iter++) {
        int u = -1;
        int minDist = INF + 1;

        // Select the unvisited node with minimum distance
        for (int i = 0; i < totalNodes; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances for neighboring nodes
        for (int v = 0; v < totalNodes; v++) {
            if (!visited[v] && trainingCost[u][v] != INF) {
                if (dist[u] + trainingCost[u][v] < dist[v]) {
                    dist[v] = dist[u] + trainingCost[u][v];
                    path[v] = u;
                }
            }
        }
    }

    cout << "\nSport/Player   MinTrainingCost   PreviousNode\n";
    for (int i = 0; i < totalNodes; i++) {
        cout << i << "               " << dist[i] << "                 " << path[i] << "\n";
    }

    return 0;
}
