#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        //via array
        //normal
        //simple just bruteforce
        int n = dist.size();
        int m = dist[0].size();
        
        for(int via=0; via < n; via++){
            for(int i=0; i < n; i++){
                for(int j=0; j < m; j++){
                    if(dist[i][via] == 1e8 || dist[via][j]== 1e8)continue;
                    
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
        
        
    }
};