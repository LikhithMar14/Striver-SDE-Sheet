#include<bits/stdc++.h>
using namespace std;


/*

    only for directed graphs

    TIME COMPLEXITY: E * V

    it can detect negative cycle

    it can be used to find shortest path in a graph with negative weights and positive weights


    => IMPORTANT NOTE: 

        In BellmanFord, FlloydWarshal, kuruskals dont use adj lists because we dont care about the negihtbours 

        we are doing a global sleep 

        so use the edges directly dont convert them 
    
    
*/

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        // V-1 relaxations
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // 1 extra relaxation to check for negative cycle
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};  // Negative cycle detected
            }
        }

        return dist;
    }
};
