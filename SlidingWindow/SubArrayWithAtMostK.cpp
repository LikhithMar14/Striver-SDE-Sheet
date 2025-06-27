#include<bits/stdc++.h>
using namespace std;    
class Solution {
  public:
    int atMostK(vector<int> &arr, int k) {
        // code here
        map<int,int>mp;
        int n = arr.size();
        int i = 0;
        int j = 0;
        
        int ans = 0;
        
        while(j < n){
            mp[arr[j]]++;
            while(i <= j && mp.size() > k){
                (mp[arr[i]] > 1) ? mp[arr[i]]-- : mp.erase(arr[i]);
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }
        return ans;
        
    }
};