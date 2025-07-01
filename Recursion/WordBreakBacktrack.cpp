#include<bits/stdc++.h>
using namespace std;
//backtracking approach
//will give a tle
class Solution {
public:
    bool solve(int start, string& s, unordered_set<string>& wordSet) {
        if (start == s.length()) return true;

        for (int end = start; end < s.length(); ++end) {
            string word = s.substr(start, end - start + 1);
            if (wordSet.count(word)) {
                if (solve(end + 1, s, wordSet)) return true;
            }
        }

        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return solve(0, s, wordSet);
    }
};