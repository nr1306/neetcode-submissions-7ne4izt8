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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    res.append(to_string(node->val)+"|");
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                    res.append("#|");

            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        string str;
        stringstream ss(data);
        getline(ss,str,'|');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                getline(ss,str,'|');
                if(str == "#") node->left = nullptr;
                else{
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                } 

                getline(ss,str,'|');
                if(str == "#") node->right = nullptr;
                else{
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                } 
            }
        }
        return root;
    }
};
