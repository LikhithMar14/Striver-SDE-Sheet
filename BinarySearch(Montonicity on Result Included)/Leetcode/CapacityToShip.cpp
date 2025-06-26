#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int mid, vector<int>&weights, int days){
        int cnt = 1;
        int tmpCnt = 0;
        for(int i=0; i < weights.size(); i++){
            if(weights[i] > mid)return false;
            if(tmpCnt + weights[i] <= mid){
                tmpCnt += weights[i];
            }else{
                tmpCnt = weights[i];
                cnt++;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);

        int ans = -1;

        while(l <= h){
            int mid = (l + ((h-l) >> 1));
            if(check(mid,weights,days)){
                ans = mid;
                h=mid-1;
            }else l=mid+1;
        }

        return ans;
    }
};