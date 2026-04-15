class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size()-1;
        int mini = INT_MAX;
        while(start <= end){
            int mid = (end-start)/2 + start;
            if(nums[start] <= nums[mid]){ // If left part of array is sorted
                mini = min(mini, nums[start]);
                start = mid+1;
            }
            else{
                mini = min(mini, nums[mid]);
                end = mid-1;
            }
        }

        return mini;
    }
};
