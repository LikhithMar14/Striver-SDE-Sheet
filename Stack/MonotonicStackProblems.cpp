#include <bits/stdc++.h>
using namespace std;

//Monotonic Stack is a stack that maintains a monotonic order of elements.

//==========================================Next Greater Element I==========================================
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //Monotonic Stack
        vector<int>temp(1e4+5,0);
        stack<int>st;
        int n = nums2.size();

        for(int i = n-1; i >= 0; i--){
            //Monotonic Increasing Stack(fromn top to bottom)
            while(i >= 0 &&  st.size() > 0 && nums2[i] >= st.top())st.pop();
            if(st.empty()){
                temp[nums2[i]] = -1;

            }else{
                int el = st.top();
                temp[nums2[i]] = el;
            }
            st.push(nums2[i]);
         

        }

        vector<int>res;
        for(int i=0; i < nums1.size(); i++)res.push_back(temp[nums1[i]]);
        return res;

    }
};

//==========================================Next Greater Element II==========================================


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Circular arry logic

        // 1 2 1 1 2 1
        //feed the elements in the stack from right to left so that we can access them later

        vector<int>res(nums.size(),-1);
        stack<int>st;
        int n = nums.size();

        for(int i=2*n-1; i >= 0; i--){
            while(st.size() && st.top() <= nums[i%n])st.pop();
            if(!st.empty())res[i%n] = st.top();
            st.push(nums[i%n]);
        }
        return res;

    }
};

//==========================================Sum of Subarray Minimums==========================================\
//https://leetcode.com/problems/sum-of-subarray-minimums/description/
//================================IMPORTANT================================================


//hmra fielding set hai yaha par

//Take care of >= and > in left and right 
//we are doing this to avoid double counting
#define ll long long 
class Solution {
public:
    void nearestLeftMinElement(int n, vector<int>&arr,vector<int>&leftArray){
        stack<int>st;
        for(int i=0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])st.pop();
            if(st.empty())leftArray[i] = -1;
            else leftArray[i] = st.top();
            st.push(i);
        }

    }
    void nearestRightMinElement(int n,vector<int>&arr, vector<int>&rightArray){
        stack<int>st;
        for(int i=n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();
            if(st.empty())rightArray[i] = n;
            else rightArray[i] = st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        //Really a good way of thinking
        // Instead of going to every subarry what you can do is , as an elemen t where i can be the minimum like when
        //we are createing subsets there will be only two cases on the left and right
        //we will finding nearest less elelmetn on left and right

        int n = arr.size();
        ll sum = 0;
        int MOD = 1e9+7;

    

        vector<int>leftArray(n,0);
        vector<int>rightArray(n,0);

        nearestLeftMinElement(n,arr,leftArray);
        nearestRightMinElement(n,arr,rightArray);

        for(int i=0; i < n; i++){
            ll leftCont = ((i-leftArray[i]))%MOD;
            ll rightCont = ((rightArray[i]-i))%MOD;

            sum = (sum + arr[i] * leftCont % MOD * rightCont % MOD) % MOD;
        }
        return static_cast<int>(sum);
    }
};


//==========================================Sum of Subarray Ranges==========================================
//https://leetcode.com/problems/sum-of-subarray-ranges/description/
//================================IMPORTANT================================================



#define ll long long 

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // o(n) solution

        //just think in terms of addition and subtraction

        int n = nums.size();

        stack<int>st;

        //first find the left side greater range
        //take care of > >= 
        vector<int>leftMax(n,0);
        vector<int>leftMin(n,0);
        
        for(int i=0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) leftMax[i] = -1;
            else leftMax[i] = st.top();
            st.push(i); 
        }

        while(!st.empty()) st.pop(); 

        for(int i=0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(st.empty()) leftMin[i] = -1;
            else leftMin[i] = st.top();
            st.push(i); 
        }

        while(!st.empty()) st.pop(); 

        vector<int>rightMax(n,0);
        vector<int>rightMin(n,0);

        for(int i=n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) rightMax[i] = n;
            else rightMax[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop(); 

        for(int i=n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(st.empty()) rightMin[i] = n;
            else rightMin[i] = st.top();
            st.push(i); 
        }

        ll result = 0;

        for(int i=0; i < n; i++){
            ll leftCountMax = i - leftMax[i];
            ll rightCountMax = rightMax[i] - i;

            ll leftCountMin = i - leftMin[i];
            ll rightCountMin = rightMin[i] - i;

            result += (ll)nums[i] * leftCountMax * rightCountMax;
            result -= (ll)nums[i] * leftCountMin * rightCountMin;
        }

        return result;
    }
};


//==========================================Remove K Digits==========================================
//https://leetcode.com/problems/remove-k-digits/description/
//================================IMPORTANT================================================



class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int>st;
        string ans = "";

        // A very good question of monotonic stack where you can clearly feel

        for(int i = 0; i < n; i++) {
            while(k > 0 && !st.empty() && st.top() > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push((num[i] - '0'));
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while(st.size()) {
            ans += (char)(st.top() + '0');
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.size()) {
            if(ans[i] != '0') break;
            i++;
        }


        string res = ans.substr(i);
        

        if(res.empty() || k > 0) res = "0";

        return res;
    }
};
