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
  public:
    virtual int fun(Node *root, bool key, map<pair<Node*, bool>, int> &dp){
        if(!root)
          return 0;
        if(dp.find({root, key}) != dp.end())
          return dp[{root, key}];
        
        int nt = fun(root->left, false, dp) + fun(root->right, false, dp);
        if(!key){
            int t = (root->data) + fun(root->left, true, dp) + fun(root->right, true, dp);
            return dp[{root, key}] = max(t, nt);
        }
        return dp[{root, key}] = nt;
    }
  
    int getMaxSum(Node *root) {
        // code here
        map<pair<Node*, bool>, int> dp;
        return fun(root, false, dp);
    }
};