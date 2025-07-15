
//Dp on strings

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+2,vector<int>(m+2,0));

        for(int i=n-1; i >= 0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i] == text2[j])dp[i][j] = 1 + dp[i+1][j+1];
                else{
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        //print thte madx path
        int i = 0, j = 0;
        string lcs = "";

        while (i < n && j < m) {
            if (text1[i] == text2[j]) {
                lcs += text1[i];
                i++;
                j++;
            }
            else if (dp[i + 1][j] >= dp[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }

        cout << "LCS: " << lcs << endl;

  
        return dp[0][0];
    }
};


//Longest common substring


class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1; i >= 0; i--){
            for(int j=m-1; j >= 0; j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
            }
        }
        
        int maxi = 0;
        for(int i=0; i < n;i++){
            for(int j=0; j < m; j++){
                maxi = max(dp[i][j],maxi);
            }
        }
        return maxi;
    }
};