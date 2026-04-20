class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ind;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(ind.find(nums[i]) == ind.end())
                ind[nums[i]] = i;
        }

        vector<int> res;
        for(int i=0; i<n; i++){
            if(ind.find(target-nums[i]) != ind.end()){
                int index = ind[target-nums[i]];
                if(index != i){
                    res.push_back(min(i,index));
                    res.push_back(max(i,index));
                    break;
                }
            }
        }
        return res;
    }
};
