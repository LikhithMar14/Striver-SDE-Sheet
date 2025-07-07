#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:

    void solve(TreeNode* root, int depth, vector<int>&res){
        if(!root)return;

        if(depth == res.size())res.push_back(root->val);
        //just reverse for left view
        solve(root->right,depth+1,res);
        solve(root->left,depth+1,res);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        //we need to find the cutoff point kind of thing
        vector<int>res;
        solve(root,0,res);
        return res;
    }
};