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
    int solve(TreeNode* root, int& maxi){
        if(!root) return 0;

        int sumLeft = solve(root->left,maxi);
        int sumRight = solve(root->right,maxi);

        if(sumLeft < 0) sumLeft = 0;
        if(sumRight < 0) sumRight = 0;

        maxi = max(maxi, root->val + sumLeft + sumRight);

        return root->val + max(sumLeft, sumRight);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};
