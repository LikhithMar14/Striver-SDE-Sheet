#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        //flloyd warshal
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                if(i == j)dist[i][j] = 0;
            }
        }
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int via = 0; via < n; via++){
            for(int i=0; i < n; i++){
                for(int j=0; j < n; j++){
                    if(dist[i][via] == 1e9 || dist[via][j] == 1e9)continue;

                    dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        int city = -1;
        int maxCount = n;
        for(int i=0; i < n; i++){
            int cnt = 0;
            for(int j=0; j < n; j++){
                if(dist[i][j] <= k)cnt++;
            }
            if(cnt <= maxCount){
                maxCount = cnt;
                city = i;
            }
        }
        return city;

    }
};