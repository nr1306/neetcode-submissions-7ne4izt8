class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        int prefix = 1, suffix = 1;

        for(int i=1; i<n; i++){
            prefix *= nums[i-1];
            ans[i] = prefix;
        }

        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix; 
// It simply means that prefix uptill ith place holds the result of mul of elements till i-1 and suffix in same way holds the mul result of elements till i+1
// Here we are just doing for ith element - prefix * suffix (which both exclude ith element)
        }

        return ans;
    }
};
