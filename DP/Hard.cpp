//Felt tricky for me probably easy for others


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1e9)));

        //state
        //See one thing r1 and r2 are some every step so we willl only include on r
        //state dp[r][c1][c2]
        //Meanign of state the maximum cherries we can pickup upto this point from 0
        //transition you can move 

        //base case
       dp[0][0][m-1] = grid[0][0] + (0 == m-1 ? 0 : grid[0][m-1]);

        for(int r=1; r < n; r++){
            for(int c1=0; c1 < m; c1++){
                for(int c2=0; c2 < m; c2++){
                    int maxi = -1e9;

                    for(int j1=-1; j1<=1; j1++){
                        for(int j2=-1; j2<=1; j2++){
                            int pc1 = c1 + j1;
                            int pc2 = c2 + j2;

                            if(pc1>=0 && pc1<m && pc2>=0 && pc2<m){
                                maxi = max(maxi,dp[r-1][pc1][pc2]);
                            }
                        }
                    }

                    int cherries = grid[r][c1];
                    if(c1 != c2) cherries += grid[r][c2];
                    dp[r][c1][c2] = cherries + maxi;
                }
            }
        }

        int ans = 0;
        for(int c1=0; c1 < m; c1++){
            for(int c2=0; c2 < m; c2++){
                ans = max(ans, dp[n-1][c1][c2]);
            }
        }
        return ans;
    }
};
