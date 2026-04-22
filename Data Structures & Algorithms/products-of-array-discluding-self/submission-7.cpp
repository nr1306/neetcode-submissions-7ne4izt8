class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // to get the product except self we can calculate by storing prefix and suffix product res of every element
        int prefix = 1;
        int n = nums.size();
        vector<int> ans(n, 1); // for temporary we are gonna store our prefix results inside the res array

        for(int i=1; i<n; i++){
            prefix *= nums[i-1];
            ans[i] = prefix;
        }
        
        // will calculate suffix along the way , and if we keep multiply with prefix results we stored in ans array
        // we will get our res array ready at the end of the loop
        int suffix = 1;
        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }

        return ans;
    }
};
