#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    void dfs(TreeNode* root, int row, int col, map<int, map<int, multiset<int>>>& nodes) {
        if (!root) return;

        nodes[col][row].insert(root->val);

        dfs(root->left, row + 1, col - 1, nodes);
        dfs(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        dfs(root, 0, 0, nodes);

        vector<vector<int>> res;

        for (auto& col : nodes) {
            vector<int> temp;
            for (auto& row : col.second) {
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            res.push_back(temp);
        }

        return res;
    }
};
