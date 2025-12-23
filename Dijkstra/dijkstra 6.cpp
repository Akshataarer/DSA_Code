#include <iostream>
using namespace std;

#define MAXN 100
#define INF 999

int main() {

    int locations;
    cout << "Enter number of locations in the Adventure Park (rides / food stalls / exits):\n";
    cin >> locations;

    int distance[MAXN][MAXN];

    cout << "Enter the distance matrix (Enter 999 if no direct path exists):\n";
    for (int i = 0; i < locations; i++) {
        for (int j = 0; j < locations; j++) {
            cin >> distance[i][j];
        }
    }

    int entrance;
    cout << "Enter the entrance location (source node index):\n";
    cin >> entrance;

    int minDist[MAXN], parent[MAXN], visited[MAXN];

    // Initialization
    for (int i = 0; i < locations; i++) {
        minDist[i] = distance[entrance][i];
        parent[i] = entrance;
        visited[i] = 0;
    }
    visited[entrance] = 1;

    // Dijkstra’s Algorithm
    for (int iter = 0; iter < locations - 1; iter++) {
        int u = -1;
        int min = INF + 1;

        for (int i = 0; i < locations; i++) {
            if (!visited[i] && minDist[i] < min) {
                min = minDist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < locations; v++) {
            if (!visited[v] && distance[u][v] != INF) {
                if (minDist[u] + distance[u][v] < minDist[v]) {
                    minDist[v] = minDist[u] + distance[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    cout << "\nLocation   Shortest Distance from Entrance   Previous Location\n";
    for (int i = 0; i < locations; i++) {
        cout << i << "              " << minDist[i]
             << "                        " << parent[i] << "\n";
    }

    return 0;
}
