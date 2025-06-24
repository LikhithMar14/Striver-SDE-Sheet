//Impotant question 


//Dijkstra's algorithm with a twist
//we are storing the stops as weight
//we are not retturning when we hit  dst
// we are waiting till the end

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // when we have equal increasing in values(when we compare steps) then there is no need to heap
        //simple bfs with queue
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        // Converting 2d vector into graph
        vector<pair<int,int>>adj[n];
        vector<int>dist(n,1e9);
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // Now you have your adjacency list
        while(!q.empty()){
            auto it = q.front();
            int node = it.second.first;
            int stops = it.first;
            int cost = it.second.second;
            q.pop();
            if(stops > k)continue;
            for(auto it:adj[node]){
                if(it.second+cost < dist[it.first]){
                    dist[it.first] = it.second+cost;
                    q.push({stops+1,{it.first,dist[it.first]}});
                }
            }
        }
        if(dist[dst] == 1e9)return -1;
        return dist[dst];
    }
};