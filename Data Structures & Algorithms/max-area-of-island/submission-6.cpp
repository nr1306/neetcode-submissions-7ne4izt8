class Solution {
public:
    void dfs(vector<vector<int>>& grid,
    int r, int c, int& count){
        int n = grid.size();
        int m = grid[0].size();

        count++;
        grid[r][c] = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            grid[nrow][ncol] == 1){        
                dfs(grid,nrow, ncol,count);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];

        int maxi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    dfs(grid, i, j, count);
                    maxi = max(maxi, count);
                }
            }
        }

        return maxi;   
    }
};
