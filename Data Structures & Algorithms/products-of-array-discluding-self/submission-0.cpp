class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1,count0=0;
        for(int x : nums){
            if(x) mul *= x;
            else count0++;
        }

        vector<int> res(nums.size());
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            if(count0 > 1 || (x && count0 == 1)){
                res[i] = 0;
            }
            else if(!x && count0 == 1){
                res[i] = mul;
            }
            else{
                res[i] = mul/x;
            }     
        }
        return res;
    }
};
