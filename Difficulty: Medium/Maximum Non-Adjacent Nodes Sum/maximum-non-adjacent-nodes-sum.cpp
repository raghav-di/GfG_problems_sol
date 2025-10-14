/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    pair<int,int> localmax(Node* root){
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> lp = localmax(root->left);
        pair<int,int> rp = localmax(root->right);
        int inc = root->data+lp.second+rp.second;
        // int exc = lp.first+rp.first;
        int exc = max(lp.first,lp.second)+max(rp.first,rp.second);
        pair<int,int> res = make_pair(inc,exc);
        return res;
        
    }
  public:
    int getMaxSum(Node *root) {
        pair<int,int> ans = localmax(root);
        return max(ans.first,ans.second);
    }
};