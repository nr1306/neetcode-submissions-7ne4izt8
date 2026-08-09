class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

    
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n-1; j++){
                int k = j+1, l = n-1;

// We are keeping i and j pointer constant for this iteration            
                while(k < l){
                    long long sum = (long long)nums[i] + 
                    nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        vector<int> temp 
                        {nums[i], nums[j], nums[k], nums[l]};

                        res.push_back(temp);

                    // To avoid duplicate quadraples
                        while(k<l && nums[k] == nums[k+1]) k++;
                        while(k<l && nums[l] == nums[l-1]) l--;

                        k++;
                        l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            // To avoid duplicate quadraples
                while(j<n-1 && nums[j] == nums[j+1]) j++;
            }
            // To avoid duplicate quadraples
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }

        return res;
    }
};