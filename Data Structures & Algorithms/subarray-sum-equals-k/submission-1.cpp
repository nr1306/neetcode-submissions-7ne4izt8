class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        map<int,int> prefixSum;
        int prefix = 0;
        int sum = 0;
        int count = 0;
        prefixSum[0] = 1; // if k is also an element in nums, this initialization will count that
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]; // calculating prefix sum
            int diff = sum-k; 
            count += prefixSum[diff]; // adding the count of sum-k (potential solution)
            prefixSum[sum]++; // adding current prefix sum to hashmap
        }
        return count;
    }
};