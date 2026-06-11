class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(mp[target-nums[i]]){
                int ind = mp[target-nums[i]];
                if(ind-1 != i){
                    res.push_back(ind-1);
                    res.push_back(i);
                    break;
                }
            }
            mp[nums[i]] = i+1;
        }
        return res;
    }
};
