class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0;
        int count = 0;
        for(int x : nums){
            sum += x;
            int diff = sum - k;
            count += prefixSum[diff];
            prefixSum[sum]++;
        }

        return count;
    }
};