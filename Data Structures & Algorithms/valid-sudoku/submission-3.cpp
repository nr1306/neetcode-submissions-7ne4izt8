class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> rows;
        map<char,int> cols;
        map<pair<int,int>, map<char,int>> cross_cols;
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '.') continue;

                if(rows[board[i][j]] == 1) return false;
                rows[board[i][j]] = 1;

                pair<int,int> sq_index = {i/3, j/3};
                if(cross_cols[sq_index][board[i][j]] == 1) return false;
                cross_cols[sq_index][board[i][j]] = 1;
            }
            rows.clear();
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(board[i][j] == '.') continue;
                
                if(cols[board[i][j]] == 1) return false;
                cols[board[i][j]] = 1;
            }
            cols.clear();
        }

        return true;
    }
};
