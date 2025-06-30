#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    bool isPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    void solve(int i, int n, vector<vector<string>>& res, vector<string>& temp, string& s) {
        if (i == n) {
            res.push_back(temp);
            return;
        }

        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            if (isPalindrome(sub)) {
                temp.push_back(sub);
                solve(j + 1, n, res, temp, s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int n = s.size();

        solve(0, n, res, temp, s);
        return res;
    }
};
