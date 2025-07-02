#include<bits/stdc++.h>
using namespace std;
// NOT ACCEPTED ON GEEKSFORGEEKS
//Unoptimal solution (on^2)
class Solution {
  public:
  static bool cmp(pair<int,int>&a, pair<int,int>&b){
    if(a.first != b.first)return a.first > b.first;
    return a.second > b.second;
  }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int maxDays = *max_element(deadline.begin(),deadline.end());
        vector<int>days(maxDays,-1);
        
        vector<pair<int,int>>arr;
        
        
        for(int i=0; i < deadline.size(); i++){
            arr.push_back({profit[i],deadline[i]});
        }
        sort(arr.begin(),arr.end(),cmp);
        int res = 0;
        int jobCount = 0;
        //optimal solution (onlogn) using dsu
        for(int i=0; i < arr.size(); i++){
            for(int j = arr[i].second-1; j >= 0; j--){
                if(days[j] == -1){
                    days[j] = 1;
                    jobCount++;
                    res += arr[i].first;
                    break;
                }
            }
        }
        return {jobCount,res};
        
        
    }
};

