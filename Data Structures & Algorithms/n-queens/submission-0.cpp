class Solution {
public:
    bool isValidCell(int row, int col, vector<string>& board){
        int n = board.size();
        int tempRow = row, tempCol = col;

        // checking upper diagonal in left side
        while(tempRow >= 0 && tempCol >= 0){
            if(board[tempRow][tempCol] == 'Q') return false;
            tempCol--;
            tempRow--;
        }

        tempRow = row;
        tempCol = col;

        // checking the same row
        while(tempCol >= 0){
            if(board[row][tempCol] == 'Q') return false;
            tempCol--;
        }
        
        tempRow = row;
        tempCol = col;

        // checking lower diagonal in left side
        while(tempRow < n && tempCol >= 0){
            if(board[tempRow][tempCol] == 'Q') return false;
            tempCol--;
            tempRow++;
        }
        return true;

    }   

    void solve(vector<vector<string>>& res, vector<string>& board,
    int n, int col){
        if(col == n){
            res.push_back(board);
            return;
        }

        for(int row = 0 ; row<n; row++){
            if(isValidCell(row,col,board)){
                board[row][col] = 'Q';
                solve(res,board,n,col+1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s (n,'.');
        for(int i=0; i<n; i++) board[i] = s;
        solve(res,board,n,0);
        return res;
    }
};
