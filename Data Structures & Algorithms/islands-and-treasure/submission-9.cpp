class Solution {
public:

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int steps){

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
    // It will give you TLE if dont track the points u have visited
    // It might be the case that farther treasure chest could also visit a nearer point again and perform extra bfs

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};

                for(int i=0; i<4; i++){
                    int nrow = row+delrow[i];
                    int ncol = col+delcol[i];

            // grid[nrow][ncol] > 0, coz this could be the cell we are traversing twice from nearest treasrue chest
            // earlier we would have traveled this cell from farther chest
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    vis[nrow][ncol] == -1 && grid[nrow][ncol] > 0){
                        grid[nrow][ncol] = min(steps, grid[nrow][ncol]);
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
            steps++;
        }

    }

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

        int steps = 1;
        bfs(grid, q, steps);
    }
};
