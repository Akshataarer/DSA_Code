#include <iostream>
using namespace std;

#define MAXN 100
#define INF 999

int main() {

    int sheds;
    cout << "Enter the number of cattle sheds / milk collection points\n";
    cin >> sheds;

    int distance[MAXN][MAXN];

    cout << "Enter the distance matrix between sheds (Enter 999 for no direct path)\n";
    for (int i = 0; i < sheds; i++) {
        for (int j = 0; j < sheds; j++) {
            cin >> distance[i][j];
        }
    }

    int collectionCenter;
    cout << "Enter the milk collection center (source shed index)\n";
    cin >> collectionCenter;

    int minDist[MAXN], path[MAXN], visited[MAXN];

    // Initialization
    for (int i = 0; i < sheds; i++) {
        minDist[i] = distance[collectionCenter][i];
        path[i] = collectionCenter;
        visited[i] = 0;
    }
    visited[collectionCenter] = 1;

    // Dijkstra’s Algorithm
    for (int iter = 0; iter < sheds - 1; iter++) {
        int u = -1;
        int min = INF + 1;

        for (int i = 0; i < sheds; i++) {
            if (!visited[i] && minDist[i] < min) {
                min = minDist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < sheds; v++) {
            if (!visited[v] && distance[u][v] != INF) {
                if (minDist[u] + distance[u][v] < minDist[v]) {
                    minDist[v] = minDist[u] + distance[u][v];
                    path[v] = u;
                }
            }
        }
    }

    cout << "\nShed   Min Distance   Previous Shed\n";
    for (int i = 0; i < sheds; i++) {
        cout << i << "        " << minDist[i] << "              " << path[i] << "\n";
    }

    return 0;
}

