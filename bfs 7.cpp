#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

// Graph class representing a directed graph using adjacency list representation
class Graph {
    int V; // Number of vertices

    // Pointer to an array containing adjacency lists
    vector<list<int>> adj;

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list
    }

    // Function to perform breadth-first search from a given vertex
    void BFS(int s) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        // Iterator to traverse all the adjacent vertices of a vertex
        list<int>::iterator i;

        while (!queue.empty()) {
            // Dequeue a vertex from the queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex s. If an adjacent 
			//vertex has not been visited, mark it visited and enqueue it.
            for (int v : adj[s]) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.push(v);
                }
            }
        }
    }
};

int main() {
    // Create a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int start_vertex = 1;

    cout << "Breadth First Traversal (starting from vertex " << start_vertex << "): ";
    g.BFS(start_vertex);

    return 0;
}

