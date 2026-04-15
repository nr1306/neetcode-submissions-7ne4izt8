class NumMatrix {
public:
    vector<vector<int>> prefixM;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        prefixM.resize(n, vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0){
                    if(j == 0)
                        prefixM[i][j] = matrix[i][j];
                    else
                        prefixM[i][j] = matrix[i][j] + prefixM[i][j-1];
                }

                else if(j == 0){
                    prefixM[i][j] = matrix[i][j] + prefixM[i-1][j];
                }

                else{
                    prefixM[i][j] = matrix[i][j] + 
                    prefixM[i-1][j] + prefixM[i][j-1] - prefixM[i-1][j-1];
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << prefixM[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sumBiggerRect = prefixM[row2][col2];
        int del = 0;
        if(row1!=0) del += prefixM[row1-1][col2];
        if(col1 != 0) del += prefixM[row2][col1-1];
        if(row1 != 0 && col1!= 0) del -= prefixM[row1-1][col1-1];
        
        int res = sumBiggerRect - del;
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */