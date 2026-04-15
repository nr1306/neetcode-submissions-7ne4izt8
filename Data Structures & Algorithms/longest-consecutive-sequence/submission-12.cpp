class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int,int> ind;
        for(int i=0; i<nums.size(); i++){
            ind[nums[i]] = i+1;
        }

        int maxi = 1;
        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            int count = 0;
            while(ind[ele]){
                count++;
                ele++;
            }
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
