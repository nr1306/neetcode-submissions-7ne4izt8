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
    int dfs(TreeNode* root, int& maxi){
        if(!root) return 0;

        int leftMaxSum = dfs(root->left, maxi);
        int rightMaxSum = dfs(root->right, maxi);

        maxi = max(maxi, root->val + leftMaxSum + rightMaxSum);
        return root->val + max(leftMaxSum, rightMaxSum) < 0 ? 
               0 : root->val + max(leftMaxSum, rightMaxSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        dfs(root, maxi);
        return maxi;
    }
};
