class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));
        int maxArea = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1){
                    int count = 1;
                    vis[i][j] = 1;
                    dfs(grid, vis, i, j, count);
                    maxArea = max(maxArea, count);
                }
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
    int row, int col, int& count){
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            vis[nrow][ncol] == -1 && grid[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                count++;
                dfs(grid,vis,nrow,ncol,count);
            }
        }
    }
};
