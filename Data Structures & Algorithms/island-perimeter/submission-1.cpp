class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& vis,
    int r, int c){
        int n = grid.size();
        int m = grid[0].size();


        if(r >= n || r < 0 || c >= m || c < 0 || grid[r][c] == 0)
            return 1;

        if(vis[r][c] == 1) return 0;
        vis[r][c] = 1; // mark it as visited

        int peri = 0;
        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};

        for(int i=0; i<4; i++){
            int nrow = r + row[i];
            int ncol = c + col[i];

            peri += solve(grid,vis,nrow,ncol);
        }

        return peri;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,-1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1){
                    return solve(grid,vis,i,j);
                }
            }
        }

        return -1;
    }
};