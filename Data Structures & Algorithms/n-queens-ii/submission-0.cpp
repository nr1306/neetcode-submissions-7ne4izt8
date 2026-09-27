class Solution {
public:
    vector<bool> samecol , posDiag , negDiag;
    vector<vector<string>> res;

    void solve(vector<string>& board, int r, int n){
        if(r == n){
            res.push_back(board);
            return;
        }

        for(int c = 0; c<n; c++){
            if(!samecol[c] && !posDiag[r+c] && !negDiag[r-c+n]){
                samecol[c] = true;
                posDiag[r+c] = true;
                negDiag[r-c+n] = true;
                board[r][c] = 'Q';

                solve(board,r+1,n);

                samecol[c] = false;
                posDiag[r+c] = false;
                negDiag[r-c+n] = false;
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

    }
    
    int totalNQueens(int n) {
// We are going keep track of columns

// Will maintain Positive diagonal which includes indices - (3,0),(2,1),(1,2),(0,3) -> You can observe their sum r+c is equal throughout

// And will keep track of negative diagonal which includes - (3,3),(2,2),(1,1),(0,0) -> You can see that when u subtract r-c (which is constant) but it could be negative so will add n (size) to "r-c" result

        samecol.resize(n,false);
        posDiag.resize(2*n, false);
        negDiag.resize(2*n, false);

        vector<string> board(n,string(n,'.'));

// We are gonna iterate row by row
        solve(board,0,n);

        return res.size();
    }
};