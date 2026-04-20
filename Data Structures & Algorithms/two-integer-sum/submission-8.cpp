class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ind;
        int n = nums.size();
        vector<int> res;

        for(int i=0; i<n; i++){
            if(ind[target-nums[i]] && ind[target-nums[i]] != i+1){
                res.push_back(ind[target-nums[i]]-1);
                res.push_back(i);
                break;
            }
            ind[nums[i]] = i+1;
        }
       
        return res;
    }
};
