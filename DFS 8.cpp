#include <iostream>
#include <list>

using namespace std;

// Graph class representing a directed graph using adjacency list representation
class Graph {
    int V; // Number of vertices

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // Recursive function for DFS
    void DFSUtil(int v, bool visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (auto u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Destructor
    ~Graph() {
        delete[] adj;
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list
    }

    // Function to perform depth-first search from a given vertex
    void DFS(int v) {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Call the recursive helper function to print DFS traversal
        DFSUtil(v, visited);

        // Free allocated memory
        delete[] visited;
    }
};

int main() {
    // Create a graph
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    int start_vertex = 2;

    cout << "Depth First Traversal (starting from vertex " << start_vertex << "): ";
    g.DFS(start_vertex);

    return 0;
}
