class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, sum = 0;
        int n = nums.size();
        int mini = INT_MAX;
        for(; j<n; j++){
            sum += nums[j];
            while(i<=j && sum >= target){
                mini = min(mini, j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};