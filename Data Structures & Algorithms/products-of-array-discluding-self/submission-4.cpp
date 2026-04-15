class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // If the itnerview didn't allow to use the division operation
        // We'll create prefix and suffix array
        // coz to calculate product of array except self we need mul result of elements before that element and mul result of elements after that element

        vector<int> res(nums.size());
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        int n = nums.size();

        prefix[0] = 1;
        suffix[n-1] = 1;

        for(int i=1; i<n; i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for(int i=n-2; i>=0; i--){
            suffix[i] = nums[i+1] * suffix[i+1];
        }

        for(int i=0; i<n; i++){
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
