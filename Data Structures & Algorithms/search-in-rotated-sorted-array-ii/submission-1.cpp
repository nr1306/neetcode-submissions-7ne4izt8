class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end){
            while(end-1 >= 0 && nums[end-1] == nums[end]){
                end--;
            }
            while(start+1 < nums.size() && nums[start] == nums[start+1]){
                start++;
            }
            int mid = (end-start)/2 + start;
            if(nums[mid] == target) return true;
            else if(nums[mid] >= nums[start]){
                if(target <= nums[mid] && target >= nums[start])
                    end = mid-1;
                else start = mid+1;
            }
            else{
                if(target >= nums[mid] && target <= nums[end])
                    start = mid+1;
                else end = mid-1;
            }
        }
        return false;
    }
};