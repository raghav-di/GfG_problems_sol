/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
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
    Node* solve(vector<int> in, vector<int> post, int &postIdx, int inS, int inE, int n){
        if(postIdx<0 || inS>inE){
            return NULL;
        }
        int e = post[postIdx--];
        Node* root = new Node(e);
        int idx = position(in, e, n);
        root->right = solve(in, post, postIdx, idx+1, inE, n);
        root->left = solve(in, post, postIdx, inS, idx-1, n);
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        int postIdx = size-1;
        Node* root = solve(inorder, postorder, postIdx, 0, size-1, size);
        return root;
    }
};
