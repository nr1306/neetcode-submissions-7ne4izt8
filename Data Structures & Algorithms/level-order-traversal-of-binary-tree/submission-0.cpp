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
    void bfs(TreeNode* root, vector<vector<int>>& level){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> elements;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                elements.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            level.push_back(elements);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        bfs(root, level);
        return level;
    }
};
