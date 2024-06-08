#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w) {
    // Add w to v’s list
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v]) {
        if (!visited[i])
            DFS(i);
    }
}

// Driver code
int main() {
    Graph g;
    int numEdges, v, w, startVertex;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (format: v w):\n";
    for (int i = 0; i < numEdges; ++i) {
        cin >> v >> w;
        g.addEdge(v, w);
    }

    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "Following is Depth First Traversal (starting from vertex " << startVertex << ") \n";

    // Function call
    g.DFS(startVertex);

    return 0;
}
