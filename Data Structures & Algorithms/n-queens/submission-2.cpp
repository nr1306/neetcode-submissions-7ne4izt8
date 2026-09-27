class Solution {
public:
    vector<bool> samecol;
    vector<bool> posDiag;
    vector<bool> negDiag;
    vector<vector<string>> res;
    
    void solve(vector<string>& board, int r, int n){
        if(r == n){
            res.push_back(board);
            return;
        }

// We are gonna move row by row and place the queen so we dont have to maintain anything for rows
// We are gonna fit queen in a row by moving through columns once we do that will move to next row and find a possible valid location for queen
// Then will backtrack and try diff column combo

        for(int c = 0; c<n; c++){
            if(!samecol[c] && !posDiag[r+c] && !negDiag[r-c+n]){
                samecol[c] = true;
                posDiag[r+c] = true;
                negDiag[r-c+n] = true;
                board[r][c] = 'Q';

                solve(board, r+1, n);

                samecol[c] = false;
                posDiag[r+c] = false;
                negDiag[r-c+n] = false;
                board[r][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        samecol.resize(n,false);
        posDiag.resize(2*n, false);
        negDiag.resize(2*n, false);

        vector<string> board(n,string(n,'.'));

        solve(board, 0, n);

        return res;
    }
};
