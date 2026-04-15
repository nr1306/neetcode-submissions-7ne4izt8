class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s; // we'll store k elements in it, if there is any duplicate element we'll know that it is repeating within k index
        int l = 0;
        for(int i=0; i<nums.size(); i++){
            int size = s.size();
            s.insert(nums[i]);
            if(size == s.size()) return true;
            if(s.size() > k){
                s.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};