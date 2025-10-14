/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
    bool ancestor(Node* root, int node, vector<int> &anc){
        if(!root){
            return false;
        }
        if(root->data == node){
            return true;
        }
        
        if(ancestor(root->left, node, anc)|| ancestor(root->right, node, anc)){
            anc.push_back(root->data);
            return true;
        }
        return false;
    }
  public:
    int kthAncestor(Node *root, int k, int node) {
        vector<int> anc;
        if(!ancestor(root, node, anc)){
            return -1;
        }
        if(k>anc.size()){
            return -1;
        }
        return anc[k-1];
    }
};
