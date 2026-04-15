class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]) mul *= nums[i];
            else count++;
        }

        vector<int> res(nums.size(),0);
        if(count>1) return res;

        for(int i=0; i<nums.size(); i++){
            if(!nums[i]) res[i] = mul;
            else if(count) res[i] = 0;
            else res[i] = mul/nums[i];
        }

        return res;
    }
};
