#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        //keep things minimal
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        int sum = 0;
        
        pq.push({0,{0,-1}});
        
        vector<int>vis(V,-1);
        
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int topElementWeight = top.first;
            int u = top.second.first;
            int v = top.second.second;

            if(vis[u] == 1) continue;

            vis[u] = 1;
            sum += topElementWeight;
            
            for(auto &it: adj[u]){
                int next = it[0];
                int wt = it[1];
                if(vis[next] == -1){
                    pq.push({wt, {next, u}});
                }
            }
        }

        return sum;
    }
};
