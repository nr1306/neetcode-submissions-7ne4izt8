class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        vector<int> res(2);
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                res[0] = i+1;
                res[1] = j+1;
                break;
            }
            else if(sum < target) i++;
            else j--;
        }

        return res;
    }
};
