#include <iostream>
using namespace std;

int totalNodes = 5;

// Adjacency matrix representing apartment layout
// 1 indicates direct connectivity for inspection
// Example: buildings, floors, or flats
int apartment[10][10] = {
    {0,1,1,0,0},  // 0 = Apartment Complex
    {1,0,0,1,1},  // 1 = Building 1
    {1,0,0,0,1},  // 2 = Building 2
    {0,1,0,0,0},  // 3 = Floor 1 (Building 1)
    {0,1,1,0,0}   // 4 = Floor 2 (Building 1 / link)
};

int visited[10];

// DFS for detailed apartment inspection
void dfsApartment(int apartment[10][10], int totalNodes, int sourceNode) {
    visited[sourceNode] = 1;

    for (int i = 0; i < totalNodes; i++) {
        if (apartment[sourceNode][i] == 1 && visited[i] == 0) {
            cout << i << "\t";
            dfsApartment(apartment, totalNodes, i);
        }
    }
}

int main() {
    int sourceNode;

    // Initialize visited array
    for (int i = 0; i < totalNodes; i++)
        visited[i] = 0;

    cout << "Enter the starting node for apartment inspection: ";
    cin >> sourceNode;

    cout << "DFS Traversal (Detailed Apartment Inspection Order):\n";
    cout << sourceNode << "\t";
    dfsApartment(apartment, totalNodes, sourceNode);

    return 0;
}
