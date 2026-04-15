class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

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
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(!q.empty())
                time++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
