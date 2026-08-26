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
    int f(TreeNode* root, int& maxi){
        if(!root) return 0;

        int left = f(root->left,maxi);
        int right = f(root->right,maxi);

        maxi = max(maxi, left+right);
        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;

        f(root,maxi);

        return maxi;
    }
};
