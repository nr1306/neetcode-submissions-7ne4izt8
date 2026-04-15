class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> rows;
        map<char,int> col;
        map<pair<int,int>, map<char,int>> squared;

        int n = board.size(), m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '.') continue;
                if(rows[board[i][j]]) return false;

                rows[board[i][j]] = 1;
                
                pair<int,int> sq_pair = {i/3,j/3};
                if(squared[sq_pair][board[i][j]]) return false;
                squared[sq_pair][board[i][j]] = 1;
            }
            rows.clear();
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(board[i][j] == '.') continue;
                if(col[board[i][j]]) return false;
                
                col[board[i][j]] = 1;
            }
            col.clear();
        }
        return true;
    }
};
