#include <bits/stdc++.h>
using namespace std;
//TIME COMPLEXITY: E LOG V
//BOTH DIRECTED AND UNIDRECTED GRAPHS
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {
        // Code here
        vector<int>dis(V,1e9);
        
        //building adjcency list
        vector<vector<pair<int,int>>>adj(V);
        
        
        for(int i=0; i < edges.size(); i++){
            int firstNode = edges[i][0];
            int secondNode = edges[i][1];
            int weight = edges[i][2];
            adj[firstNode].push_back({secondNode, weight});
            adj[secondNode].push_back({firstNode, weight});
        }
        
        //now you got the proper strcutre
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        dis[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            //kind of bfs
            
            int topNodeWeight = pq.top().first;
            int topNodeIndex = pq.top().second;
            pq.pop();
            
            for(auto &it : adj[topNodeIndex]){
                if(dis[it.first] > topNodeWeight+it.second){
                    dis[it.first] = topNodeWeight+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        return dis;
        
        
    }
};