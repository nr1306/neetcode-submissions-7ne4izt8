class Solution {
public:
    bool f(vector<int>& nums, int i){
        if(i >= nums.size()-1) return true;
        if(!nums[i]) return false;

        for(int steps = nums[i] ; steps >= 1; steps--){
            if(f(nums,i+steps)) return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        return f(nums,0);
    }
};
