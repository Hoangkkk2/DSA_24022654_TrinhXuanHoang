#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX; 
const int MAX_V = 500; 
typedef long long WeightType; 
WeightType prim_simple(int V, const vector<vector<int>>& adj_matrix) {
    if (V < 1 || V > MAX_V) return 0;

    vector<int> key(V + 1, INF); 
    vector<bool> in_mst(V + 1, false); 

    WeightType total_weight = 0;
    
    key[1] = 0; 
    
    for (int count = 1; count <= V; ++count) {
        
        int min_key = INF;
        int u = -1; 
        
        for (int v = 1; v <= V; ++v) {
            if (in_mst[v] == false && key[v] < min_key) {
                min_key = key[v];
                u = v;
            }
        }

        if (u == -1) break; 
        
        in_mst[u] = true;
        total_weight += min_key;
        
        for (int v = 1; v <= V; ++v) {
            int weight = adj_matrix[u][v];
            
            if (weight != 0 && in_mst[v] == false && weight < key[v]) {
                key[v] = weight;
            }
        }
    }

    return total_weight;
}
int main() {
    int V, E;
    V = 4;
    E = 5;
    vector<vector<int>> adj_matrix(V + 1, vector<int>(V + 1, 0));
    adj_matrix[1][2] = 10; adj_matrix[2][1] = 10;
    adj_matrix[1][3] = 6; adj_matrix[3][1] = 6;
    adj_matrix[2][4] = 15; adj_matrix[4][2] = 15;
    adj_matrix[3][4] = 4; adj_matrix[4][3] = 4;
    adj_matrix[1][4] = 5; adj_matrix[4][1] = 5;
 WeightType mst_weight = prim_simple(V, adj_matrix);
    cout << mst_weight << endl; 
    return 0;
}
