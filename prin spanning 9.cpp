#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < key.size(); v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

// Function to construct and print MST for a graph represented using adjacency list representation
void primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> parent(V); // Array to store constructed MST
    vector<int> key(V); // Key values used to pick the minimum weight edge in cut
    vector<bool> mstSet(V); // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first vertex in MST.
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Example graph represented using adjacency list
    vector<vector<int>> graph(5);

    // Add edges to the graph
    graph[0].push_back(0);
    graph[0].push_back(2);
    graph[0].push_back(0);
    graph[0].push_back(6);
    graph[0].push_back(0);

    graph[1].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(8);
    graph[1].push_back(5);

    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[2].push_back(0);
    graph[2].push_back(0);
    graph[2].push_back(7);

    graph[3].push_back(6);
    graph[3].push_back(8);D
    graph[3].push_back(0);
    graph[3].push_back(0);
    graph[3].push_back(9);

    graph[4].push_back(0);
    graph[4].push_back(5);
    graph[4].push_back(7);
    graph[4].push_back(9);
    graph[4].push_back(0);

    // Print the MST
    cout << "Minimum Spanning Tree:\n";
    primMST(graph);

    return 0;
}

