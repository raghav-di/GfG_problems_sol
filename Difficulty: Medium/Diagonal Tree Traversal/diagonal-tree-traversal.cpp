/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> result;
    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        while (curr) {
            result.push_back(curr->data);
            if (curr->left) q.push(curr->left); // next diagonal
            curr = curr->right; // same diagonal
        }
    }
    return result;
    }
};