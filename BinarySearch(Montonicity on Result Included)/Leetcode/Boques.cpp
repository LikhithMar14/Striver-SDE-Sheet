#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int mid,vector<int>&bloomDay,int m, int k){
        int cnt = 0;
        int bqt = 0;

        for(int i=0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
                if(cnt == k){
                    bqt++;
                    cnt=0;
                }
            }else cnt = 0;
            
        }
        return bqt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {


        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(l <= h) {
            int mid = (l + ((h-l) >> 1));
            if(check(mid,bloomDay,m,k)){
                h = mid-1;
                ans = mid;
            }else l = mid+1;
        }
        return ans;

    }
};