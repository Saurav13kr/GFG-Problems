class Solution {
  public:
    int move;
    int dist(Node* node){       // return no. of extra candies this subtree has
        if(!node) return 0;
        int l = dist(node->left);   // left ke paas kitni extra candies h
        int r = dist(node->right);  // right ke paas kitni extra candies h
        move+= abs(l) + abs(r);     // extra candies ko node tak laao 'or' required candies ko node se le jaao
        return node->data+l+r-1;    // 1 khud rakhne ke baad kitni extra bachi 
    }
    int distCandy(Node* root) {
        move = 0;
        dist(root);
        return move;
    }
};