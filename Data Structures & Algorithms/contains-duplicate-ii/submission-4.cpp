class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> ind;
        ind[nums[0]] = 1;
        for(int i=1; i<nums.size(); i++){
            if(ind.find(nums[i]) != ind.end()){
                if(i+1 - ind[nums[i]] <= k)
                    return true;
            }
            ind[nums[i]] = i+1;
        }
        return false;
    }
};