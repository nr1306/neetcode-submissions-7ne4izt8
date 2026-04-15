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
    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        if(left == -1) return -1;

        int right = dfs(root->right);
        if(right == -1) return -1;
        
        // cout << root->val << " " << left << " " << right << endl;
        if(abs(right-left) > 1) return -1;
        return 1 + max(left, right);
    }


    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(dfs(root) == -1) return false;
        return true;
    }
};
