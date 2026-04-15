class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // First we don't need negative numbers as they won't be res ever
        // Marking them as 0

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0) nums[i] = 0;
        }

        // Now we are going to iterate through the array, and if the val is positive and inbounds [1,len(nums)] then we'll make it negative and it will mark that index+1 element is present
        // If the number is 0 then we can't make it negative, so we'll assign at that index the biggest possible value which is len(nums)
        // If it is already negative it means that index is already marked
        // Also remember in back of our mind, we are trying to make this given nums array into solution array containing elements [1,len(nums)] (All positive integers)

        for(int i=0; i<nums.size(); i++){
            int val = abs(nums[i]);
            if(val >= 1 && val <= nums.size()){ // It means its inbound
                if(nums[val-1] > 0) nums[val-1] *= -1;
                else if(nums[val-1] == 0) nums[val-1] = -(nums.size()+1);
                // if its negative it means its already marked
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0) return i+1;
        }
        return nums.size()+1;
    }
};