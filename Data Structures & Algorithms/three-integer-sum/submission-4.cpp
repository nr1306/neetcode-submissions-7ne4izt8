class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // we are fixing the two pointers then moving the third pointer
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
    // After fixing one pointer with i there is only one task left find 2 indices which is equal to target 
    // Which is normal Two sum problem
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    vector<int> temp {nums[i],nums[j],nums[k]};
                    res.insert(temp);
                    j++; // There might be more pairs with same ith value
                }
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
