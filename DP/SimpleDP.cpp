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



