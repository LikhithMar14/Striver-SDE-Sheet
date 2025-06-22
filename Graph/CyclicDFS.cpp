#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool solve(int index, int parent,  vector<vector<int>>&adj, vector<int>&vis) {
        if(index >= vis.size())return true;
        
        vis[index] = 1;
        for(auto &it: adj[index]){
            if(vis[it] && parent != it)return true;
            
            if (solve(it,index,adj,vis)) return true;
        }
        return false;
        
        
    }
  
        
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V,0);
        //convert into adjacecny list
        
        vector<vector<int>>adj(V);
        
        for(int i=0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // cool stuff
        
        //graph can be islands
        
        for(int i=0; i < V; i++){
            if(!vis[i]){
                if(solve(i,-1,adj,vis))return true;
            }
        }
        
        
        return false;
    }
};