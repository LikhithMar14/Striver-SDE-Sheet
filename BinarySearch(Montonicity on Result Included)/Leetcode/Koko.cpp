#include<bits/stdc++.h>
using namespace std;
#define ll long long 
class Solution {

public:
    bool check(ll mid,ll hr, vector<int>&piles) {
        ll cnt = 0;
        for(auto &it: piles){
            cnt += (it/mid);
            if(it%mid)cnt++;
            // cout<<cnt<<endl;
        }
        return cnt <= hr;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        //Can easily find this is a binary search on monotonically increasing fuction

        // The importatn work is to write the check function

        ll l = 1;
        ll h = *max_element(piles.begin(),piles.end());
        int ans = -1;

        while(l <= h){
            ll mid = (l + ((h-l) >> 1));
            if(check(mid,hr,piles)){
                ans = mid;
                h = mid-1;
            }else l = mid+1;
        }
        return ans;
    }
};