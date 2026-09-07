class Solution {
public:
    void pacificRim(vector<vector<int>>& heights, 
    vector<vector<int>>& vis, int r, int c){
        int n = heights.size();
        int m = heights[0].size();

        if(vis[r][c] == 1) return;
        vis[r][c] = 1;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&  
            heights[r][c] <= heights[nrow][ncol]){
                pacificRim(heights, vis, nrow, ncol);
            }
        }
    }

    void atlanticRim(vector<vector<int>>& heights, 
    vector<vector<int>>& vis, vector<vector<int>>& res, int r, int c){
        int n = heights.size();
        int m = heights[0].size();

        if(vis[r][c] == 2) return;
        if(vis[r][c] == 1) res.push_back({r,c});
        vis[r][c] = 2;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&  
            heights[r][c] <= heights[nrow][ncol]){
                atlanticRim(heights, vis, res, nrow, ncol);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));

        // Pacific Rim

        for(int j=0; j<m; j++){
            pacificRim(heights, vis, 0, j);
        }

        for(int i=0; i<n; i++){
            pacificRim(heights, vis, i, 0);
        }

        vector<vector<int>> res;

        // Atlantic Rim

        for(int i=0; i<n; i++){
            atlanticRim(heights, vis, res, i, m-1);
        } 

        for(int j=0; j<m; j++){
            atlanticRim(heights, vis, res, n-1, j);
        }

        return res;
    }
};
