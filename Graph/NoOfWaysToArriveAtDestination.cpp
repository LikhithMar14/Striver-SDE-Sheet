#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //dont make things complicated
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it : roads){
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        int MOD = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, wt] : adj[u]) {
                if (dist[v] > d + wt) {
                    dist[v] = d + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if (dist[v] == d + wt) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
