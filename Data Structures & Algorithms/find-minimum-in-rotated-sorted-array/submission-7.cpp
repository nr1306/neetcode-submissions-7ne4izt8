class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0 ,r = nums.size()-1;
        int res = INT_MAX;
        while(l <= r){
            if(nums[l] < nums[r]){ // it means the range we are in is sorted
                res = min(res, nums[l]);
                break;
            }

            int mid = (r-l)/2 + l;
            res = min(nums[mid] , res);

            if(nums[mid] >= nums[l]) l = mid+1; // left part is sorted
            else r = mid-1; // right part is sorted
        }
        return res;
    }
};
