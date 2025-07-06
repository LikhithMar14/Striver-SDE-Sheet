#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int result = -1e9;
public:
    int solve(TreeNode* root){
        if(!root)return 0;
        //hanlding negtaive edges
        int leftPathSum = max(0,solve(root->left));
        int rightPathSum = max(0,solve(root->right));
        result = max(result, leftPathSum+rightPathSum+root->val);

        return root->val + max(leftPathSum,rightPathSum);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return result;
    }
};