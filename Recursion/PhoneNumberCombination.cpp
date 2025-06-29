#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    void solve(int i, int n,string &digits, vector<string>&res, string &temp,unordered_map<char,string>&mp){

        if(i == n){
            res.push_back(temp);
            return;
        }

        for(auto &it: mp[digits[i]]){
            temp.push_back(it);
            solve(i+1,n,digits,res,temp,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())return {};
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";


        vector<string>res;
        string temp = "";
        solve(0,digits.size(),digits,res,temp,mp);

        return res;
    }
};