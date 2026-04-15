class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        vector<int> ans(nums.size(),1);
    // For calculating prefix we are multiplying previous prefix with prev element
        int n = nums.size();
        for(int i=1; i<n; i++){
            prefix *= nums[i-1];
            ans[i] *= prefix;
        }

// For calculating suffix we are multiplying next suffix with next element
        int suffix = 1;
        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        
        return ans;
    }
};
