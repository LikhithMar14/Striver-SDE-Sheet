#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// Preorder Traversal

//Top->Left->Right
class Solution {
public:
    vector<int>res;
    void solve(TreeNode* root){
        //preorder 
        if(!root)return;
        res.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};


//Inorder Traversal

//Left->Top->Right
class Solution {
public:
    void solve(TreeNode* root, vector<int>&res){
        if(!root)return;
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        solve(root,res);
        return res;
    }
};

//Postorder Traversal

//Left->Right->Top


class Solution {
public:
    void solve(TreeNode* root, vector<int>&res){
        if(!root)return;
        solve(root->left,res);
        solve(root->right,res);
        res.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        solve(root,res);
        return res;
    }
};

//Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>level;

        level.push(root);
        while(!level.empty()){

            int levelSize = level.size();
            vector<int>temp;
            for(int i=0; i < levelSize; i++){
                TreeNode* front = level.front();
                level.pop();
                temp.push_back(front->val);
                if(front->left)level.push(front->left);
                if(front->right)level.push(front->right);

            }
            res.push_back(temp);
        }
        return res;

    }
};





