//dimaag ke tope udgaye bhai

//1547. Minimum Cost to Cut a Stick

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(c+1,0));
        for(int length=2; length < c; length++){
            for(int i=0; i+length < c; i++){
                int j = i+length;
                //choose any point between i and j excluding ]
                dp[i][j] = INT_MAX;

                for(int k=i+1; k < j; k++){
                    dp[i][j] = min(dp[i][j],cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
                }
            }
        }
        return dp[0][c-1];
    }
};

//312. Burst Balloons


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        arr.insert(arr.end(), nums.begin(), nums.end());
        arr.push_back(1);

        int c = arr.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));

        for (int length = 2; length < c; length++) {
            for (int i = 0; i + length < c; i++) {
                int j = i + length;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j],
                    //very important here
                        arr[i] * arr[k] * arr[j] + dp[i][k] + dp[k][j]
                    );
                }
            }
        }
        return dp[0][c-1];
    }
};


