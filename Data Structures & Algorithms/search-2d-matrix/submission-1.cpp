class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(vector<int> row : matrix){
            int m = row.size();
            if(target>= row[0] && target<= row[m-1]){
                int start = 0, end = m-1;
                while(start <= end){
                    int mid = start+(end-start)/2;
                    if(row[mid] == target) return true;
                    else if(row[mid] < target) start = mid+1;
                    else end = mid-1;
                }
            }
        }
        return false;
    }
};
