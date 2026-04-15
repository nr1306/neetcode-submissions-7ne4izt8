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
    void inorder(TreeNode* root, int& prev, bool& res){
        if(!root) return;

        inorder(root->left,prev,res);

        int curr = root->val;
        if(curr > prev) prev = curr;
        else res = false;
        
        inorder(root->right,prev,res);
    }

    bool isValidBST(TreeNode* root) {
        bool res = true;
        int prev = INT_MIN;
        inorder(root, prev, res);
        return res;
    }
};
