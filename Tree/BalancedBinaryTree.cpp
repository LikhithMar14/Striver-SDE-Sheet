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
public:
    int solve(TreeNode* root){
        if(!root)return 0;

        int leftNode = solve(root->left);
        if(leftNode == -1)return -1;

        int rightNode = solve(root->right);
        if(rightNode == -1)return -1;
        if(abs(leftNode-rightNode)>1)return -1;
        return 1+max(leftNode,rightNode);
    }
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};