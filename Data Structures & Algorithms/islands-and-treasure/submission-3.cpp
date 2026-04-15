class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
    queue<pair<int,int>>& q, int dist){
        int n = grid.size();
        int m = grid[0].size();
        int INF = INT_MAX;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                int deltarow[] = {-1,0,1,0};
                int deltacol[] = {0,1,0,-1};

                for(int i=0; i<4; i++){
                    int nrow = row + deltarow[i];
                    int ncol = col + deltacol[i];

                // grid value should not be water
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    vis[nrow][ncol] == -1 && grid[nrow][ncol] > 0){
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = min(grid[nrow][ncol], dist);
                        q.push({nrow,ncol});
                    }
                }
            }
            dist++; // After we take 1 step from every treasure chest
        }

    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j}); // Inserting all the treasure chest location then we'll explore all paths together
                }
            }
        }
        bfs(grid, vis, q, 1);
    }
};
