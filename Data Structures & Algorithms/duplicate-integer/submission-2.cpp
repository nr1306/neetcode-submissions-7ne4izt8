class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> freq;
        for(int x : nums){
            freq[x]++;
            if(freq[x] > 1) return true;
        }
        return false;
    }
};