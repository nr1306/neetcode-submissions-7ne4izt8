class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int i, int& res){
        if(i == nums.size()){
            int tempRes = 0;
            for(int x : temp){
                tempRes ^= x;
            }
            res += tempRes;
            return;
        }

        solve(nums,temp,i+1,res);
        temp.push_back(nums[i]);
        solve(nums,temp,i+1,res);
        temp.pop_back();
    }

    int subsetXORSum(vector<int>& nums) {
        int i=0,res=0;
        vector<int> temp;
        solve(nums, temp, i, res);
        return res;
    }
};