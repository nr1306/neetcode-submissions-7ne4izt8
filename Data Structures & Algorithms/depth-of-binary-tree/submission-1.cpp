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

        int leftHeight = dfs(root->left, maxi);
        int rightHeight = dfs(root->right, maxi);

        maxi = max(maxi, 1+max(leftHeight,rightHeight));

        return max(leftHeight, rightHeight) + 1;
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};
