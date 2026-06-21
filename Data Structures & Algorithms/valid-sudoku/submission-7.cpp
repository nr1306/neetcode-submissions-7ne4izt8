class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        map<char, bool> rows;
        map<char, bool> cols;
        map<pair<int,int> , map<char,bool> >adj;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch = board[i][j];
                if(ch == '.') continue;

                if(rows[ch]) return false;
                rows[ch] = true;

                pair<int,int> ind {i/3,j/3};
                if(adj[ind][ch]) return false;
                adj[ind][ch] = true;
            }
            rows.clear();
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                char ch = board[i][j];
                if(ch == '.') continue;

                if(cols[ch]) return false;
                cols[ch] = true;
            }
            cols.clear();
        }

        return true;
    }
};
