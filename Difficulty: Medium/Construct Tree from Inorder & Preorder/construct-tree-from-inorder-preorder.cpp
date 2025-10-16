/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    int position(vector<int> in, int e, int n){
        for(int i = 0; i<n; i++){
            if(in[i]==e){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int> in, vector<int> pre, int &preIdx, int inS, int inE, int n){
        if(preIdx>=n || inS>inE){
            return NULL;
        }
        int e = pre[preIdx++];
        Node* root = new Node(e);
        int idx = position(in, e, n);
        root->left = solve(in, pre, preIdx, inS, idx-1, n);
        root->right = solve(in, pre, preIdx, idx+1, inE, n);
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int size = inorder.size(), preIdx = 0;
        Node* root = solve(inorder, preorder, preIdx, 0, size-1, size);
        return root;
    }
};