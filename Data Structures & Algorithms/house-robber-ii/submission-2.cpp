class Solution {
public:
    int f(vector<int>& nums, int i, vector<int>& dp){
        int n = nums.size();
        if(i < 0){
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int money1 = nums[i] + f(nums,i-2,dp);
        int money2 = 0 + f(nums,i-1,dp);

        return dp[i] = max(money1, money2);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        vector<int> dp1(nums.size()-1, -1) , dp2(nums.size()-1, -1);
        
        vector<int> temp1(nums.begin() , nums.begin()+(nums.size()-1));
        int money1 = f(temp1, temp1.size()-1, dp1);

        vector<int> temp2 (nums.begin()+1, nums.end());
        int money2 = f(temp2, temp2.size()-1, dp2);

        return max(money1, money2);
    }
};
