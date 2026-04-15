struct Trie{
    Trie* ch[26];
    string word = "";
    Trie(){
        for(int i=0; i<26; i++) ch[i] = nullptr;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, 
    vector<string>& words, int& row, int& col, set<string>& res, Trie* root){
        if(root->word.size()) res.insert(root->word);

        int n = board.size(), m = board[0].size();
        vis[row][col] = 1;

        int r[] = {-1,0,1,0};
        int c[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = row + r[i];
            int ncol = col + c[i];

            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] == -1){
                int letter = board[nrow][ncol] - 'a';
                if(root->ch[letter]){
                    dfs(board, vis, words, nrow, ncol, res, root->ch[letter]);
                    vis[nrow][ncol] = -1;
                }
            }
        }
    }

    Trie* buildTree(Trie* root, vector<string>& words){
        for(string word : words){
            
            Trie* temp = root;
            int size = word.size();
            
            for(int i=0; i<size; i++){
                int letter = word[i]-'a';
                if(temp->ch[letter] == nullptr){
                    temp->ch[letter] = new Trie();
                }
                temp = temp->ch[letter];
            }
            temp->word = word;
        }

        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        Trie* root = new Trie();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        set<string> res;
        
        root = buildTree(root, words);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int letter = board[i][j] - 'a';
                if(root->ch[letter]){
                    dfs(board, vis, words, i, j, res, root->ch[letter]);
                    vis[i][j] = -1; // marking this node unvisit again
                }
            }
        }

        vector<string> ans {res.begin(),res.end()};
        return ans;
    }
};
