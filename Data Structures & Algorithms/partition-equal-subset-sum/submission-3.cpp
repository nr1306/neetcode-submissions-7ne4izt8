class Solution {
public:
    // Always remember whenever you are asked to find the subsequence / subset of elements of sum == target
    // Make dp of size target+1, coz in that case dp of dimension index doesn't make any sense, if you are ith index you will find sum == target that is not true
    // But if you are the current target then you can tell whether that is possible with elements in the array or not

    bool solve(vector<int>& nums, int i, int target, vector<int>& dp){
        if(i == nums.size()){
            return target == 0;
        }

        if(dp[target] != -1) return dp[target];

        bool res = false;
        if(nums[i] <= target)
            res = solve(nums,i+1,target-nums[i],dp);
        
        return dp[target] = res || solve(nums,i+1,target,dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum%2 != 0) return false; // coz then its not possible to divide the sum into 2 parts evenly

        int target = sum/2;
        vector<int> dp(target+1, -1);
        return solve(nums,0,target,dp);
    }
};
