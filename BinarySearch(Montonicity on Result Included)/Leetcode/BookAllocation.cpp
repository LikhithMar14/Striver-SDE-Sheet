#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool check(int mid, vector<int>&arr, int k){
        int cnt = 1;
        int tmpCnt = 0;
        
        for(int i=0; i < arr.size(); i++){
            if(arr[i]+tmpCnt <= mid){
                tmpCnt += arr[i];
            }else{
                if(arr[i] > mid)return false;
                tmpCnt = arr[i];
                cnt++;
            }
        }
        
        return cnt <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n)return -1;
        int l = *max_element(arr.begin(),arr.end());
        int h = accumulate(arr.begin(),arr.end(),0);
        
        int ans = -1;
        
        while(l <= h){
            int mid = (l+((h-l) >> 1));
            
            if(check(mid,arr,k)){
                ans = mid;
                h = mid-1;
            }else l = mid+1;
        }
        
        return ans;
    }
};