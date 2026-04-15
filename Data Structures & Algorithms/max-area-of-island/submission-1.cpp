class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
    int r, int c, int& area){
        int n = grid.size();
        int m = grid[0].size();

        int deltarow[] = {-1,0,1,0};
        int deltacol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r+deltarow[i];
            int ncol = c+deltacol[i];

            if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] == -1 && grid[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                area++;
                dfs(grid, vis, nrow, ncol, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        int area = 0,maxArea = 0; // number of islands

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1){
                    vis[i][j] = 1;
                    area++;
                    dfs(grid, vis, i, j, area);
                    maxArea = max(maxArea, area);
                    area = 0; // Value to 0 to count area of other islands
                }
            }
        }

        return maxArea;
    }
};
