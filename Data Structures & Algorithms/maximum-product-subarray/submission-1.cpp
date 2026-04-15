class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];

            ans = max(ans, max(prefix, suffix));

            if(!prefix) prefix = 1; // if its 0 we can't continue with that value
            if(!suffix) suffix = 1; 

        }

        return ans;
    }

};
