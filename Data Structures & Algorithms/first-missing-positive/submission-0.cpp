class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int count = 1;
        map<int,int> freq;
        for(int x : nums) freq[x]++;
        while(freq[count]) count++;
        return count;
    }
};