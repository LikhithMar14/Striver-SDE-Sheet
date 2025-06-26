#include<bits/stdc++.h>
using namespace std;
//Good Segment Pattern
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = fruits.size();

        while(j < n){
            mp[fruits[j]]++;

            while(i <= j && mp.size() > 2){
                (mp[fruits[i]] > 1) ? mp[fruits[i]]-- : mp.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};