#include<bits/stdc++.h>
#include <string>
//Recursion and Backtracking
//Binary Exponentiation

class Solution {
    public:
        long long mod = 1e9 + 7;
        //important
        long long mulMod(long long a, long long b) {
            return (1LL*a % mod * b % mod) % mod;
        }
    
        long long helper(long long n, long long k) {
            if (n == 0) return 1;
    
            long long half = helper(n >> 1, k);
    
            if (n & 1) {
                return mulMod(k, mulMod(half, half));
            }
            return mulMod(half, half);
        }
    
        int countGoodNumbers(long long n) {
            long long odd = (n + 1) >> 1;
            long long even = n >> 1;
    
            return mulMod(helper(odd, 5), helper(even, 4));
        }
    };
    
//BackTrack use address to persist , so we can do physical backtracking and get fine grained control
//Handles not take cases automcatically


class Solution {
    public:
        void solve(int idx, vector<string>&res, string temp,int n){
            if(temp.size() == n){
                res.push_back(temp);
                return;
            }
            //pick 0
            temp.push_back('0');
            solve(idx+1,res,temp,n);
            temp.pop_back();
            if((idx > 0 && temp[idx-1] == '0') || idx == 0){
                temp.push_back('1');
                solve(idx+1,res,temp,n);
                temp.pop_back();
            }
           
    
        }
        vector<string> generateBinaryStrings(int n) {
            // Your code goes here
            vector<string>res;
            string temp = "";
            solve(0,res,temp,n);
            return res;
        }
    };
    

//For Loop Pattern for recursion backtracking

class Solution {
    public:
        void solve(int idx, int n,vector<int>&c,vector<int>&temp,vector<vector<int>>&res,int target,int sum){
           
            if(target == sum){
                res.push_back(temp);
                return;
            }
            
            for(int i = idx; i < n; i++){
                if(i != idx && c[i] == c[i-1]){
                    continue;
                }
                if(sum+c[i] > target)break;//it is sorted
                temp.push_back(c[i]);
                solve(i+1,n,c,temp,res,target,sum+c[i]);
                temp.pop_back();
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& c, int target) {
            sort(c.begin(),c.end());
            //order wont matter and also easy to differentiate
            vector<int>temp;
            vector<vector<int>>res;
            solve(0,c.size(),c,temp,res,target,0);
            return res;
        }
};

//Variable size sliding window
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
    
            int i = 0;
            int j = 0;
            map<int,int>mp;
            int ans = 0;
    
    
            while(j < n){
                //=> Important point to note these growth and decreasing stages can be flipped according to needs
                
                //Growth Stage
                mp[nums[j]]++;
                //decreasing stage on condition
                while(i <= j && mp[0] > k){
                    mp[nums[i]]--;
                    i++;
                }
                //answer calculation
                ans = max(ans,j-i+1);
                j++;
            }
            return ans;
            
        }
    };