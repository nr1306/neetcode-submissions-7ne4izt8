class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> elements;
        for(int i=0; i<nums.size(); i++){
            elements[nums[i]] = i+1;
        }
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(elements[target-nums[i]]){
                int ind = elements[target-nums[i]]-1;
                if(i != ind) {
                    res.push_back(i+1);
                    res.push_back(ind+1);
                    break;
                }
            }
        }
        return res;
    }
};
