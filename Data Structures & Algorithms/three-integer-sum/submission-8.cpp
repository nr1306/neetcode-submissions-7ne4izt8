class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() == 3){
            vector<vector<int>> res;
            if(nums[0] + nums[1] + nums[2] == 0){
                vector<int> temp;
                res.push_back({nums[0],nums[1],nums[2]});
            }
            return res;
        }

        sort(nums.begin(), nums.end());
        int target = 0;
        vector<vector<int>> res;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > 0) break;
            if(i && nums[i] == nums[i-1]) continue; // This will ensure that computations steps are reduced and no duplicate triplets will be taken

            int left = i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == target){
                    vector<int> temp;
                    res.push_back({nums[i],nums[left],nums[right]});
                   
                    left++;
                    right--;

                    while(left<right && nums[left] == nums[left-1])
                        left++;
                }
                else if(sum < target) left++;
                else right--;
            }
            
        }
        return res;
    }
};
