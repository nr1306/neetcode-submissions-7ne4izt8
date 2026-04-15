class Solution {
public:
    int maxProduct(vector<int>& nums) {
    // Here we are gonna calculate prefix mul and suffix mul 
    // Coz it covers all the following cases
        /*
        - If there is odd no of negative ele, then will ignore it and compute mul of rest of ele
        - If there are even negatives, then will take all of them
        - if there are no negatives
        */

        int prefix = 1, suffix = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            prefix *= nums[i];
            suffix *= nums[n-1-i];

            maxi = max(maxi, max(prefix, suffix));

            if(!prefix) prefix = 1;
            if(!suffix) suffix = 1;
        }
        return maxi;
    }
};
