class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> freq;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(freq[target-nums[i]] && freq[target-nums[i]] != i+1){
                res.push_back(freq[target-nums[i]]-1);
                res.push_back(i);
                break;
            }
            freq[nums[i]] = i+1;
        }
        return res;
    }
};
