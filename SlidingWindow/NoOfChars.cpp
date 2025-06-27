#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int n = s.size();

        int i=0;
        int j=0;

        int ans = 0;

        while(j < n){
            mp[s[j]]++;
            //shrinking
            //already jo ana h milkchuka hai
            while(i <= j && mp['a']  && mp['b']  && mp['c'] ){
                mp[s[i]]--;
                i++;
                //very important pattern
                ans += (n-j);
            }
            j++;

        }
        return ans;
    }
};