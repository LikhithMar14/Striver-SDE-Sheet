//Climbing Steps
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:


    int climbStairs(int n) {
        //state , transition

        //State
        //dp[i] = dp[i+1] + dp[i+2];
        //dp[0] = dp[1]+dp[2];
        //from this we can conclude that we need to precalcuate the next 2 steps before only so the for loop will come revrse
        vector<int>dp(n+3,0);
        //you have reached the destination
        dp[n] = 1;
        dp[n-1] = 1;

        for(int i=n-2; i >= 0; i--){
            dp[i] = dp[i+1]+dp[i+2];
        }
        return dp[0];
    }
};


//Frog Jump

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        // Code here
        //state
        //dp[i] the minium amount of cost i need to take to reacth the top
        //dp[i] = min(heights[i] + dp[i+1],heights[i]+dp[i+2]);
        //by this we can conlcude we need loop in reverse
        ////the most optimal way to reach the top is going to be min(heights[n-2],heights[n-1]);
        vector<int>dp(height.size()+2,0);
    
        
        for(int i=n-2; i >= 0; i--){
            dp[i] = min(abs(height[i]-height[i+1])+dp[i+1], ((i+2 >= n) ? INT_MAX : abs(height[i]-height[i+2])+dp[i+2]));  
        }
        return dp[0];
        
        
    }
};




//Frong jump with k distance
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int>dp(n+2,0);
        // vector<vector<int>>dp(n+2,vector<int>(k+2,0));
        for(int i=n-2; i >= 0; i--){
            int mini = INT_MAX;
            for(int j=1; j <= k; j++){
                if(i+j < n){
                    mini = min(mini,(abs(heights[i]-heights[i+j])+dp[i+j]));
                }
            }
            dp[i] = mini;
        }
        return dp[0];
    }
};


//House Robber-II
class Solution {
public:
    int rob(vector<int>& nums) {
        //state dp[i] => 
        //Restrictions: you cannot choose ii+1
        //maxiumum things i can loot from this point
        //i can start from 0th index or 1st  and choose max
        //dp[i] = max(maxi,dp[i+j]+heights[i]);
        //we will have two rounds on from 0 to n-2, 1 to n-1
        int n = nums.size();
        //edge case 
        if(n == 1)return nums[0];

        //you can chose the next one and the current one with the best of next next one

        vector<int>dp1(n+3,0),dp2(n+3,0);

        for(int i=n-2; i >= 0; i--){
            dp1[i] = max(dp1[i+1],dp1[i+2]+nums[i]);
        }
        for(int i=n-1; i >= 1; i--){
            dp2[i] = max(dp2[i+1],dp2[i+2]+nums[i]);
        }

        return max(dp1[0],dp2[1]);


    }
};