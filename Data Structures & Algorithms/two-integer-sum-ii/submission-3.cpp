class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() == 2){
            res.push_back(1);
            res.push_back(2);
            return res;
        }
        
        int left = 0, right = nums.size()-1;

        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if(sum < target) left++;
            else right--;
        }
        return res;
    }
};
