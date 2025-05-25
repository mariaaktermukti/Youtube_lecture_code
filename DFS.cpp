#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;  // Maximum number of nodes
vector<int> graph[MAX]; // Adjacency list representation of graph
bool visited[MAX]; // To keep track of visited nodes

// DFS function - visits all nodes reachable from 'node'
void dfs(int node) 
{
    cout << "Visited node: " << node << endl;
    visited[node] = true; // Mark the node as visited

    // Visit all unvisited neighbors
    for (int neighbor : graph[node]) 
    {
        if (!visited[neighbor]) 
        {
            dfs(neighbor); // Recursive call to DFS
        }
    }
}

int main() 
{
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    // Input edges
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // For undirected graph
    }

    // Initialize all nodes as unvisited
    for (int i = 0; i <= nodes; ++i) 
    {
        visited[i] = false;
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "\nDFS traversal starting from node " << start << ":\n";
    dfs(start);  // Start DFS from the given node

    return 0;
}





// user input
// Enter number of nodes and edges: 5 4
// Enter edges (u v):
// 1 2
// 1 3
// 2 4
// 3 5
// Enter starting node: 1
//output:
// DFS traversal starting from node 1:
// Visited node: 1
// Visited node: 2
// Visited node: 4
// Visited node: 3
// Visited node: 5
// PS D:\Youtube>