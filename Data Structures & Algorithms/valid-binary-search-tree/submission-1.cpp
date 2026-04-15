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
    void inorder(TreeNode* root, vector<int>& elements){
        if(!root) return ;

        inorder(root->left, elements);
        elements.push_back(root->val);
        inorder(root->right, elements);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> elements;
        inorder(root,elements);
        int size = elements.size();
        for(int i=1; i<size; i++){
            if(elements[i] <= elements[i-1]) 
                return false;
        }
        return true;
    }
};
