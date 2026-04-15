class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];

        int start = 0, end = nums.size()-1;
        int mini = INT_MAX;
        while(start <= end){
            int mid = (end-start)/2 + start;

// left part of array is sorted, so i'll just compare the min value of that subarray
            if(nums[start] <= nums[mid]){
                mini = min(mini, nums[start]);
                start = mid+1;
            }
// right part of array is sorted, i'll compare the min or first value of that subarray
            else{
                mini = min(mini, nums[mid]);
                end = mid-1;
            }
        }
        return mini;
    }
};
