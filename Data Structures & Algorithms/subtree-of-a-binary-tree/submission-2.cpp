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
        preorder(root->right, res);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string res = "";
        preorder(root, res);
        string subRes = "";
        preorder(subRoot, subRes);
        
        return res.find(subRes) != std::string::npos;
    }
};
