//Stock selling-II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //State 
        //dp[i][0] = maximum amount profit i can get by buying this at the point of i 
        //dp[i][1] = maximum amount profit i can get by selling this at the point of i
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        
        for(int i=n-1; i >= 0; i--){
            dp[i][0] = max(-prices[i]+dp[i+1][1],dp[i+1][0]);//buy
            dp[i][1] = max(dp[i+1][0]+prices[i],dp[i+1][1]);
        }
        return dp[0][0];
    }
};

//Stock Selling-III

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3)));

        for(int i = n-1; i >= 0; i--)
            for(int j = 1; j >= 0; j--)
                for(int k = 2; k >= 1; k--)
                    dp[i][j][k] = max(
                        (j ? -prices[i] + dp[i+1][0][k] : prices[i] + dp[i+1][1][k-1]),
                        dp[i+1][j][k]
                    );

        return dp[0][1][2];
    }
};

//Stock Selling-IV

class Solution {
public:
    int maxProfit(int cnt, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(cnt+1,0)));
        for(int i=n-1; i >= 0; i--){
            for(int j=1; j >= 0; j--){
                for(int k=cnt; k >= 1; k-- ){
                    if(j){
                        //they can buy
                        dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }else{
                        dp[i][j][k] = max(prices[i]+dp[i][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][cnt];
    }
};

//Stock sellling with cooldown


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(n+2,vector<int>(2,0));

        for(int i=n-1; i >= 0; i--){
            //buy
            dp[i][0] = max(-prices[i]+dp[i+1][1],dp[i+1][0]);
            dp[i][1] = max(prices[i]+dp[i+2][0],dp[i+1][1]);
        }
        return dp[0][0];
    }
};

//Stock sellling with transaction fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1; i >= 0; i--){
            //buy
            dp[i][0] = max(-prices[i]+dp[i+1][1],dp[i+1][0]);

            //sell

            dp[i][1] = max(prices[i]+dp[i+1][0]-fee,dp[i+1][1]);
        }
        return dp[0][0];
    }
};