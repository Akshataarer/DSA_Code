#include <iostream>
using namespace std;

int sections = 5;

// Adjacency matrix representing connectivity between gym sections
// 1 indicates direct access between workout areas
int gym[10][10] = {
    {0,1,1,0,0},  // Cardio connected to Weights & Functional
    {1,0,0,1,1},  // Weights connected to Cardio, Yoga, CrossFit
    {1,0,0,0,1},  // Functional connected to Cardio & CrossFit
    {0,1,0,0,0},  // Yoga connected to Weights
    {0,1,1,0,0}   // CrossFit connected to Weights & Functional
};

int visited[10];

// DFS used for detailed inspection of connected gym sections
void dfs(int gym[10][10], int sections, int startSection) {
    visited[startSection] = 1;

    for (int i = 0; i < sections; i++) {
        if (gym[startSection][i] == 1 && visited[i] == 0) {
            cout << i << "\t";
            dfs(gym, sections, i);
        }
    }
}

int main() {
    int startSection;

    // Initialize visited array
    for (int i = 0; i < sections; i++)
        visited[i] = 0;

    cout << "Enter the starting gym section for inspection: ";
    cin >> startSection;

    cout << "DFS Traversal (Detailed Gym Section Inspection Order):\n";
    cout << startSection << "\t";
    dfs(gym, sections, startSection);

    return 0;
}
