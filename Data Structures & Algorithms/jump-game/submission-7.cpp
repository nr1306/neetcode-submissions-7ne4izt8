class Solution {
public:
    bool canJump(vector<int>& nums) {
        int coverage = 0;
        int lastJumpIndex = 0;
        int n = nums.size();
        if(nums.size() == 1) return true;
        
        for(int i=0; i<n; i++){
            coverage = max(coverage , i+nums[i]);
            if(i == coverage && !nums[i]) return false;

            if(i == lastJumpIndex){
                lastJumpIndex = coverage;
            }

            if(coverage >= n-1)
                return true;
        }
        return false;
    }
};
