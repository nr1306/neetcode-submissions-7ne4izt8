class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
    queue<pair<int,int>>& q, int& time){
        int n = grid.size(); 
        int m = grid[0].size();

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

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    vis[nrow][ncol] == -1 && grid[nrow][ncol] == 1){
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(!q.empty()) // if they found fresh oranges
                time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,-1));
        queue<pair<int,int>> q;
        
        int time = 0; // In 0th minute we'll see neighbour of rotten fruit which shouldn't count
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    // pushing every rotten oranges in queue first
                    // Then we'll explore all their neighbours at once
                    q.push({i,j});
                }
            }
        }

        bfs(grid, vis, q, time);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
