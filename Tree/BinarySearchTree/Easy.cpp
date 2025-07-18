//Ceil in BST

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */


void solve(Node*root,int input,int &ans){
    if(!root)return;
    if(root->data >= input)ans = min(ans,root->data);
    if(root->data > input)solve(root->left,input,ans);
    else solve(root->right,input,ans);
}

int findCeil(Node* root, int input) {
    // Your code here
    int ans = 1e9;
    if(!root)return 0;
    solve(root,input,ans);
    return ans == 1e9 ? -1 : ans;
    
}

//kth smallest integer in bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, priority_queue<int,vector<int>,greater<int>>&pq){
        if(!root)return;
        solve(root->left,pq);
        solve(root->right,pq);

        pq.push(root->val);
    }
    int kthSmallest(TreeNode* root, int k) {
        //traverse entire and use ps
        priority_queue<int,vector<int>,greater<int>>pq;
        solve(root,pq);
        while(k > 1){
            k--;
            pq.pop();
        }
        return pq.top();
    }
};