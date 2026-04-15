class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = (end+start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(vector<int> row : matrix){
            int m = row.size();
            if(target >= row[0] && target <= row[m-1] && search(row,target) != -1)
                return true;
        }
        return false;
    }
};
