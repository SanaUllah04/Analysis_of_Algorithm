#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, list<int>> adj;

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // BFS traversal of the vertices reachable from v
    void BFS(int start);
};

void Graph::addEdge(int v, int w) {
    // Add w to v’s list
    adj[v].push_back(w);
}

void Graph::BFS(int start) {
    // Mark all the vertices as not visited
    map<int, bool> visited;
    for (auto &vertex : adj) {
        visited[vertex.first] = false;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push_back(start);

    while (!queue.empty()) {
        // Dequeue a vertex from the queue and print it
        start = queue.front();
        cout << start << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex start
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (auto &i : adj[start]) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push_back(i);
            }
        }
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

    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "Following is Breadth First Traversal (starting from vertex " << startVertex << ") \n";

    // Function call
    g.BFS(startVertex);

    return 0;
}
