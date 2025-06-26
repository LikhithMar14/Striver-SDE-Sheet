#include<bits/stdc++.h>
using namespace std;

//very Important template for binary search on decimal
class Solution {
  public:
     bool check(double mid, vector<int>& stations, int k) {
        int cnt = 0;
        for (int i = 0; i < stations.size() - 1; i++) {
            double dist = stations[i + 1] - stations[i];
            cnt += int(dist / mid);
        }
        return cnt <= k;
    }

        
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int count = 0;
        
        double l=0;
        double h=*max_element(stations.begin(),stations.end())-*min_element(stations.begin(),stations.end());
        
        double ans = -1;
        double err = 1e-9;
        
        while(h - l > err){
            double mid = (l+h)/2.0;//due to decimal not using bits
            if(check(mid,stations,k)){
                h = mid-err;
                ans = mid;
            }else l = mid+err;
            count++;
            if(count >= 200)break;
        }
        return ans;
        
  
    }
};