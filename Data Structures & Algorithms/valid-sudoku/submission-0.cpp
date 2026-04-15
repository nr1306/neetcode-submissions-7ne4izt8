class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        map<char, int> rows, cols;
        map<pair<int,int>,map<char,int>> squares;

        // Iterating rows
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '.') continue;
                if(rows[board[i][j]])
                    return false;
                rows[board[i][j]]++;

                pair<int,int> grid_pair = {i/3, j/3};
                if(squares[grid_pair][board[i][j]])
                    return false; 
                squares[grid_pair][board[i][j]]++;
            }
            rows.clear();
        }

        //Iterating columns
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(board[i][j] == '.') continue;
                if(cols[board[i][j]])
                    return false;
                cols[board[i][j]]++;
            }
            cols.clear();
        }
        return true;
    }
};
