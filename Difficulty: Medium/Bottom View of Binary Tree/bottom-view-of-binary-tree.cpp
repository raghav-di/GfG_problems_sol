/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int,vector<int>> nodes;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* curr = temp.first;
            int hd = temp.second;
            nodes[hd].push_back(curr->data);
            if(curr->left){
                q.push(make_pair(curr->left, hd-1));
            }
            if(curr->right){
                q.push(make_pair(curr->right, hd+1));
            }
        }
        for(auto i : nodes){
            ans.push_back(*(i.second.end()-1));
        }
        return ans;
    }
};