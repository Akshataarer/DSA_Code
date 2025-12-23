#include <iostream>
using namespace std;

// BFS traversal to review player progress level-by-level
void bfs(int academy[10][10], int totalNodes, int sourceSport)
{
    int queue[20];
    int front = 0, rear = 0, currentNode, i;
    int visited[10];

    // Initialize visited array
    for (i = 0; i < totalNodes; i++)
        visited[i] = 0;

    // Start BFS from selected sport/category
    queue[rear] = sourceSport;
    visited[sourceSport] = 1;

    cout << "BFS Traversal (Player Progress Level-by-Level):\n";

    while (front <= rear)
    {
        currentNode = queue[front];
        cout << currentNode << "\t";
        front++;

        // Visit connected players/sports
        for (i = 0; i < totalNodes; i++)
        {
            if (academy[currentNode][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear++;
                queue[rear] = i;
            }
        }
    }
}

int main()
{
    int totalNodes = 5;

    // Adjacency matrix representing academy structure
    // Nodes can represent sports categories and players
    int academy[10][10] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,1},
        {0,1,0,0,0},
        {0,1,1,0,0}
    };

    int sourceSport;
    cout << "Enter the starting sport/category node: ";
    cin >> sourceSport;

    bfs(academy, totalNodes, sourceSport);

    return 0;
}
