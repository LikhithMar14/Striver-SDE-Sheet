//A very good example of topological sorting

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Topological sorting
        int n = graph.size();
        int m = graph[0].size();
        vector<vector<int>>adj(n);
        
        vector<int>indegree(n,0);

        for(int i=0; i < n; i++){
            for(auto &it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int>res;
        queue<int>q;
        for(int i=0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int el = q.front();
            q.pop();

            for(auto &it: adj[el]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    res.push_back(it);
                }
            }
        }
        
         sort(res.begin(),res.end());
         return res;


    }
};