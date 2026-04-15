class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++){
            while(i && i<nums.size() && nums[i] == nums[i-1]) i++;

            for(int j=i+1; j<nums.size(); j++){
                int k = j+1, l = nums.size()-1;

                while(k<l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else{
                        res.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                }
            }
        }

        return vector<vector<int>> (res.begin(), res.end());
    }
};