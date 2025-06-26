#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int mid, vector<int>&nums, int k, vector<int>&pre){
        int cnt = 1;
        int last = 1;
        for(int i=last; i <= nums.size(); i++){
            if(pre[i]-pre[last-1] > mid){
                cnt++;
                last = i;
                if(cnt > k)return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        //construct a prefix sum
        vector<int>pre(n+1,0);
        pre[1] = nums[0];

        for(int i=2; i <= n; i++){
            pre[i] = (pre[i-1]+nums[i-1]);
        }

        while(l <= h){
            int mid = (l + ((h-l) >> 1));
            if(check(mid,nums,k,pre)){
                h = mid-1;
                ans = mid;
            }else l=mid+1;
        }
        return ans;
    }
};