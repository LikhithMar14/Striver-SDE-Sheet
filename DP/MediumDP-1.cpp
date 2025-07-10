#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //state dp[i]=> the no of way sto reach lasat node
        //transition dp[i] = i+1 < mdp[i+1]+dp[j+1]
        //base case dp[m][n] = 0
        vector<vector<int>>dp(m+2,vector<int>(n+2,0));
        dp[m-1][n-1] = 1;

        for(int i=m-1; i >= 0; i--){
            for(int j=n-1; j >= 0; j--){
                if (i == m - 1 && j == n - 1) continue; 
                dp[i][j] = ((i + 1 < m) ? dp[i + 1][j] : 0) + ((j + 1 < n) ? dp[i][j + 1] : 0);
            }
        }
        return dp[0][0];
    }
};
//Path having obstacle

#define ll long long 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<ll>>dp(n+3,vector<ll>(m+3,0));
        if (obstacleGrid[n - 1][m - 1] == 1) return 0;


        dp[n-1][m-1] = 1;
        for(int i=n-1; i >= 0; i--){
            for(int j=m-1; j >= 0; j--){
                if(i == n-1 && j == m-1)continue;
                if(obstacleGrid[i][j] == 1)dp[i][j] = 0;
                else dp[i][j] = ((i + 1 < n) ? dp[i + 1][j] : 0) + ((j + 1 < m) ? dp[i][j + 1] : 0);
            }
        }
        return dp[0][0];
    }
};



//Minimum Path Sum


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+3,vector<int>(m+3,0));

        dp[n-1][m-1] = grid[n-1][m-1];

        for(int i=n-1; i >= 0; i--){
            for(int j=m-1; j >= 0; j--){
                if(i == n-1 && j == m-1)continue;
                    dp[i][j] = grid[i][j] + min(
                        ((i+1) < n) ? dp[i+1][j] : INT_MAX,
                        ((j+1) < m) ? dp[i][j+1] : INT_MAX
                    );            
                }
        }
        return dp[0][0];
    }
};


//Triangle




class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //make a compelte 2d arryay and perform dp on it
        int n = triangle.size();
        vector<vector<int>>dp(n+3,vector<int>(n+3,INT_MAX));

        for(int i=0; i < n; i++)dp[n-1][i] = triangle[n-1][i];

        for(int i=n-2; i >= 0; i--){
            for(int j=n-1; j >= 0; j--){
                if(j <= i){
                    dp[i][j] = triangle[i][j] + min(
                        (j < triangle[i + 1].size() ? dp[i + 1][j] : INT_MAX),
                        (j + 1 < triangle[i + 1].size() ? dp[i + 1][j + 1] : INT_MAX)
                    );
                }
            }
        }
        return dp[0][0];

    }
};