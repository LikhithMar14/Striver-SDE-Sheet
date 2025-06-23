#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        //buidling adjacencly list

        vector<vector<int>>adj(numCourses);

        for(int i=0; i < p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        //count the indegree of the each one

        vector<int>indegree(numCourses,0);

        for(int i=0; i < numCourses; i++){  
            for(auto &it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i = 0; i < numCourses; i++){  
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int el = q.front();
            q.pop();
            
            ans.push_back(el);  

            for(auto &it: adj[el]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() == numCourses) return ans;
        else return vector<int>{};  
    }
};
