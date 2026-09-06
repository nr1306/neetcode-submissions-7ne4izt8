class Solution {
public:
    int INF = 2147483647;

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, 
    queue<pair<int,int>>& q){
        int n = grid.size();
        int m = grid[0].size();
        int dist = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                
                q.pop();

// exploring in 4 directions from (row,col) - all at same distance
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};

                for(int i=0; i<4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    vis[nrow][ncol] == -1 && grid[nrow][ncol] > 0){
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = min(grid[nrow][ncol], dist);
                        q.push({nrow,ncol});
                    } 
                }
            }
            dist++;
        }

    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,-1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        bfs(grid, vis, q);
    }
};
