class Solution {
    struct Trie{
        Trie* ch[26];
        string word;

        Trie(){
            for(int i=0; i<26; i++)
                ch[i] = nullptr;
            word = "";
        }
    }*root;

public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,
    int row, int col, Trie* root, set<string>& res){
        int n = board.size();
        int m = board[0].size();

        if(root->word.size()){
            res.insert(root->word);
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            vis[nrow][ncol] == -1 && root->ch[board[nrow][ncol]-'a']){
                vis[nrow][ncol] = 1;
                dfs(board, vis, nrow, ncol, 
                root->ch[board[nrow][ncol]-'a'], res);
                vis[nrow][ncol] = -1;
            }
        }
    }

    Trie* buildTrie(Trie* root, string word){
        Trie* curr = root;
        for(char alph : word){
            if(!root->ch[alph-'a'])
                root->ch[alph-'a'] = new Trie();
            root = root->ch[alph-'a'];
        }
        root->word = word;
        return curr;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        set<string> res;

        root = new Trie();
        for(int k=0; k<words.size(); k++){
            root = buildTrie(root, words[k]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(root->ch[board[i][j]-'a']){
                    vis[i][j] = 1;
                    dfs(board, vis, i, j, root->ch[board[i][j]-'a'],res);
                    vis[i][j] = -1;
                }
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
