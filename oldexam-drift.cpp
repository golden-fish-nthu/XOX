#include <iostream>
#include <vector>
using namespace std;

struct Graph {
    int V;                    // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

    Graph(int V)
        : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);  // Add both directions for an undirected graph
    }

    bool DFSUtil(int v, vector<bool>& visited, int parent, int& cycleNode) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (DFSUtil(neighbor, visited, v, cycleNode))
                    return true;
            } else if (neighbor != parent) {
                cycleNode = neighbor;
                return true;
            }
        }
        return false;
    }

    int findCycleNode() {
        vector<bool> visited(V, false);
        int cycleNode = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFSUtil(i, visited, -1, cycleNode))
                    return cycleNode;
            }
        }
        return -1;  // Should never reach here if there's exactly one cycle
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Graph g(n);
        for (int i = 0; i < n; i++) {
            int A, B;
            cin >> A >> B;
            g.addEdge(A, B);
        }
        cout << g.findCycleNode() << endl;
    }
    return 0;
}