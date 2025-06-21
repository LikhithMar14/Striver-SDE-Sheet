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
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;

        Node *firstNode = new Node(node->val);
        queue<Node*>q;
        q.push(node);
        unordered_map<int,Node*>mp;
        mp[firstNode->val] = firstNode;

        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();
            Node *CopyNode = mp[currNode->val];

            for(auto &it: currNode->neighbors){
                if(mp.find(it->val) == mp.end()){
                    Node *newNode = new Node(it->val);
                    q.push(it);
                    mp[it->val] = newNode;
                    mp[CopyNode->val]->neighbors.push_back(newNode);
                }
                else{
                    //iska already sub set hogaya you just need to add it
                    CopyNode->neighbors.push_back(mp[it->val]);
                }
            }
        }
            return firstNode;
    }
};