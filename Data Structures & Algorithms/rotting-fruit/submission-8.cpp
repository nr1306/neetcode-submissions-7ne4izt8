class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, 
    int& freshCount, int& time){
        int n = grid.size();
        int m = grid[0].size(); 

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

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        freshCount--;
                        q.push({nrow,ncol});
                    }
                }
            }
            time++;
        }   
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int freshCount = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    freshCount++;
            }
        }
        if(!freshCount) return 0; // there are no fresh oranges initially

        int time = 0;
        bfs(grid, q, freshCount, time);

        if(freshCount) return -1; // if all the fresh oranges are not turned into rotten one
        return time-1;
    }
};
