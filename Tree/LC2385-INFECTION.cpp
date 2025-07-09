#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};
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
#define ll long long 
class Solution {
public:
    void convertToGraph(TreeNode* root, unordered_map<int,vector<int>>&mp){
        if(!root)return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }

        convertToGraph(root->left,mp);
        convertToGraph(root->right,mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        //convert into adjacecnly list 
        //parnet node and it children
        unordered_map<int,vector<int>>mp;
        vector<int>vis(1e5+5,0);

        convertToGraph(root,mp);
        //now you have the graph

        //now you need to bfs for the most optimal thing 

        queue<pair<int,int>>q;
        q.push({start,0});
        vis[start] = 1;
        int maxi = 0;

        while(!q.empty()){
            int len = q.size();
            for(int i=0; i < len; i++){
                auto [el,dist] = q.front();
                q.pop();
                maxi = max(maxi,dist);

                for(auto &it: mp[el]){
                    if(!vis[it]){
                        q.push({it,dist+1});
                        vis[it] = 1;
                    }

                }
            }

        }
        return maxi;

    }
};