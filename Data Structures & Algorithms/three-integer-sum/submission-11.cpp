class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        if(nums.size() <= 2) return vector<vector<int>> (s.begin(), s.end());

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            int j=i+1, k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                
                if(sum == 0){
                    s.insert({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        return vector<vector<int>> (s.begin(), s.end());
    }
};
