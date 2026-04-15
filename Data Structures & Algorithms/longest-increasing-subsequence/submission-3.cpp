class Solution {
public:
    int solve(vector<int>& nums, int i, int prev_ind, vector<vector<int>>& dp){
        if(i == nums.size()){
            return 0;
        }

        if(dp[i][prev_ind+1] != -1) return dp[i][prev_ind+1];

    // not taking the curr element 
        int len = 0 + solve(nums,i+1, prev_ind, dp);

    // checking the ith element, if its the first ele of sequence then take it
        if(prev_ind == -1 || (nums[i] > nums[prev_ind])){
            len = max(len, 1+solve(nums,i+1,i,dp));
        }

        return dp[i][prev_ind+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev_ind = -1;
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size(), -1));
    // i will move from 0 - n-1 
    // prev_ind move from -1 to n-2, so we'll use prev_ind+1 to prevent out of bounds error
        return solve(nums, 0, prev_ind, dp);
    }
};
