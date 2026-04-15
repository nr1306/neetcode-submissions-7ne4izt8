class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        map<char, int> rows, cols;
        map<pair<int, int> , map<char, int>> squares;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '.') continue;
                if(rows[board[i][j]]) return false;
                rows[board[i][j]]++;

                pair<int,int> dim {i/3,j/3};
                if(squares[dim][board[i][j]]) return false;
                squares[dim][board[i][j]]++;
            }
            rows.clear();
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(board[i][j] == '.') continue;
                
                if(cols[board[i][j]]) return false;
                cols[board[i][j]]++;
            }
            cols.clear();
        }

        return true;
    }
};
