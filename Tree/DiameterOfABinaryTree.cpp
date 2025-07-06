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
    int res = 0;
public:
    int solve(TreeNode* root){
        if(!root)return 0;
        //diameter will be you ulitimate left and ultimate right
        //at every node find ultimate left and ulitmiate right for that length
        //abs(maxnooftimesmovedright-maxnofofitmesmoveedleft)
        int maxLeftMoves = solve(root->left);
        int maxRightMoves = solve(root->right);

        res = max(res, maxLeftMoves + maxRightMoves);

        return 1+max(maxLeftMoves,maxRightMoves);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res;

    }
};