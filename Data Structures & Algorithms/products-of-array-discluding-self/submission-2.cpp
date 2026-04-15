class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        int count = 0;
        for(int x : nums) {
            if(x) mul *= x;
            else count++;
        }

        vector<int> res(nums.size(),0);
        if(count > 1) return res;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            if(x){
                if(count) res[i] = 0;
                else res[i] = (mul/x);
            }
            else{
                res[i] = mul;
            }
        }
        return res;
    }
};
