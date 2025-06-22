#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int index, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int,int>>q;
        q.push({index,-1});
        
        while(!q.empty()){
            int currParentIndex = q.front().second;
            int currElementIndex = q.front().first;
            vis[currElementIndex] = 1;
            q.pop();
            for(auto &it: adj[currElementIndex]){
                if(!vis[it]){
                    q.push({it, currElementIndex});
                }else{
                    if(it != currParentIndex)return true;
                }
            }
            
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (solve(i, adj, vis)) return true;
            }
        }

        return false;
    }
};
