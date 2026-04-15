class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1 = 0, index2 = nums.size()-1;
        vector<int> res(2);
        while(index1 < index2){
            int sum = nums[index1] + nums[index2];
            if(sum < target) index1++;
            else if(sum > target) index2--;
            else {
                res[0] = index1+1;
                res[1] = index2+1;
                break;
            }
        }
        return res;
    }
};
