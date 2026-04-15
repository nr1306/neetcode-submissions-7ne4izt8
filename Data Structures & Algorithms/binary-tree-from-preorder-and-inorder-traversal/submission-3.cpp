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
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd,
    vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap){
        
        if(inStart > inEnd || preStart > preEnd) return nullptr;

        int ele = preorder[preStart];
        int pos = inMap[ele];
        int numsleft = pos-inStart;

        TreeNode* root = new TreeNode(ele);

        root->left = solve(preorder, preStart+1, preStart+numsleft,
                    inorder, inStart, pos, inMap);

        root->right = solve(preorder, preStart+numsleft+1, preEnd,
                    inorder, pos+1, inEnd, inMap);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, inStart = 0;
        int preEnd = preorder.size()-1, inEnd = inorder.size()-1;
        map<int,int> inMap;
        for(int i=0; i<=inEnd; i++)
            inMap[inorder[i]] = i;

        return solve(preorder, preStart, preEnd, inorder, inStart, inEnd, inMap);
    }
};
