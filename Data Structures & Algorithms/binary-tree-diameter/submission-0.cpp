/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root, int& maxlen){
        if(!root) return 0;
        
        int leftH = dfs(root->left,maxlen);
        int rightH = dfs(root->right,maxlen);
        maxlen = max(maxlen, leftH + rightH);
        return 1 + max(leftH,rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxlen = 0;
        dfs(root,maxlen);
        return maxlen;
    }
};
