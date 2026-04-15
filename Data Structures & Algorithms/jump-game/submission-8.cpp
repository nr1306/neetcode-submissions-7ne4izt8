class Solution {
public:
    bool canJump(vector<int>& nums) {
        int coverage = 0;
        int lastJumpIndex = 0;
        int n = nums.size();
        if(nums.size() == 1) return true;

        for(int i=0; i<n; i++){
            coverage = max(coverage , i+nums[i]);
    // If we reach at the last pos in window and before we go further we need to make sure we can go further, by checking the val of nums[i]
    // If its non-zero then will move as it is , if not then that's the dead end
            if(i == coverage && !nums[i]) return false;

    // If we reach end of temp window will update the max coverage covered
            if(i == lastJumpIndex){
                lastJumpIndex = coverage;
            }

            if(coverage >= n-1)
                return true;
        }
        return false;
    }
};
