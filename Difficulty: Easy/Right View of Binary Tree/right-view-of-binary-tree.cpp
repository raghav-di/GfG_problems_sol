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
}; */

class Solution {
public:
    vector<int> rightView(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at current level

            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();

                // If it's the last node in this level, add to result
                if (i == levelSize - 1) {
                    result.push_back(curr->data);
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return result;
    }
};