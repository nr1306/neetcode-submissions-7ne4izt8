class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int,int> ind;
        for(int i=0; i<nums.size(); i++){
            ind[nums[i]] = i+1;
        }

        int count = 1, maxi = 1;
        for(int num : nums){
            int ele = num;
            int count = 1;
            while(ind[ele+1]){
                count++;
                ele++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
