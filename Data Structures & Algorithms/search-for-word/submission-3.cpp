class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& vis,
    string word, int ind, int r, int c){
        int n = board.size();
        int m = board[0].size();

        if(ind == word.size()) return true;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] == -1 && board[nrow][ncol] == word[ind]){
                vis[nrow][ncol] = 1;
                cout << board[nrow][ncol] << " ";
                if(dfs(board,vis, word, ind+1, nrow, ncol)) 
                    return true;
                vis[nrow][ncol] = -1;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<int>> vis(n, vector<int>(m,-1));
                if(board[i][j] == word[0]){
                    cout << i << " " << j << endl; 
                    vis[i][j] = 1;
                    if(dfs(board, vis, word, 1, i, j))
                        return true;
                    vis[i][j] = -1;
                }
            }
        }
        return false;
    }
};
