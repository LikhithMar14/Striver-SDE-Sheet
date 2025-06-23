#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        //using djikstra
        
        vector<int>dis(adj.size(),1e8);
        
        // can solve with normal bfs
        
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        queue<int>q;
        q.push(src);
        dis[src] = 0;
        
        while(!q.empty()){
            int index = q.front();
            
            q.pop();
            
            for(auto &it: adj[index]){
                if(dis[it] > 1+dis[index]){
                    q.push(it);
                    dis[it] = 1+dis[index];
                }
            }
            
        }
        
        auto it = find(dis.begin(),dis.end(),1e8);
        if(it == dis.end()) return dis;
        
        for(int i=0; i < dis.size(); i++){
            if(dis[i] == 1e8) dis[i] = -1;
        }

        return dis;
    }
};
