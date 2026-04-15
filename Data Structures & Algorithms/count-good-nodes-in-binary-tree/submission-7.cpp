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
// Just keeping the track of max value until that node, and comparing current node val to max
// If greater than max then it is a good node

    void dfs(TreeNode* root, int& count, int maxi){
        if(!root) return;
        if(root->val >= maxi) count++;

        maxi = max(maxi, root->val);
        dfs(root->left, count, maxi);
        dfs(root->right, count, maxi);
    }

    int goodNodes(TreeNode* root) {
        int maxi = -101;
        int count = 0;
        dfs(root, count, maxi);
        return count;
    }
};
