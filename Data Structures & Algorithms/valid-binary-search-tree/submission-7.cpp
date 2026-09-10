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
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);

    // checking if inorder of elements is in sorted fashion or not
        int val = INT_MIN;
        for(int x : res){
            if(x <= val) return false;
            val = x;
        }
        return true;
    }
};
