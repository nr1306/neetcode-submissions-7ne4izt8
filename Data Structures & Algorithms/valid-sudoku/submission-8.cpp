class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        map<char,bool> rows, cols;
        map<pair<int,int> , map<char,bool>> diagonal;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            
                char curr = board[i][j];
                if(curr == '.') continue;
            
                if(rows[curr]) return false;
                rows[curr] = true;

                pair<int,int> coord = {i/3, j/3};
                
                if(diagonal[coord][curr]) return false;
                diagonal[coord][curr] = true;
            }
            rows.clear();
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                
                char curr = board[i][j];
                if(curr == '.') continue;

                if(cols[curr]) return false;
                cols[curr] = true;
            }
            cols.clear();
        }

        return true;
    }
};
