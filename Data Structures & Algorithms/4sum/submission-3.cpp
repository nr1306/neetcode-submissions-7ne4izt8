class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n-1; j++){
                int k = j+1, l = n-1;
                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});

                        while(k+1 < n && nums[k] == nums[k+1])
                            k++;
                        
                        while(l-1 >= 0 && nums[l] == nums[l-1])
                            l--;

                        k++;
                        l--;
                    }

                    else if(sum < target) k++;
                    else l--;

                }
                while(j+1 < n && nums[j] == nums[j+1])
                    j++;
            }
            while(i+1 < n && nums[i] == nums[i+1])
                i++;
        }

        return res;
    }
};