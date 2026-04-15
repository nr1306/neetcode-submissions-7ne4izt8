class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, 
    int row, int col){
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            vis[nrow][ncol]== -1 && board[nrow][ncol] == 'O'){
                vis[nrow][ncol] = 1;
                dfs(board,vis,nrow,ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && 
                board[i][j] == 'O'){
                    vis[i][j] = 1;
                    dfs(board, vis, i, j);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && vis[i][j] == -1)
                    board[i][j] = 'X';
            }
        }
    }
};
