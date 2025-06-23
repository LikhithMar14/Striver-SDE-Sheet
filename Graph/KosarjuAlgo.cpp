#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int i, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st){
        vis[i]=1;
        
        for(auto &it: adj[i]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
                st.push(i);
    }
    
    void newDfs(int i, vector<vector<int>>&adjT, vector<int>&vis){
        vis[i]=1;
        
        for(auto &it: adjT[i]){
            if(!vis[it]){
                newDfs(it, adjT, vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        
        int n = adj.size();
        int m = adj[0].size();
        
        stack<int>st;
        vector<int>vis(n,0);
        
        for(int i=0; i < n; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        //now upto now we will have the stack
        
        //constructing the reverse graph
        
        vector<vector<int>>adjT(n);
        
        
        for(int i=0; i < n; i++){
            for(auto &it: adj[i]){
                adjT[it].push_back(i);
            }
            vis[i]=0;
        }
        
        int scs = 0;
    
        
        
        while(st.size()){
            int el = st.top();
            st.pop();
            
            if(!vis[el]){
                scs++;
                newDfs(el, adjT, vis);
                
            }
            
            
        }
        return scs;
        
    }
};