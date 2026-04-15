class Solution {
public:

    vector<vector<int>> res;

    void pacificRim(vector<vector<int>>& heights, 
    vector<vector<int>>& grid, int r, int c){
        if(grid[r][c] == 1) return; // It is already marked
        grid[r][c] = 1; // marking 1 for pacific

        int n = heights.size();
        int m = heights[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            heights[nrow][ncol] >= heights[r][c]){
    // We are starting from pacific borders, if we can visit this cell then water from [nrow,ncol] cell will go to pacific
                pacificRim(heights,grid,nrow,ncol);
            }
        }
    }

    void atlanticRim(vector<vector<int>>& heights, 
    vector<vector<int>>& grid, int r, int c){
        if(grid[r][c] == 1){
            vector<int> coord {r,c};
            res.push_back(coord);
        } // It is already marked pacific and this cell is going in atlantic as well
        if(grid[r][c] == 2) return; // already marked
        
        grid[r][c] = 2; // marking 2 for atlantic after checking the grid value so that we won't overwrite if its already marked as 1

        int n = heights.size();
        int m = heights[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            heights[nrow][ncol] >= heights[r][c]){
    // We are starting from pacific borders, if we can visit this cell then water from [nrow,ncol] cell will go to pacific
                atlanticRim(heights,grid,nrow,ncol);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if(n == 0) return res;
        int m = heights[0].size();
        vector<vector<int>> grid(n, vector<int>(m,-1)); // to mark pacific and atlantic

// First traversing pacific border
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0){
                    pacificRim(heights,grid,i,j);
                }
            }
        }

        // First traversing atlantic border
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == n-1 || j == m-1){
                    atlanticRim(heights,grid,i,j);
                }
            }
        }

        
        return res;
    }
};
