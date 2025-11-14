#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited); 
            }
        }
    }

    void DFS(int start_node) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        DFSUtil(start_node, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 2); 

    int start_node = 0;

    g.DFS(start_node); 

    return 0;
}
