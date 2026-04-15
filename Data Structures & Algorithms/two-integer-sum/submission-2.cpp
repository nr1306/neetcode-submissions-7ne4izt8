class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ind;
        vector<int> res(2);
        for(int i=0; i<nums.size(); i++){
            if(ind[target-nums[i]]){
                int ind2 = ind[target-nums[i]]-1;
                if(i!=ind2){
                    res[0] = i < ind2 ? i : ind2;
                    res[1] = i < ind2 ? ind2 : i;
                    break;
                }
            }
            ind[nums[i]] = i+1;
        }
        return res;
    }
};
