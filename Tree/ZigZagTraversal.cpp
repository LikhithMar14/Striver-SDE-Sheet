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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // we will use alterator + deque logic

        if (!root) return {}; 

        deque<TreeNode*> dq;
        vector<vector<int>> res;
        dq.push_back(root);
        int alt = 0;

        // 0 => left to right (pop from front), normal
        // 1 => right to left (pop from back), reverse

        while (!dq.empty()) {
            int length = dq.size();
            vector<int> level;

            for (int i = 0; i < length; i++) {
                TreeNode* topEl = nullptr;

                if (alt == 0) {
                    topEl = dq.front(); dq.pop_front();
                    level.push_back(topEl->val);

                    if (topEl->left) dq.push_back(topEl->left);
                    if (topEl->right) dq.push_back(topEl->right);

                } else {
                    topEl = dq.back(); dq.pop_back();
                    level.push_back(topEl->val);


                    if (topEl->right) dq.push_front(topEl->right);
                    if (topEl->left) dq.push_front(topEl->left);
                }
            }

            res.push_back(level);
            alt = !alt;
        }

        return res;
    }
};
