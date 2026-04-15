class Solution {
public:
    void solve(vector<vector<string>>& res, vector<string>& board,
    int n, int col, vector<int> samerow, vector<int> lowerdiagonal, 
    vector<int> upperdiagonal){
        if(col == n){
            res.push_back(board);
            return;
        }

        for(int row = 0 ; row<n; row++){
            if(!samerow[row] && 
            !lowerdiagonal[row+col] && 
            !upperdiagonal[n-1 + col-row]){

                samerow[row] = 1;
                lowerdiagonal[row+col] = 1;
                upperdiagonal[n-1 + col-row] = 1;
                board[row][col] = 'Q';

                solve(res,board,n,col+1, samerow, lowerdiagonal, upperdiagonal);

                board[row][col] = '.';
                lowerdiagonal[row+col] = 0;
                upperdiagonal[n-1 + col-row] = 0;
                samerow[row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        
        vector<string> board(n);
        string s (n,'.');
        for(int i=0; i<n; i++) board[i] = s;

        vector<int> lowerdiagonal(2*n-1, 0);
        vector<int> upperdiagonal(2*n-1,0);
        vector<int> samerow (n,0);
        
        solve(res,board,n,0, samerow, lowerdiagonal, upperdiagonal);
        return res;
    }
};
