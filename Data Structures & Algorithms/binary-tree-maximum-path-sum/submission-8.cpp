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

        int leftSum = dfs(root->left, maxi);
        int rightSum = dfs(root->right, maxi);

// negative values won't contribute to the sum
        if(leftSum < 0) leftSum = 0;
        if(rightSum < 0) rightSum = 0;

        maxi = max(maxi, root->val + leftSum + rightSum);

    // sending the max value among left and right path to parent node
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = -1001;
        dfs(root, maxi);
        return maxi;
    }
};
