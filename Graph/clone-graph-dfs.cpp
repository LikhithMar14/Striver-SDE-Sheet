#include<bits/stdc++.h>


using namespace std;

class Node{
    public:
    int val;
    vector<Node*> neighbors;
    Node(int val){
        this->val = val;
    }
};




class Solution {
public:
    map<int, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;


        if (mp.find(node->val) != mp.end()) {
            //iska already subsethogaya hia
            return mp[node->val];
        }


        Node* cloneNode = new Node(node->val);
        mp[node->val] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};