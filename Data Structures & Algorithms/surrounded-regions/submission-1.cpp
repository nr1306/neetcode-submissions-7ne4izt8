class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,
    int r, int c){
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            vis[nrow][ncol] == -1 && board[nrow][ncol] == 'O'){
                vis[nrow][ncol] = 1;
                board[nrow][ncol] = '#'; // marking this O node
                dfs(board,vis,nrow,ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        // Here condition is on border 'o's so we'll start from border o's
        // And if we are able to traverse other o's then it means they are not captured ones so we'll mark them  
        // After dfs traversals if any cell is 'o' that means they are captured ones
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) &&
                vis[i][j] == -1 && board[i][j] == 'O'){
                    vis[i][j] = 1;
                    board[i][j] = '#'; // marking this O node
                    dfs(board,vis,i,j);
                }
            }
        }

        // Now we'll convert all the surrounded ones
        // coz now remaining O's are surrounded and couldn't reach by corner Os

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O'; // unmarking the node
            }
        }
    
    }
};
