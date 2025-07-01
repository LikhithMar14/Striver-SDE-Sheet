#include<bits/stdc++.h>
using namespace std;
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return (((double)a.first/a.second) > ((double)b.first/b.second));
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>a;
        for(int i=0; i < val.size(); i++){
            a.push_back({val[i],wt[i]});
        }
        sort(a.begin(),a.end(),cmp);
        
        double ans = 0;
        int i = 0;
        while(capacity > 0 && i < a.size()){
            if(a[i].second <= capacity){
                capacity -= a[i].second;
                ans += a[i].first;
            }else{
                 ans +=  (((double)capacity/a[i].second)) * a[i].first;
                capacity = 0;
            }
            i++;
        }
        return ans;
    }
};
