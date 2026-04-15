class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> freq;
        for(int x : nums){
            if(freq[x])
                return true;
            freq[x]++;
        }
        return false;
    }
};
