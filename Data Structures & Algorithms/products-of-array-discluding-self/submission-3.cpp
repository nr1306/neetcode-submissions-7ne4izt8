class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        int count0 = 0;
        for(int x : nums){
            if(x != 0)
                mul *= x;
            else count0++;
        }

        vector<int> res;
        for(int x : nums){
            if(x == 0){
                if(count0 > 1) res.push_back(0);
                else res.push_back(mul);
            }
            else{
                if(count0 >= 1) res.push_back(0);
                else res.push_back(mul/x);
            }
        }
        return res;
    }
};
