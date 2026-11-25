class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;

        vector<int> res(2);
        for(int i=0; i<nums.size(); i++){
            if(mp[target-nums[i]]){
                res[0] = mp[target-nums[i]]-1;
                res[1] = i;
                break;
            }

            mp[nums[i]] = i+1; 
        }

        return res;
    }
};
