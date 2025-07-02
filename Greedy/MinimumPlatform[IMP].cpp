#include<bits/stdc++.h>
using namespace std;
//Important way of thinking 
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        
        int n = arr.size();
        // Your code here
        int i = 1;
        //already there is one train
        int j = 0;
        
        //with the departure of j
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int platform = 1;
        
        //here a particular train doesnt matter 
        //just hte arrival and departrue timess matter
        int maxi = 1;
        
        while(j < n && i < n){
            if(arr[i] <= dep[j]){
                platform++;
                i++;
            }else {
                platform--;
                j++;
            }
            maxi = max(platform,maxi);
        }
        return maxi;
        
    }
};
