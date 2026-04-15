class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, sum); // But we can't neglect -ve sum, so we'll check before we turn it to 0
            if(sum < 0) sum = 0; // taking negative sum forward won't help me in getting max result
        }
        return maxi;
    }
};
