//Good Segment Pattern
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        map<int,int>mp;
        int ans = 0;


        while(j < n){
            mp[nums[j]]++;
            while(i <= j && mp[0] > k){
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};