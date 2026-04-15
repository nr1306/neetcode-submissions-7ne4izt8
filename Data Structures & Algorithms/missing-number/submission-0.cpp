class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR = n; // This will store xor of 0-n numbers
        int XOR_nums = 0; // This will store xor of nums elements
        for(int i=0; i<n; i++){
            XOR ^= i;
            XOR_nums ^= nums[i];
        }
        return XOR ^ XOR_nums; // The number remaining will be left rest will be cancelled out
    }
};
