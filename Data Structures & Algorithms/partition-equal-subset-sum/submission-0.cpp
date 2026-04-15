class Solution {
public:

    bool solve(vector<int>& nums, int i, int target){
        if(i == nums.size()){
            if(target == 0) return true;
            return false;
        }

        if(nums[i] <= target){
            if(solve(nums,i+1,target-nums[i])) return true;
        }
        return solve(nums,i+1,target);
    }

    bool canPartition(vector<int>& nums) {
    // Intuition: We are told to divide the array into 2 parts where sum s1 and sum s2 are both equal
    // It means, s1 will be s/2 (Where s is the sum of array)
    // If sum of all elements of array is odd, that is not possible
    // So we are gonna find one subset of sum equal to s/2, if we found one then there definitely be a second subset of sum s/2
        int sum = 0;
        for(int x : nums) sum += x;
        
        if(sum%2 != 0) return false;
        
        int target = sum/2;
        return solve(nums, 0, target);    
    }
};
