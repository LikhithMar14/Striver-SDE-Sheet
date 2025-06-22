// Resource USACO GUIDE

//N nodes , m edege 

// CLEANEST WAY TO FIND CYCLES IN A GRAPH
// #INDEGREE
// We are checking dependencies, not which is numerically greater.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        //i came to an analysis this is a graph quewstion
        //my job is to find the cycle in this 


        vector<vector<int>>adj(numCourses);
        queue<int>q;
        int count = 0;

        for(auto &it: p){
            //unidirectional graph
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegrees(numCourses,0);

        for(int i=0; i < numCourses; i++){
            for(auto &it: adj[i])indegrees[it]++;
        }

        //now you will get the starting points

        for(int i=0; i < numCourses; i++){
            if(!indegrees[i])q.push(i);
        }

        while(!q.empty()){
            //start exploring

            int node = q.front();
            q.pop();
            count++;

            for(auto &it: adj[node]){
                indegrees[it]--;
                if(!indegrees[it])q.push(it);
            }
        }
        return count==numCourses;

    }
};

//ISKA DFS SOLUTION IS NOT RELEVANT FOR ME RIGHT NOW