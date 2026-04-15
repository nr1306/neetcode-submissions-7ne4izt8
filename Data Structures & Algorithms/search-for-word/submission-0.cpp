class Solution {
public:
    bool search(vector<vector<char>>& board, vector<vector<int>>& vis, 
    string word, int r, int c, int k){
        int n = board.size();
        int m = board[0].size();

        if(k == word.size()) return true;
 
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r + row[i];
            int ncol = c + col[i];

            if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] == -1 && board[nrow][ncol] == word[k]){
                vis[nrow][ncol] = 1;
                if(search(board,vis,word,nrow,ncol,k+1)) 
                    return true;
                vis[nrow][ncol] = -1;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(search(board,vis, word, i,j,1))
                        return true;
                    vis[i][j] = -1;
                }
            }
        }
        return false;
    }
};
