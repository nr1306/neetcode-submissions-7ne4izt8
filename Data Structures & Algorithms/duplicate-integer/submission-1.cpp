class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int x : nums){
            int size = s.size();
            s.insert(x);
            if(size == s.size()) return true;
        }
        return false;
    }
};