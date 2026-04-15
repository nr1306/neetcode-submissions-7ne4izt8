class Solution {
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int i=0,j=0, maxi = INT_MIN;

        // First window and fidning the max of it
        for(; j<k; j++){
            maxi = max(maxi, nums[j]);
        }
        res.push_back(maxi);
        int prev = nums[i];
        i++;

        for(;j<n; i++,j++){
            if(nums[j] > maxi)
                maxi = nums[j];
            else if(prev == maxi){
                maxi = INT_MIN;
                for(int l=i; l<=j; l++){
                    maxi = max(maxi, nums[l]);
                }
            }
            
            res.push_back(maxi);
            prev = nums[i];
        }
        return res;
    }
};
