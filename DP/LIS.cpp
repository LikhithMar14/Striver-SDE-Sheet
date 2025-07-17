//Longest Increasing subsquence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //state: dp[i] => the maxium length of the sereis which starts with this i
        //Transition: => you can take consider the number a from as the extenstion to this at each i we can chose or move en
        int n = nums.size();
        vector<int>dp(n+1,1);
        int maxi = 1;
        vector<int>mp(n,-1);
        int prev = -1;
        //base case every single number is valid

        for(int i=n-1; i >= 0; i--){
            for(int j=i+1; j < n; j++){
                if(nums[i] < nums[j] && dp[i] < dp[j]+1){
                    dp[i] = 1+dp[j];
                    mp[i] = j;
                }
            }
            if(dp[i] >= maxi){
                maxi = dp[i];
                prev = i;
            }
        }

        cout << "Longest Increasing Subsequence Length: " << maxi << endl;
        cout << "Sequence: ";
        while(prev != -1){
            cout << nums[prev] << " ";
            prev = mp[prev];
        }
        cout << endl;

        return maxi;
    }
};

// 368. Largest Divisible Subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //The reason why we are sorting
        // => they asked subsets not subsequences
        // => let us suppose there a three numebrs a, b,c where a < b < c
        // so if we able to rpove that  c%b == 0, and b%a == 0then we can make a series

        sort(nums.begin(),nums.end());

        int n = nums.size();

        vector<int>dp(n+1,1);
        int startIndex = -1;
        vector<int>mp(n,-1);
        int prev = n-1;

        //state
        // dp[i] => the maxium length series starting form this character at ith index
        for(int i=n-1; i >= 0; i--){
            for(int j=i+1; j < n; j++){
                if(nums[j]%nums[i] == 0 && dp[i] < 1+dp[j]){
                    dp[i] = 1+dp[j];
                    mp[i] = j;
                    prev = i;
                }
            }
        }
        //we wil lfind the max index
        int maxValue = *max_element(dp.begin(),dp.end());
        int maxIndex = -1;

        for(int i=0; i < n; i++){
            if(dp[i] == maxValue){
                maxIndex = i;
            }
        }

        int currIndex = maxIndex;
        vector<int> ans;
        while(currIndex != -1) {
            ans.push_back(nums[currIndex]);
            currIndex = mp[currIndex];
        }

        return ans;
    }
};

//Longest String chain

class Solution {
public:
    bool areValid(string &a, string &b){
        int n = a.size();
        int m = b.size();
        if(m != n + 1) return false;

        int i=0;
        int j=0;
        int gap = 0;

        while(i < n && j < m){
            if(a[i] == b[j]){
                i++;
                j++;
            }else{
                gap++;
                if(gap > 1)return false;
                j++;
                if(j >= m)break;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        vector<int>dp(n+1,1);
        sort(words.begin(),words.end(),[](string &a, string &b){
            return a.size() < b.size();
        });
        for(int i=n-1; i >= 0; i--){
            for(int j=i+1; j  < n; j++){
                if(areValid(words[i],words[j])){
                    dp[i] = max(1+dp[j],dp[i]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//Longest bitonic sequcne

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    left[i] = max(left[i], 1 + left[j]);
                }
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] > nums[j]) {
                    right[i] = max(right[i], 1 + right[j]);
                }
            }
        }

        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(left[i] > 1 && right[i] > 1) {
                maxi = max(maxi, left[i] + right[i] - 1);
            }
        }
        return maxi;
    }
};
