class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> ind;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(ind.find(nums[i]) != ind.end()){
                int index = ind[nums[i]]-1;
                if(abs(i-index) <= k) return true;
            }

            ind[nums[i]] = i+1;
        }

        return false;
    }
};