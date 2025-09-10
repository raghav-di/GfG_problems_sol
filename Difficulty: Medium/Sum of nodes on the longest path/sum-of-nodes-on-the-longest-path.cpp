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
}; */

class Solution {
  public:
    void longSum(Node* root, int sum, int length, vector<pair<int,int>> &sums){
        if(!root){
            sums.push_back(make_pair(sum,length));
            return;
        }
        sum += root->data;
        longSum(root->left, sum, length+1, sums);
        longSum(root->right, sum, length+1, sums);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        vector<pair<int,int>> sums;
        longSum(root, 0, 0, sums);
        pair<int,int> maxpair = sums[0];
        for(pair<int,int> e : sums){
            if(e.second>maxpair.second){
                maxpair.second = e.second;
                maxpair.first = e.first;
            }
            else if(e.second==maxpair.second){
                if(e.first>maxpair.first){
                    maxpair.second = e.second;
                    maxpair.first = e.first;
                }
            }
            
        }
        return maxpair.first;
    }
};