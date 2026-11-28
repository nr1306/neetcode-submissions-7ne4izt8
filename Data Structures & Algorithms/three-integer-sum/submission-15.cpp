class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<n-1; i++){
            int j=i+1, k=n-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]){
                        j++;
                    }

                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }

                    j++;
                    k--;
                }

                else if(sum < 0) j++;
                else k--;
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }

        return res;
    }
};
