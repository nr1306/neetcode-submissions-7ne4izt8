class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q){

        int n = grid.size();
        int m = grid[0].size();

        int time = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,-1,0,1};

                for(int i=0; i<4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(!q.empty())
                time++;
        }

        return time;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        int time = bfs(grid,q);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};
