#include <bits/stdc++.h>
using namespace std;

struct TreeNode {   
    int val;
    TreeNode* left;
    TreeNode* right;
};

//Easy approach using graph

class Solution {
public:
    void constructGraph(TreeNode* curr, TreeNode* parent, vector<vector<int>>& adj) {
        if (!curr) return;  

        if (parent) {
            adj[parent->val].push_back(curr->val);
            adj[curr->val].push_back(parent->val);
        }

        constructGraph(curr->left, curr, adj);
        constructGraph(curr->right, curr, adj);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> adj(501);
        constructGraph(root, nullptr, adj);

        queue<int> q;
        vector<int> vis(501, 0);
        q.push(target->val);  
        vis[target->val] = 1;

        int cnt = 0;
        while (!q.empty()) {
            int length = q.size();
            if (cnt == k) break;

            for (int i = 0; i < length; i++) {
                int curr = q.front(); q.pop();  

                for (auto &it : adj[curr]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            cnt++;
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }


        return res;
    }
};

