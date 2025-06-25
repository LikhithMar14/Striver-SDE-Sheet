//Simplest Approach


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& n, int target) {
        set<int>st(n.begin(),n.end());
        vector<int>nums(st.begin(),st.end());
        int l = 0;
        int h = nums.size()-1;

        int ans = -1;

        while(l <= h) {
            int mid = l + ((h-l) >> 1);
            if(nums[mid] == target)return true;

            //check

            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target <= nums[mid]){
                    h = mid-1;
                }
                else l = mid+1;
            }else {
                if(target >= nums[mid] && target <= nums[h]){
                    l = mid+1;
                }else h = mid-1;
            }
        }
        return false;
    }
};