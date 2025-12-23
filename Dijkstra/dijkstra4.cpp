#include <iostream>
using namespace std;

#define MAXN 100
#define INF 999

int main() {

    int locations;
    cout << "Enter the number of delivery locations:\n";
    cin >> locations;

    int distance[MAXN][MAXN];

    cout << "Enter the distance matrix between locations (Enter 999 for no direct road):\n";
    for (int i = 0; i < locations; i++) {
        for (int j = 0; j < locations; j++) {
            cin >> distance[i][j];
        }
    }

    int cafe;
    cout << "Enter the Café location (source index):\n";
    cin >> cafe;

    int minDist[MAXN], previous[MAXN], visited[MAXN];

    // Initialization
    for (int i = 0; i < locations; i++) {
        minDist[i] = distance[cafe][i];
        previous[i] = cafe;
        visited[i] = 0;
    }
    visited[cafe] = 1;

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
                    previous[v] = u;
                }
            }
        }
    }

    cout << "\nLocation   Shortest Distance   Previous Location\n";
    for (int i = 0; i < locations; i++) {
        cout << i << "              "
             << minDist[i] << "                 "
             << previous[i] << "\n";
    }

    return 0;
}


