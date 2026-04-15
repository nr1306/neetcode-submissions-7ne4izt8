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
    int count = 0;
    void dfs(TreeNode*& root, int k, int& ans){
        if(!root) return ;

        dfs(root->left,k,ans);
        if(count+1 == k) ans = root->val;
        count++;
        dfs(root->right,k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        dfs(root, k, res);
        return res;
    }
};
