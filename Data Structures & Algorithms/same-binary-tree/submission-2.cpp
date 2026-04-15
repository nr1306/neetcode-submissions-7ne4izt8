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
    void preorder(TreeNode* root, string& res){
        if(!root){
            res.append("#");
            return;
        }
        res.append(to_string(root->val));
        preorder(root->left, res);
        preorder(root->right,res);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string res1 = "", res2 = "";
        preorder(p, res1);
        preorder(q, res2);

        return res1 == res2;
    }
};
