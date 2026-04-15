class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        set<vector<int>> res;

        for(int i=0; i<nums.size()-1; i++){
            
            while(i > 0 && i<nums.size() && nums[i] == nums[i-1])
                i++;
            
            int j = i+1, k = nums.size()-1;
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target) j++;
                else if(sum > target) k--;
                else {
                    res.insert({nums[i],nums[j],nums[k]});
// To avoid same combination again and not get stuck in infinite loop we'll update both the indexes
                    j++;
                    k--;
                }
            }
        }

        return vector<vector<int>> (res.begin(), res.end());
    }
};
