class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // marking all negatives to 0 - coz we dont need it
        for(int i=0; i<n; i++){
            if(nums[i] < 0) nums[i] = 0;
        }

        for(int i=0; i<n; i++){
            int val = abs(nums[i]);
            if(val >= 1 && val <= n){
                if(nums[val-1] > 0) nums[val-1] *= -1;
                else if(nums[val-1] == 0) nums[val-1] = -1*n; // will assign the biggest value if its zero , coz we cna't make it -ve
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] >= 0) // Even if there is 0 in any place it means right element was not present
                return i+1;
        }
        return n+1; // if all elements from 0 to n-1 are at their place then n will be the first missing +ve
    }
};