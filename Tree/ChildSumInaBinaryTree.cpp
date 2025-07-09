

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};




class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        if(!root)return 1;
        if (!root->left && !root->right) return 1;

        
        if(!root->left && root->right && root->data == root->right->data)return isSumProperty(root->right);
        if(!root->right && root->left && root->data == root->left->data)return isSumProperty(root->left);
        if (!root->left || !root->right) return 0;
        if(root->data != root->left->data + root->right->data)return 0;
        int leftVal = isSumProperty(root->left) ? 1 : 0;
        int rightVal = isSumProperty(root->right) ? 1 : 0;
        
        return leftVal && rightVal;
        
        
        
    }
};