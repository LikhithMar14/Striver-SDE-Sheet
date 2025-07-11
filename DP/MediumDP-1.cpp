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


//Minimum Faliing path sum



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //top to down makes more sensse
        int n = matrix.size();

        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0; i < n; i++)dp[0][i] = matrix[0][i];

        for(int i=1; i < n; i++){
            for(int j=0; j < n; j++){
                int up = ((i-1) < 0) ? INT_MAX: dp[i-1][j];
                int upLeft = ((i-1) < 0 || (j-1) < 0) ? INT_MAX : dp[i-1][j-1];
                int upRight = ((i-1) < 0 || (j+1) >= n) ? INT_MAX : dp[i-1][j+1];

                dp[i][j] = matrix[i][j]+min({up,upLeft,upRight});

            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};

//Ninjas Traning 

#include<bits/stdc++.h>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    //at every you have two options other than the previous option
    //what will be the paramerts
    //the defination of the state => the maxium number of points i can earn 
    //from the day to end by choosing which option
    //Golden Rule To Decide the State: Your DP state must capture 
    // all the information needed to make a decision at the current step.

    vector<vector<int>>dp(n+2,vector<int>(5,0));

    //state the maxiumu i can reach from this i to the end
    //dp[i][0->3-{prev}] = max()

    //setting the basecase
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    

    for(int i=1; i < n; i++){
        for(int prevTask=0; prevTask < 3; prevTask++){
            int maxi = 0;
            for(int task=0; task < 3; task++){
                if(task != prevTask){
                    maxi = max(maxi,points[i][task]+dp[i-1][task]);
                }
            }
            dp[i][prevTask] = maxi;
        }
    }
    return *max_element(dp[n-1].begin(),dp[n-1].end());


}