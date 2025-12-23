#include <iostream>
using namespace std;

// Structure to represent a training connection between players/sports
struct TrainingEdge {
    int sport1, sport2, priority; // priority = importance / weight
};

// Sort edges based on priority (ascending)
void bubbleSort(TrainingEdge edges[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].priority > edges[j + 1].priority) {
                TrainingEdge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Union function for disjoint sets
void Union(int parent[], int n, int u, int v) {
    int temp = parent[u];
    for (int i = 0; i < n; i++) {
        if (parent[i] == temp)
            parent[i] = parent[v];
    }
}

// Find function for disjoint sets
bool Find(int parent[], int u, int v) {
    return parent[u] == parent[v];
}

int main() {
    int totalSports, totalConnections;
    cout << "Enter number of sports/categories and training connections: ";
    cin >> totalSports >> totalConnections;

    TrainingEdge edges[100];

    cout << "Enter connections as: sport1 sport2 priority\n";
    for (int i = 0; i < totalConnections; i++) {
        cin >> edges[i].sport1 >> edges[i].sport2 >> edges[i].priority;
    }

    int parent[100];
    for (int i = 0; i < totalSports; i++)
        parent[i] = i;

    // Sort connections based on priority (lower = higher importance)
    bubbleSort(edges, totalConnections);

    int totalPriority = 0;

    cout << "\nTraining connections selected (Greedy Scheduling):\n";
    for (int i = 0; i < totalConnections; i++) {
        int u = edges[i].sport1;
        int v = edges[i].sport2;
        int w = edges[i].priority;

        if (!Find(parent, u, v)) {
            cout << "Train between Sport " << u << " and Sport " << v 
                 << " with priority " << w << "\n";
            totalPriority += w;
            Union(parent, totalSports, u, v);
        }
    }

    cout << "Total Training Priority = " << totalPriority << endl;

    return 0;
}
