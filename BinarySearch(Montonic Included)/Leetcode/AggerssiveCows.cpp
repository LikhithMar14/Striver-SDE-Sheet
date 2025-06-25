#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool check(int mid, vector<int>&stalls,int k){
        //check function feeling difficult
        
        // kya hum utna gap maintain karpathe
        //can we acheive the cojnntnwith tat gap
        int cnt = 1;
        int last = 0;
        //paths with the gap
        for(int i=0; i < stalls.size(); i++){
            if(stalls[i]-stalls[last] >= mid){
                cnt++;
                last = i;
            }
        }
        return cnt >= k;
        
        
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        //wed can sort the stalls because we dont need the info about their relative positions we only 
        
        //need positions 
        
        sort(stalls.begin(), stalls.end());
        int l = 1;
        int h = *max_element(stalls.begin(),stalls.end())-*min_element(stalls.begin(),stalls.end());
        
        int ans = l;
        
        while(l <= h){
            int mid = (l+((h-l) >> 1));
            if(check(mid,stalls,k)){
                ans = mid;
                l=mid+1;
            }else h = mid-1;
        }
        return ans;
    }
};