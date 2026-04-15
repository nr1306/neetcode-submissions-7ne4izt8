class Solution {
public:
    void pacificRim(vector<vector<int>>& heights, vector<vector<int>>& vis, 
    int row, int col){
        int n = heights.size();
        int m = heights[0].size();

        if(vis[row][col] == 1) return;
        vis[row][col] = 1;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            heights[row][col] <= heights[nrow][ncol]){
                pacificRim(heights, vis, nrow, ncol);
            }
        }
    }

    void atlanticRim(vector<vector<int>>& heights, vector<vector<int>>& vis,
    vector<vector<int>>& coord, int row, int col){
        int n = heights.size();
        int m = heights[0].size();

        if(vis[row][col] == 2) return;
        if(vis[row][col] == 1) coord.push_back({row,col});
        vis[row][col] = 2;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            heights[row][col] <= heights[nrow][ncol]){
                atlanticRim(heights, vis, coord, nrow, ncol);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));

        vector<vector<int>> coord;

    // PacificRim
        for(int i=0; i<n; i++){
            pacificRim(heights, vis, i, 0);
        }

        for(int j=0; j<m; j++){
            pacificRim(heights, vis, 0, j);
        }

    // AtlanticRim
        for(int i=0; i<n; i++){
            atlanticRim(heights, vis, coord, i, m-1);
        }

        for(int j=0; j<m; j++){
            atlanticRim(heights, vis, coord, n-1, j);
        }

        return coord;
    }
};
