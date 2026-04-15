class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;

        int mini = nums.size()+1;
        int prefixSum = 0;
        for(int i=0,j=0; j<nums.size(); j++){
            prefixSum += nums[j];
            while(prefixSum >= target){
                mini = min(mini, j-i+1);
                prefixSum -= nums[i];
                i++;
            }
        }
        if(mini == nums.size()+1) return 0;
        return mini;
    }
};