class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, bool> rows,cols;
        map<pair<int,int>, map<char,bool> > diagonal;

        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch = board[i][j];
                if(ch == '.') continue;
                
                if(rows[ch])
                    return false;
                
                rows[ch] = true;
            }
            rows.clear();
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                char ch = board[i][j];
                if(ch == '.') continue;
                
                if(cols[ch])
                    return false;
                cols[ch] = true;

                pair<int,int> diag {i/3, j/3};
                if(diagonal[diag][ch])
                    return false;
                
                diagonal[diag][ch] = true;
            }
            cols.clear();
        }

        return true;

    }
};
