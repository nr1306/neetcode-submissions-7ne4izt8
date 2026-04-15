class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,
    int r, int c){
        int n = grid.size();
        int m = grid[0].size();

        int deltarow[] = {-1,0,1,0};
        int deltacol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r+deltarow[i];
            int ncol = c+deltacol[i];

            if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] == -1 && grid[nrow][ncol] == '1'){
                vis[nrow][ncol] = 1;
                dfs(grid, vis, nrow, ncol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        int count = 0; // number of islands

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == -1){
                    vis[i][j] = 1;
                    dfs(grid, vis, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
