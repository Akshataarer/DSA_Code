#include <iostream>
using namespace std;

int sections = 5;

// Adjacency matrix representing connectivity between plant nursery sections
// 1 → Direct monitoring path
// 0 → No direct path
int nursery[10][10] = {
    {0,1,1,0,0},
    {1,0,0,1,1}, 
    {1,0,0,0,1},
    {0,1,0,0,0},
    {0,1,1,0,0}
};

// Array to track visited sections
int visited[10];

// DFS for deep inspection of plant nursery sections
void dfs(int nursery[10][10], int sections, int sourceSection)
{
    visited[sourceSection] = 1;   // Mark section as inspected

    for (int i = 0; i < sections; i++)
    {
        if (nursery[sourceSection][i] == 1 && visited[i] == 0)
        {
            cout << i << "\t";
            dfs(nursery, sections, i);
        }
    }
}

int main()
{
    int sourceSection;

    // Initialize visited array
    for (int i = 0; i < sections; i++)
        visited[i] = 0;

    cout << "Enter the starting plant nursery section: ";
    cin >> sourceSection;

    cout << "\nDFS Traversal (Plant Inspection Order):\n";
    cout << sourceSection << "\t";

    dfs(nursery, sections, sourceSection);

    return 0;
}
