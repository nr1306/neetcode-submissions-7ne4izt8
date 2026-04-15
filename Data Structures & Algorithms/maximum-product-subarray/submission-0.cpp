class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // DP solution is not an intuitive solution so Do the following sol in an interview
        // We are gonna keep calculating prefix prod and suffix prod and if 0 occours we'll start again with 1
        // Intuition is that, If there are all +ves, then we'll just get the product
        // If there are even negatives then also
        // But if there are odd +ves then we can skip one negative and check its prefix and suffix subarrays and compute the max
        int ans = INT_MIN;
        int prefix = 1, suffix = 1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            ans = max(ans, max(prefix,suffix));

            if(!prefix) prefix = 1;
            if(!suffix) suffix = 1;
        }
        return ans;
    }
};
