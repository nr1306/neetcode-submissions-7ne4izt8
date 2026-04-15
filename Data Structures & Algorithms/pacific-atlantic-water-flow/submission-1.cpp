class Solution {
public:
    void pacificRim(vector<vector<int>>& heights, vector<vector<int>>& grid,
    int r, int c){
        if(grid[r][c] == 1) return; // if already visited
        grid[r][c] = 1; // mark it visited

        int n = heights.size();
        int m = heights[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && 
            heights[nrow][ncol] >= heights[r][c]){
                pacificRim(heights,grid,nrow,ncol);
            }
        }
    }

    void atlanticRim(vector<vector<int>>& heights, vector<vector<int>>& grid,
    int r, int c, vector<vector<int>>& res){
        if(grid[r][c] == 2) return; // already visited in atlanticRim
        if(grid[r][c] == 1){ // if this cell is already visited in pacificRim we'll insert the points into res
            res.push_back({r,c});
        }
        grid[r][c] = 2; // mark it visited

        int n = heights.size();
        int m = heights[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && 
            heights[nrow][ncol] >= heights[r][c]){
                atlanticRim(heights,grid,nrow,ncol,res);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> grid(n, vector<int>(m,0));

// Exploring pacific Area , First row and first column
        for(int i=0; i<n; i++){
            pacificRim(heights,grid,i,0);
        }
        
        for(int j=0; j<m; j++){
            pacificRim(heights,grid,0,j);
        }
        
        vector<vector<int>> res;
        // Exploring Atlantic Area , First row and first column
        for(int i=0; i<n; i++){
            atlanticRim(heights,grid,i,m-1,res);
        }
        
        for(int j=0; j<m; j++){
            atlanticRim(heights,grid,n-1,j,res);
        }

        return res;
    }
};
