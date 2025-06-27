#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n, int goal,vector<int>&nums){
        int i = 0;
        int j = 0;
        int ans = 0;
        int cnt = 0;

        while(j < n){
            cnt += nums[j];
            while(i <= j && cnt > goal){
                cnt -= nums[i];
                i++;
            }
            //all subarrays who are less than goals
            ans += (j-i+1);

            j++;
        }
        return ans;
        

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //very important question
        //here they given one thing should be equal so we should do increasing and decreaseing at a same time not possibe

        //cleverly do == k => k-k-1

        return (solve(nums.size(),goal,nums)-solve(nums.size(),goal-1,nums));
  
    }
};