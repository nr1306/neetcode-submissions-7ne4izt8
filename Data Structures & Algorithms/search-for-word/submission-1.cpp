class Solution {
public:
    void solve(vector<vector<char>>& board, string& word, 
    vector<vector<int>>& vis, int row, int col, int i, bool& res){
        int n = board.size();
        int m = board[0].size();

        if(i == word.size()){
            res = true;
            return;
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int j=0; j<4; j++){
            int nrow = row+delrow[j];
            int ncol = col+delcol[j];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            board[nrow][ncol] == word[i] && vis[nrow][ncol] == -1 && !res){
                cout << board[nrow][ncol] << " ";
                vis[nrow][ncol] = 1;
                solve(board, word, vis, nrow, ncol, i+1, res);
                vis[nrow][ncol] = -1;   
            }
        }

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        bool res = false;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    solve(board, word,vis,i,j,1,res);
                    vis[i][j] = -1;
                }
            }
        }
        return res;
    }
};
