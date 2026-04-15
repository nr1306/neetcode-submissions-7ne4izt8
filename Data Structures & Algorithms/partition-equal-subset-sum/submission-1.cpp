class Solution {
public:

    bool solve(vector<int>& nums, int i, int target,
    vector<vector<bool>>& dp){
        if(i == nums.size()){
            if(target == 0) return true;
            return false;
        }

        if(dp[i][target]) return dp[i][target];

        if(nums[i] <= target){
            if(solve(nums,i+1,target-nums[i],dp)) return dp[i][target]=true;
        }
        return dp[i][target]=solve(nums,i+1,target,dp);
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
        
        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1,false));

        return solve(nums, 0, target, dp);    
    }
};
