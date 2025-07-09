#include<bits/stdc++.h>
using namespace std;
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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#define ll unsigned long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        ll maxi = 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int length = q.size();
            ll firstIndex = q.front().second;
            ll lastIndex = q.back().second;

            maxi = max(maxi, lastIndex - firstIndex + 1);

            for (int i = 0; i < length; i++) {
                auto [node, index] = q.front();
                q.pop();

                index -= firstIndex;

                if (node->left) {
                    q.push({node->left, 2 * index});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
            }
        }

        return maxi;
    }
};
