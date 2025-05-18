#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main() 
{
    // Create a simple graph using an adjacency list
    map<char, vector<char>> graph;
    graph['A'] = {'B', 'C', 'D'};
    graph['B'] = {'E', 'F'};
    graph['C'] = {'G'};
    graph['D'] = {'H', 'I'};
    graph['E'] = {'J', 'K'};
    graph['F'] = {};
    graph['G'] = {'L'};
    graph['H'] = {};
    graph['I'] = {'M'};
    graph['J'] = {};
    graph['K'] = {'N'};
    graph['L'] = {};
    graph['M'] = {};
    graph['N'] = {};

    map<char, bool> visited;      // To keep track of visited nodes
    queue<char> q;                // Queue for BFS

    q.push('A');                  // Start from node 'A'
    visited['A'] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        char current = q.front(); // Get the front element
        q.pop();                  // Remove it from the queue

        cout << current << " ";   // Print the current node

        // Loop through all neighbors of current node
        for (char neighbor : graph[current]) 
        {
            if (!visited[neighbor]) 
            {
                q.push(neighbor);         // Add neighbor to the queue
                visited[neighbor] = true; // Mark as visited
            }
        }
    }

    return 0;
}



// output: BFS Traversal: A B C D E F G H I J K L M N 