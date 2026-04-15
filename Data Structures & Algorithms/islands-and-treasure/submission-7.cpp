class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
// We need / must explore all treasure chest points at same time eacch step in every direction from treasure chest will steps dist from it
// To avoid visiting twice the same node vis array is required

        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};

                for(int i=0; i<4; i++){
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];

                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 &&
                    !vis[nrow][ncol] && grid[nrow][ncol] > 0){
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = min(grid[nrow][ncol], steps);
                        q.push({nrow,ncol});
                    }
                }
            }
            steps++;
        }
    }
};
