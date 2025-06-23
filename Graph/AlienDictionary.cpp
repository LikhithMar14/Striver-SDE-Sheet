#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        // topological sorting
        
        //building a graph from it
        
        vector<vector<int>>adj(26);
        set<int>st;
        for(int i=0; i < words.size(); i++){
            for(int j=0; j < words[i].size(); j++){
                st.insert(words[i][j]-'a');
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            int j = 0;
            while (j < words[i].size() && j < words[i + 1].size()) {
                if (words[i][j] != words[i + 1][j]) {
                    adj[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                    break;
                }
                j++;
            }

            if (j == words[i + 1].size() && words[i].size() > words[i + 1].size()) return "";
        }

        
        // store the values which are present
        
        //now you have the adjacency list now it's just the standard alogrithm
        
        
        //indegress algorithm
        
        //calculation of indegrees
        
        vector<int>indegree(26,0);
        
        for(int i=0; i < 26; i++){
            for(auto &it: adj[i]){
                indegree[it]++;
            }
        }
        //pushing the indegree with 0 and present in the strings
        
        queue<int>q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && st.find(i) != st.end()) {
                q.push(i);
            }
        }
        //so you can start from these nodes
        
        string res = "";

        while (!q.empty()) {
            int node = q.front(); q.pop();
            res += (char)(node + 'a');
        
            for (auto &nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        //check for cycle
        if (res.size() != st.size()) return "";
        
        return res;

        
        
        
    }
};