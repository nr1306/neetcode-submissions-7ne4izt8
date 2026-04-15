class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;

        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = (end-start)/2 + start;
            if(nums[mid] == target) return mid;
// left part of array is sorted, so i'll just find the value in that subarray
            else if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target <= nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
// right part of array is sorted, i'll compare the min or first value of that subarray
            else{
                if(target >= nums[mid] && target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return -1;
    }
};
