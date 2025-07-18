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