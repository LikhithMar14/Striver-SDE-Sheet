#include<bits/stdc++.h>
using namespace std;
//Good Segment Pattern

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxFreq = 0;
        map<char,int>mp;
        int ans = 0;

        while(j < n){
            mp[s[j]]++;
            maxFreq = max(maxFreq,mp[s[j]]);
            while(i <= j && j-i+1-maxFreq > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};