class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i=0, j=nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum < target) i++;
            else if(sum > target) j--;
            else{
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
        }
        return res;
    }
};
