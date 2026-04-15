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
    void dfs(TreeNode* root, int maxi, int& count){
        if(!root) return;

        if(root->val >= maxi)
            count++; // This node is a good node so we increase the counter
        
        dfs(root->left, max(maxi,root->val), count);
        dfs(root->right, max(maxi,root->val), count);
    }

    int goodNodes(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        int maxi = root->val,count = 0;
        dfs(root, maxi, count);
        return count;
    }
};
